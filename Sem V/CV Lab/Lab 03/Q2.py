import cv2
import numpy as np

def sobel_kernels():
    sobel_x = np.array([[-1, 0, 1],
                        [-2, 0, 2],
                        [-1, 0, 1]], dtype=np.float32)

    sobel_y = np.array([[-1, -2, -1],
                        [0, 0, 0],
                        [1, 2, 1]], dtype=np.float32)

    return sobel_x, sobel_y


def apply_convolution(image, kernel):
    kernel_height, kernel_width = kernel.shape
    pad_height = kernel_height // 2
    pad_width = kernel_width // 2

    padded_image = np.pad(image, ((pad_height, pad_height), (pad_width, pad_width)), mode='constant', constant_values=0)
    gradient = np.zeros_like(image, dtype=np.float32)

    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            region = padded_image[i:i + kernel_height, j:j + kernel_width]
            gradient[i, j] = np.sum(region * kernel)

    return gradient


def compute_gradients(image):
    sobel_x, sobel_y = sobel_kernels()

    grad_x = apply_convolution(image, sobel_x)
    grad_y = apply_convolution(image, sobel_y)

    return grad_x, grad_y


def compute_magnitude(grad_x, grad_y):
    magnitude = np.sqrt(grad_x ** 2 + grad_y ** 2)
    magnitude = np.clip(magnitude, 0, 255)
    return magnitude.astype(np.uint8)


def main():
    image = cv2.imread('image.jpg', 0)

    if image is None:
        raise ValueError("Image not found or unable to read.")

    grad_x, grad_y = compute_gradients(image)

    magnitude = compute_magnitude(grad_x, grad_y)

    cv2.imshow('Original Image', image)
    cv2.imshow('Gradient Magnitude', magnitude)

    cv2.waitKey(0)
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
