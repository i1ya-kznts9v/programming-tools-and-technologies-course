#include <stdio.h>

#include "image.h"
#include "fractal.h"

int main()
{
  image_p image = create_image(512, 512);

  fill_white(image);
  fractal(image, MANDELBROT);
  save_pgm(image, "mandelbrot.pgm");

  fill_white(image);
  fractal(image, SIERPINSKI);
  save_pgm(image, "sierpinski.pgm");

  return 0;
}
