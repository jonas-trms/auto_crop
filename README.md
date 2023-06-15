# An image auto-cropper

Columns of pixels of minimum energy (those containing the least detail) are iteratively removed to reduce the size of the image while preserving its areas of interest.

## Compilation
You can compile with GCC by running the following command:

```
$ gcc -o auto_crop main.c energy.c image_operations.c pixel_operations.c -lm
```

## Usage
Images must be in `.png` format and grayscale. Here's the command for the auto-cropper:
* `./main [args]` auto-crops the provided image. Arguments:
  * `input` is the path to the `.png` image to be cropped.
  * `output` is the path to the cropped `.png` image.
  * `columns` is a `int` value equal to the number of colums to be removed.
  
## Example
```
$ ./auto_crop castle.png castle_cropped.png 400
```

![initial image](https://i.imgur.com/ilT20K7.png) ![reduced image](https://i.imgur.com/fd9SSz2.png) \
`60%` of the columns have been removed.
