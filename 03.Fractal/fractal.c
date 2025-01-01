#include <assert.h>
#include <complex.h>

#include "image.h"
#include "fractal.h"

void mandelbrot(image_p picture) {
  int max_iter = 1000;
  double scale = 2.0 / picture->width;
  for (pixel_coord y = 0; y < picture->height; y++) {
    for (pixel_coord x = 0; x < picture->width; x++) {
      double real = (x - picture->width / 2.0) * scale;
      double imag = (y - picture->height / 2.0) * scale;
      int iter;
      complex double c = real + imag * I;
      complex double z = 0;
      for (iter = 0; iter < max_iter && cabs(z) <= 2.0; iter++) {
        z = z * z + c;
      }
      set_pixel(picture, x, y, iter % 256);
    }
  }
}

void sierpinski(image_p picture, int x, int y, int size) {
  if (size < 1) return;
  int new_size = size / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) {
        for (int new_y = y + new_size; new_y < y + 2 * new_size; new_y++) {
          for (int new_x = x + new_size; new_x < x + 2 * new_size; new_x++) {
            set_pixel(picture, new_x, new_y, 0);
          }
        }
      } else {
        sierpinski(picture, x + i * new_size, y + j * new_size, new_size);
      }
    }
  }
}

void fractal(image_p picture, fractal_t type) {
  switch (type) {
    case MANDELBROT:
      mandelbrot(picture);
      break;
    case SIERPINSKI:
      sierpinski(picture, 0, 0, picture->width);
      break;
  }
}
