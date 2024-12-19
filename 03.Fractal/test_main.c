#include <stdio.h>

#include "image.h"
#include "fractal.h"
#include "./utest.h/utest.h"

struct ImageTestFixture {
    image_p image;
};

UTEST_F_SETUP(ImageTestFixture) {
    utest_fixture->image = create_image(64, 64);
    ASSERT_NE((void *) utest_fixture->image, NULL);
}

UTEST_F_TEARDOWN(ImageTestFixture) {
    free_image(utest_fixture->image);
}

UTEST_F(ImageTestFixture, ImageSetGetPixel) {
    set_pixel(utest_fixture->image, 10, 10, 10);
    ASSERT_EQ(10, get_pixel(utest_fixture->image, 10, 10));
}

UTEST_F(ImageTestFixture, ImageFillWrite) {
    fill_white(utest_fixture->image);
    for (pixel_coord y = 0; y < utest_fixture->image->height; y++) {
        for (pixel_coord x = 0; x < utest_fixture->image->width; x++) {
            ASSERT_EQ(0xff, get_pixel(utest_fixture->image, x, y));
        }
    }
}

UTEST_F(ImageTestFixture, FractalMandelbrot) {
    fractal(utest_fixture->image, MANDELBROT);
    ASSERT_NE((void *) utest_fixture->image, NULL);
}

UTEST_F(ImageTestFixture, FractalSierpinski) {
    fractal(utest_fixture->image, SIERPINSKI);
    ASSERT_NE((void *) utest_fixture->image, NULL);
}

UTEST_MAIN();
