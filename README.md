# An image auto-cropper

Columns of pixels of minimum energy (those containing the least detail) are iteratively removed to reduce the size of the image while preserving its areas of interest.

# Compilation
You can compile with GCC by running the following command: \
```$ gcc -o auto_crop main.c energy.c image_operations.c pixel_operations.c -lm```

# Execution
Images must be in PNG format and grayscale.

Arguments: input path, output path, desired number of removed colums. \
Example: ```$ ./auto_crop castle.png castle_cropped.png 400```

# Example
![](https://i.imgur.com/ilT20K7.png) ![](https://i.imgur.com/fd9SSz2.png) \
60% of the columns have been removed.
