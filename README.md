# An image auto-cropper

Columns of pixels of minimum energy (those containing the least detail) are iteratively removed to reduce the size of the image while preserving its areas of interest.

## Compilation
You can compile with `gcc` by running the following command:

```
$ gcc -o auto_crop src/main.c src/energy.c src/image_operations.c src/pixel_operations.c -lm
```

## Usage
Images must be in `.png` format and grayscale. Here's the command for the auto-cropper:
* `./auto_crop [args]` auto-crops the provided image. Arguments:
  * `input` is the path to the `.png` image to be cropped.
  * `output` is the path to the cropped `.png` image.
  * `columns` is a `int` value equal to the number of colums to be removed.
  
## Example
```
$ ./auto_crop castle.png castle_cropped.png 400
```

![initial image](https://i.imgur.com/ilT20K7.png) ![reduced image](https://i.imgur.com/fd9SSz2.png) \
`60%` of the columns have been removed.
