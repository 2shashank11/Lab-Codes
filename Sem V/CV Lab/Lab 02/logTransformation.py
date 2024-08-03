import cv2
import numpy as np

img = cv2.imread('image.jpg', 0)

c = 255 / (np.log(1 + np.max(img)))
log_transformed = c * np.log(1 + img)

log_transformed = np.array(log_transformed, dtype=np.uint8)

cv2.imshow('log_transformed.jpg', log_transformed)
cv2.waitKey(0)
