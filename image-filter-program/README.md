# Image Filter Program

This program does various image filtering in C and was done along wih my self-study of CS50X. The starting point for this program was everything but an essentially void helpers.c file. See my contributions there.

**Note** You may only use uncompressed, 24bit BMP images! Use [this converter](https://online-converting.com/image/convert2bmp/) to utilize other image files.

To compile:

```bash
$ make filter
```

*This program is meant to be compiled with clang.*

## Included Filters

### Reflection

Pre-process            |  Post-process
:-------------------------:|:-------------------------:
![Image of courtyard, pre-processed.](https://github.com/pseamusmcdonald/project-media/blob/main/courtyard.bmp) | ![Image of reflected courtyard, post-processed.](https://github.com/pseamusmcdonald/project-media/blob/main/reflected-courtyard.bmp)

To run the reflection filter on your image, run:

```bash
$ ./filter -r ./images/courtyard.bmp ./images/reflected-courtyard.bmp # Output location
```

### Greyscale

Pre-process            |  Post-process
:-------------------------:|:-------------------------:
![Image of courtyard, pre-processed.](https://github.com/pseamusmcdonald/project-media/blob/main/courtyard.bmp) | ![Image of greyscale courtyard, post-processed.](https://github.com/pseamusmcdonald/project-media/blob/main/greyscale-courtyard.bmp)

To run the greyscale filter on your image, run:

```bash
$ ./filter -g ./images/courtyard.bmp ./images/greyscale-courtyard.bmp # Output location
```


### Blur

Pre-process            |  Post-process
:-------------------------:|:-------------------------:
![Image of courtyard, pre-processed.](https://github.com/pseamusmcdonald/project-media/blob/main/courtyard.bmp) | ![Image of blurred courtyard, post-processed.](https://github.com/pseamusmcdonald/project-media/blob/main/blurred-courtyard.bmp)

To run the blur filter on your image, run:

```bash
$ ./filter -b ./images/courtyard.bmp ./images/blurred-courtyard.bmp # Output location
```

### Edges

Implemented using a Sobel operator, similar algorithms are used for many basic computer vision edge detection.

Pre-process            |  Post-process
:-------------------------:|:-------------------------:
![Image of courtyard, pre-processed.](https://github.com/pseamusmcdonald/project-media/blob/main/barb.bmp) | ![Image of edge extracted courtyard, post-processed.](https://github.com/pseamusmcdonald/project-media/blob/main/barb-edged.bmp)


To run the edges filter on your image, run:

```bash
$ ./filter -r ./images/courtyard.bmp ./images/edged-courtyard.bmp # Output location
```
