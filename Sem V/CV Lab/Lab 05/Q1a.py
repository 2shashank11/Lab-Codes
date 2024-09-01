import cv2
import numpy as np

def harris_corner_detection(image_path):
    # Load the image in grayscale
    img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    img = np.float32(img)

    # Step 1: Compute gradients
    sobel_x = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=3)
    sobel_y = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize=3)

    # Step 2: Compute products of gradients
    I_x2 = sobel_x**2
    I_y2 = sobel_y**2
    I_xy = sobel_x * sobel_y

    # Step 3: Compute the Harris matrix and response function
    height, width = img.shape
    R = np.zeros((height, width))

    k = 0.04
    for y in range(1, height-1):
        for x in range(1, width-1):
            S_x2 = np.sum(I_x2[y-1:y+2, x-1:x+2])
            S_y2 = np.sum(I_y2[y-1:y+2, x-1:x+2])
            S_xy = np.sum(I_xy[y-1:y+2, x-1:x+2])

            det_M = (S_x2 * S_y2) - (S_xy**2)
            trace_M = S_x2 + S_y2
            R[y, x] = det_M - k * (trace_M**2)

    # Step 4: Threshold and Non-maximum suppression
    threshold = 0.01 * R.max()
    corners = np.zeros_like(R)
    corners[R > threshold] = 255

    # Display results
    img_color = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
    img_color[corners > 0] = [0, 0, 255]  # Mark corners in red
    cv2.imshow('Harris Corners', img_color)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# Example usage
harris_corner_detection('image.png')
