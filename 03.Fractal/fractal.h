#ifndef _FRACTAL_H_
#define _FRACTAL_H_

#include "image.h"

typedef enum {
  MANDELBROT,
  SIERPINSKI,
} fractal_t;

/**
 * @brief Draws fractal with specified type, assuming image is clean.
 *
 * @param picture
 * @param type
 */
void fractal(image_p picture, fractal_t type);

#endif // _FRACTAL_H_
