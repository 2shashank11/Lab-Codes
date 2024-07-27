import cv2

#read
img = cv2.imread('image.jpg')

#display
cv2.imshow('Q1', img)
cv2.waitKey(5000)

#write
cv2.imwrite('Q1Output.png', img)