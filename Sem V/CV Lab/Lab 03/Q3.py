import cv2
import numpy as np


def box_filter_kernel(size):
    kernel = np.ones((size, size), dtype=np.float32) / (size * size)
    return kernel


def gaussian_filter_kernel(size, sigma):
    kernel_radius = size // 2
    x = np.linspace(-kernel_radius, kernel_radius, size)
    y = np.linspace(-kernel_radius, kernel_radius, size)
    x, y = np.meshgrid(x, y)

    kernel = np.exp(-(x ** 2 + y ** 2) / (2 * sigma ** 2))
    kernel = kernel / np.sum(kernel)
    return kernel


def apply_convolution(image, kernel):
    kernel_height, kernel_width = kernel.shape
    pad_height = kernel_height // 2
    pad_width = kernel_width // 2

    padded_image = np.pad(image, ((pad_height, pad_height), (pad_width, pad_width)), mode='constant', constant_values=0)
    output_image = np.zeros_like(image, dtype=np.float32)

    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            region = padded_image[i:i + kernel_height, j:j + kernel_width]
            output_image[i, j] = np.sum(region * kernel)

    return output_image


def main():
    image = cv2.imread('image.jpg', 0)

    if image is None:
        raise ValueError("Image not found or unable to read.")

    box_kernel = box_filter_kernel(size=5)
    box_filtered_image = apply_convolution(image, box_kernel)

    gaussian_kernel = gaussian_filter_kernel(size=5, sigma=1.0)
    gaussian_filtered_image = apply_convolution(image, gaussian_kernel)

    box_filtered_image = np.clip(box_filtered_image, 0, 255).astype(np.uint8)
    gaussian_filtered_image = np.clip(gaussian_filtered_image, 0, 255).astype(np.uint8)

    # Display the images
    cv2.imshow('Original Image', image)
    cv2.imshow('Box Filtered Image', box_filtered_image)
    cv2.imshow('Gaussian Filtered Image', gaussian_filtered_image)

    cv2.waitKey(0)
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
