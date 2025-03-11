#include <stdio.h>
#include <string.h>
#include <cuda_runtime.h>

__device__ bool wordMatch(const char* sentence, int index, const char* word) {
    int i = 0;
    while (word[i] != '\0' && sentence[index + i] != '\0') {
        if (sentence[index + i] != word[i]) {
            return false;
        }
        i++;
    }
    return word[i] == '\0' && (sentence[index + i] == ' ' || sentence[index + i] == '\0');
}

__global__ void countWordOccurrences(const char* sentence, const char* word, int sentenceLength, int wordLength, int* count) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;

    if (idx < sentenceLength - wordLength + 1) {
        if (wordMatch(sentence, idx, word)) {
            atomicAdd(count, 1);
        }
    }
}

int main() {

    char sentence[1024];
    char word[100];

    printf("Enter sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0; 
    printf("Enter word: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = 0;

    int sentenceLength = strlen(sentence);
    int wordLength = strlen(word);

    char* d_sentence;
    char* d_word;
    int* d_count;
    int count = 0;

    cudaMalloc(&d_sentence, sentenceLength + 1);
    cudaMalloc(&d_word, wordLength + 1);
    cudaMalloc(&d_count, sizeof(int));

    cudaMemcpy(d_sentence, sentence, sentenceLength + 1, cudaMemcpyHostToDevice);
    cudaMemcpy(d_word, word, wordLength + 1, cudaMemcpyHostToDevice);
    cudaMemcpy(d_count, &count, sizeof(int), cudaMemcpyHostToDevice);

    int blockSize = 256;
    int gridSize = (sentenceLength + blockSize - 1) / blockSize;

    countWordOccurrences<<<gridSize, blockSize>>>(d_sentence, d_word, sentenceLength, wordLength, d_count);

    cudaMemcpy(&count, d_count, sizeof(int), cudaMemcpyDeviceToHost);

    printf("The word %s appears %d times in the sentence\n", word, count);

    cudaFree(d_sentence);
    cudaFree(d_word);
    cudaFree(d_count);

    return 0;
}


// Enter sentence: hello world
// Enter word: hello
// The word hello appears 1 times in the sentence