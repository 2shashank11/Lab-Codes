import cv2

image = cv2.imread('image.jpg')

resizedImage=cv2.resize(image, (500, 500))

cv2.imshow("Q5", resizedImage)

cv2.waitKey(0)