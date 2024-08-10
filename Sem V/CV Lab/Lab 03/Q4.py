import cv2
import numpy as np

def sobelFilter():
    sobelV=np.array([[-1, 0, 1],
                     [-2, 0, 2],
                     [-1, 0, 1]
                     ], dtype=np.float32)
    sobelH=np.array([[-1, -2, -1],
                     [0, 0, 0],
                     [1, 2, 1]
                     ], dtype=np.float32)
    return sobelH, sobelV

def edgeDetection(image):

    sobelH, sobelV = sobelFilter()
    kernelHalf=sobelH.shape[0]//2

    gradX=np.zeros_like(image, dtype=np.float32)
    gradY=np.zeros_like(image, dtype=np.float32)

    for p in range(kernelHalf, image.shape[0]-kernelHalf):
        for q in range(kernelHalf, image.shape[1]-kernelHalf):
            region=image[p-kernelHalf : p+kernelHalf+1, q-kernelHalf : q+kernelHalf+1]

            gradX[p, q]=np.sum(region * sobelH)
            gradY[p, q]=np.sum(region * sobelV)

    magnitude = np.sqrt(gradX**2 + gradY**2)
    magnitude = np.clip(magnitude, 0, 255)

    return magnitude.astype(np.uint8)

def main():
    image = cv2.imread('image.jpg', 0)
    cv2.imshow('Original Image', image)

    image=image.astype(np.float32)
    edge=edgeDetection(image)

    cv2.imshow('Edges', edge)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

if(__name__=="__main__"):
    main()