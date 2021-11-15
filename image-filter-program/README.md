# Image Filter Project

The starting point for this program was everything but an essentialy void helpers.c file. See my contributions there.

*This project for CS50 is meant to be compiled with clang.*

To compile:

```bash
make filter
```

## Included Filters

### Reflection

Pre-process            |  Post-process
:-------------------------:|:-------------------------:
![Image of courtyard, pre-processed.](https://github.com/pseamusmcdonald/cs50-programs/blob/main/projectMedia/courtyard.bmp) | ![Image of reflected courtyard, post-processed.](https://github.com/pseamusmcdonald/cs50-programs/blob/main/projectMedia/reflected-courtyard.bmp)

To run the reflection filter on your image, run:

```bash
./filter -r ./images/courtyard.bmp ./images/reflected-courtyard.bmp
```

### Blur

Pre-process            |  Post-process
:-------------------------:|:-------------------------:
![Image of courtyard, pre-processed.](https://github.com/pseamusmcdonald/cs50-programs/blob/main/projectMedia/courtyard.bmp) | ![Image of blurred courtyard, post-processed.](https://github.com/pseamusmcdonald/cs50-programs/blob/main/projectMedia/blurred-courtyard.bmp)

To run the blur filter on your image, run:

```bash
./filter -b ./images/courtyard.bmp ./images/blurred-courtyard.bmp
```

### Greyscale

Pre-process            |  Post-process
:-------------------------:|:-------------------------:
![Image of courtyard, pre-processed.](https://github.com/pseamusmcdonald/cs50-programs/blob/main/projectMedia/courtyard.bmp) | ![Image of greyscale courtyard, post-processed.](https://github.com/pseamusmcdonald/cs50-programs/blob/main/projectMedia/greyscale-courtyard.bmp)

To run the greyscale filter on your image, run:

```bash
./filter -g ./images/courtyard.bmp ./images/greyscale-courtyard.bmp
```

### Edges

Pre-process            |  Post-process
:-------------------------:|:-------------------------:
![Image of courtyard, pre-processed.](https://github.com/pseamusmcdonald/cs50-programs/blob/main/projectMedia/courtyard.bmp) | ![Image of edge extracted courtyard, post-processed.](https://github.com/pseamusmcdonald/cs50-programs/blob/main/projectMedia/edged-courtyard.bmp)




To run the edges filter on your image, run:

```bash
./filter -r ./images/courtyard.bmp ./images/edged-courtyard.bmp
```