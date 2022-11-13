# Ascii Art Generator

C++ program to convert an image to ascii art.

Currently only works with the `.ppm` image format.

## Quick Start
```
$ ./build.sh
$ ./main
```

Images can be converted to `.ppm` with [ImageMagick](https://imagemagick.org/) using the following command:
```
$ convert input.png -compress none output.ppm
```

## Configuration
File input/output destination can be configured in the Main.cpp file.
Support for picking file as a command-line argument is an intended future feature.

## Demo
Original image: \
![](images/orig/keqing.png) \
[Converted ascii art text](images/output/keqing.txt)
