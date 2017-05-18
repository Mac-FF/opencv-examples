#!/usr/bin/python
"""**blur_detection.py v1.0, Python v2.7.6 - 2.7.12, 2017, kmlajceps@gmail.com**

- This module detect blurry images in dir 'sample' using::

    OpenCV v2.4.9"""
import cv2
import os
import glob
import time


def detect(image):
    threshold = 400
    variance = cv2.Laplacian(image, cv2.CV_64F).var()
    if variance < threshold:
        return True
    return False


def main():
    print "Detect blurry images in dir 'sample'"
    paths = glob.glob("sample/*.jpg")
    for path in paths:
        start = time.time()
        image = cv2.imread(path, 0)
        name = os.path.basename(path)[:-4]
        print name, " - ", detect(image), ", time: ", time.time() - start
    print "End"

if __name__ == '__main__':
    main()
