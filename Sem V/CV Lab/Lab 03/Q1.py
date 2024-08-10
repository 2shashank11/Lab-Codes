import cv2
import numpy as np

image = cv2.imread('image.jpg', 0)
image = image.astype(np.float32)

filterSize=5
halfFilter=filterSize//2

blurred = np.zeros_like(image)

for p in range(halfFilter, image.shape[0]-halfFilter):
    for q in range(halfFilter, image.shape[1]-halfFilter):
        region = image[p-halfFilter : p+halfFilter+1, q-halfFilter : q+halfFilter+1]
        avg = np.mean(region, axis=(0, 1))
        blurred[p, q] = avg

scale=2
mask=image-blurred
output=image+scale*mask
output = np.clip(output, 0, 255).astype(np.uint8)
image = image.astype(np.uint8)
blurred = blurred.astype(np.uint8)

cv2.imshow('Original', image)
cv2.imshow('Blurred', blurred)
cv2.imshow('Unsharp Masking', output)
cv2.waitKey(0)
cv2.destroyAllWindows()