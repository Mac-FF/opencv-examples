#!/usr/bin/python
"""**sharpening.py v1.0, Python v2.7.6 - 2.7.12, 2017, kmlajceps@gmail.com**

- This module sharpens of images in dir 'sample' using::

    OpenCV v2.4.9
    NumPy v1.11.1"""
import cv2
import numpy as np
import glob
import os
import time


class Kernel:
    def __init__(self):
        self.size = 3
        self.kernel = 0
        self.calculate()

    def calculate(self):
        c = 3 + 2 * self.size
        kernel = np.zeros((c, c), np.float32)
        kernel[c / 2, c / 2] = 2.0
        box_filter = np.ones((c, c), np.float32) / (c * c)
        kernel = kernel - box_filter
        self.kernel = kernel
        return kernel


def main():
    print "Sharpen the images in dir 'sample'"
    kernel = Kernel()

    paths = glob.glob("sample/*.jpg")
    for path in paths:
        start = time.time()
        name = os.path.basename(path)[:-4]
        image = cv2.imread(path)
        img_back = cv2.filter2D(image, -1, kernel.kernel)
        cv2.imwrite(name + '_sharpened.jpg', img_back)
        print path, "time: ", time.time() - start
    print "End"

if __name__ == '__main__':
    main()
