import cv2

img = cv2.imread('image.jpg')
blue, green, red = (img[100, 100])
print(f"R:{red} G:{green} B:{blue}")