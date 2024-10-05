import cv2
import numpy as np

# Load images
img1 = cv2.imread('img_1.png', cv2.IMREAD_GRAYSCALE)
img2 = cv2.imread('img_4.png', cv2.IMREAD_GRAYSCALE)

# Initialize the SIFT detector
sift = cv2.SIFT_create()

# Find the keypoints and descriptors with SIFT
keypoints1, descriptors1 = sift.detectAndCompute(img1, None)
keypoints2, descriptors2 = sift.detectAndCompute(img2, None)

# Create a BFMatcher object
bf = cv2.BFMatcher()

# Match descriptors using KNN
matches = bf.knnMatch(descriptors1, descriptors2, k=2)

# Apply the ratio test
ratio_thresh = 0.7
good_matches = []

for m, n in matches:
    if m.distance < ratio_thresh * n.distance:
        good_matches.append(m)

# Draw the matches
img_matches = cv2.drawMatches(img1, keypoints1, img2, keypoints2, good_matches, None, flags=cv2.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)

# Display the matched images
cv2.imshow('Good Matches', img_matches)
cv2.waitKey(0)
cv2.destroyAllWindows()
