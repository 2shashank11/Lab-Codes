import cv2
import numpy as np
import os
import glob

# Defining the dimensions of checkerboard
CHECKERBOARD = (12, 12)

# Termination criteria for corner sub-pixel refinement
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 50, 0.0001)

# Creating lists to store 3D points and 2D points for each checkerboard image
objpoints = []  # 3D point in real world space
imgpoints = []  # 2D points in image plane

# Defining the world coordinates for 3D points
objp = np.zeros((CHECKERBOARD[0] * CHECKERBOARD[1], 3), np.float32)
objp[:, :2] = np.mgrid[0:CHECKERBOARD[0], 0:CHECKERBOARD[1]].T.reshape(-1, 2)

# Extracting path of individual images stored in a given directory
images = glob.glob('./calib_images/*.tif')

for fname in images:
    img = cv2.imread(fname)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Find the chessboard corners
    ret, corners = cv2.findChessboardCorners(gray, CHECKERBOARD,
        cv2.CALIB_CB_ADAPTIVE_THRESH + cv2.CALIB_CB_FAST_CHECK + cv2.CALIB_CB_NORMALIZE_IMAGE)

    # If desired number of corners are found, then append object points and image points
    if ret:
        objpoints.append(objp)
        corners2 = cv2.cornerSubPix(gray, corners, (11, 11), (-1, -1), criteria)
        imgpoints.append(corners2)

        # Draw and display the corners
        img = cv2.drawChessboardCorners(img, CHECKERBOARD, corners2, ret)
        cv2.imshow('img', img)
        cv2.waitKey(0)

cv2.destroyAllWindows()

# Performing camera calibration
ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, gray.shape[::-1], None, None)

# Output the intrinsic parameters
print("Camera matrix : \n", mtx)
print("Distortion coefficients : \n", dist)

# Output the extrinsic parameters
for i in range(len(rvecs)):
    print(f"Rotation vector for image {i+1} : \n", rvecs[i])
    print(f"Translation vector for image {i+1} : \n", tvecs[i])
