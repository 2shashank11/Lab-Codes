import cv2

image=cv2.imread('image.jpg')

rotatedImage=cv2.rotate(image, cv2.ROTATE_90_COUNTERCLOCKWISE)

cv2.imshow("Q6", rotatedImage)
cv2.waitKey(0)