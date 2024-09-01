import cv2
import numpy as np

def fast_corner_detection(image_path, threshold=20):
    # Load the image in grayscale
    img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    if img is None:
        print("Error loading image.")
        return

    img = np.float32(img)
    height, width = img.shape

    # Define the circular pattern around a candidate pixel
    pattern = [(0, 3), (1, 3), (2, 2), (3, 1), (3, 0), (3, -1), (2, -2), (1, -3), (0, -3), (-1, -3), (-2, -2), (-3, -1), (-3, 0), (-3, 1), (-2, 2), (-1, 3)]
    radius = 3

    def is_corner(x, y):
        if x < radius or x >= width - radius or y < radius or y >= height - radius:
            return False

        center_intensity = img[y, x]
        surrounding_intensities = [img[y + dy, x + dx] for dx, dy in pattern]

        count_above = sum(i > center_intensity + threshold for i in surrounding_intensities)
        count_below = sum(i < center_intensity - threshold for i in surrounding_intensities)

        return count_above >= 12 or count_below >= 12

    # Detect corners
    corners = np.zeros((height, width), dtype=np.uint8)
    for y in range(height):
        for x in range(width):
            if is_corner(x, y):
                corners[y, x] = 255

    # Display the results
    img_color = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
    img_color[corners > 0] = [0, 0, 255]  # Mark corners in red

    cv2.imshow('FAST Corners', img_color)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# Example usage
fast_corner_detection('image.png')
