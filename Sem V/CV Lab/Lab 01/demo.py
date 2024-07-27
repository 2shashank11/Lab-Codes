import cv2

#read the image as a grayscale image
img = cv2.imread("image.jpg", 0) #0 for read as gray

#display the image
cv2.imshow("First CV program", img)

# await for a key press
cv2.waitKey(0)
