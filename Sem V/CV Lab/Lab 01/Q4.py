import cv2

image=cv2.imread('image.jpg')

startPoint=(100, 100)
endPoint=(200, 200)
color=(0, 255, 0)
thickness=2

image=cv2.rectangle(image, startPoint, endPoint, color, thickness)

cv2.imshow("Q4", image)

cv2.waitKey(0)