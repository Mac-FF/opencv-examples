
import cv2
import numpy as np
import glob
import argparse


class Filter:
    filter_size = 5
    c = 3 + 2 * filter_size
    kernel = np.zeros((c, c), np.float32)
    kernel[c / 2, c / 2] = 2.0
    box_filter = np.ones( (c, c), np.float32) / (c * c)
    kernel = kernel - box_filter

def focus(image):

    return cv2.filter2D(image,-1, kernel)


def main():
    print kernel
    print np.shape(kernel)


if __name__ == '__main__':
    main()