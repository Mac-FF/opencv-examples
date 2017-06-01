OpenCV examples in Python and C/C++
########################################

Process digital images with computer algorithms at Photogrammetry and Laser-based Vision Systems

.. contents::

.. section-numbering::



Python Examples
=============

Fourier Transform
-----

* This module find the Fourier Transform of images
* Can help to find laser glare, reflects and dots in images
* Can help to remove or smooth reflects
* Files: fouruer_transform.py
* Dirs: sample
* Example:
.. class:: no-web

    .. image:: fourier_transform_example.png
        :alt: alternate text
        :width: 100%
        :align: center

Blur Detection
-----

* This module detect blurry images
* Finds blurry and out off focus images
* Some blurry images can be sharpened by special filter but it needs to implementation and adjust the band pass filter between threshold A > pass > B
* Files: blur_detecion.py
* Dirs: sample

Sharpening
-----

+ This module sharpens images
+ Destiny:

  - Can help to find image edges
  
  - Sharpening blurry images
  
  - Improves performance of photogrammetric processing and  3D spatial data. For example it can be used before  Agisoft PhotoScan processing.
 
+ Contents:

  - Files: sharpening.py
  
  - Dirs: sample
  
+ Example:
.. class:: no-web

    .. image:: sharpening_example.png
        :alt: alternate text
        :width: 100%
        :align: center



C/C++ examples
=============

Image Pyramids
-----

* Program uses the OpenCV functions pyrUp and pyrDown to downsample or upsample given images in dir sample.
* Files: bin/Depug/Image Pyramids, main.cpp
* Dirs: sample
* Example:
.. class:: no-web

    .. image:: name.png
        :alt: alternate text
        :width: 100%
        :align: center



Requirements
=============

Python
-----

* OpenCV v2.4.9
* Python v2.7.6 - 2.7.12
* NumPy v1.11.1

C++
-----
* C++ 14
* OpenCV v2.4.9
* Boost v1.54.0
