#!/usr/bin/python
"""**fourier_transform.py v1.0, Python v2.7.6 - 2.7.12, 2017, kmlajceps@gmail.com**

- This module find the Fourier Transform of images in dir 'sample' using::

    OpenCV v2.4.9
    NumPy v1.11.1"""
import cv2
import numpy as np
import glob
import os
import time


def transform(image):
    """- returns the image after FFT
    **Drawbacks**:
    http://docs.opencv.org/3.1.0/de/dbc/tutorial_py_fourier_transform.html"""
    window_size = 30
    fft = np.fft.fft2(image)
    shift = np.fft.fftshift(fft)
    rows, cols = image.shape
    row, col = rows / 2, cols / 2
    shift[row - window_size:row + window_size, col - window_size:col + window_size] = 0
    inverse_shift = np.fft.ifftshift(shift)
    image = np.fft.ifft2(inverse_shift)
    image = np.abs(image)
    return image


def main():
    print "Find Fourier Transform of jpg images in dir 'sample'"
    paths = glob.glob("sample/*.jpg")
    for path in paths:
        start = time.time()
        name = os.path.basename(path)[:-4]
        image = cv2.imread(path, 0)
        img_back = transform(image)
        cv2.imwrite(name + '_fft.jpg', img_back)
        print path, " time: ", time.time() - start
    print "End"

if __name__ == '__main__':
    main()
