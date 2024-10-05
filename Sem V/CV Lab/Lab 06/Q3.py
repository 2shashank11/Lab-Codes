import cv2
import numpy as np

def estimate_homography(img1, img2):
    # Step 1: Create SIFT detector
    sift = cv2.SIFT_create()

    # Step 2: Detect keypoints and compute descriptors
    keypoints1, descriptors1 = sift.detectAndCompute(img1, None)
    keypoints2, descriptors2 = sift.detectAndCompute(img2, None)

    # Step 3: Match features using KNN
    # Use KNN to find the best matches
    bf = cv2.BFMatcher()
    matches = bf.knnMatch(descriptors1, descriptors2, k=2)

    # Step 4: Apply Lowe's ratio test
    good_matches = []
    for m, n in matches:
        if m.distance < 0.75 * n.distance:
            good_matches.append(m)

    # Step 5: Extract the matched keypoints' coordinates
    if len(good_matches) >= 4:  # We need at least 4 matches to estimate homography
        src_pts = np.float32([keypoints1[m.queryIdx].pt for m in good_matches]).reshape(-1, 2)
        dst_pts = np.float32([keypoints2[m.trainIdx].pt for m in good_matches]).reshape(-1, 2)

        # Step 6: Estimate homography using RANSAC
        H, mask = cv2.findHomography(src_pts, dst_pts, cv2.RANSAC)

        # Mask can be used to visualize inliers and outliers
        inliers = mask.ravel().tolist()

        return H, inliers
    else:
        print("Not enough good matches found.")
        return None, None

# Example usage
img1 = cv2.imread('img_1.png', cv2.IMREAD_GRAYSCALE)
img2 = cv2.imread('img_4.png', cv2.IMREAD_GRAYSCALE)

H, inliers = estimate_homography(img1, img2)

if H is not None:
    print("Homography matrix:")
    print(H)

    # Optionally: warp one image to the perspective of the other
    height, width = img2.shape
    img1_warped = cv2.warpPerspective(img1, H, (width, height))

    # Display or save the warped image
    cv2.imshow('Warped Image', img1_warped)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
