#include "seamcarving.h"
#include <stdio.h>
#include <math.h>
#include "c_img.h"

int main() {
    struct rgb_img *im;
    struct rgb_img *grad;
    read_in_img(&im,"3x4.bin");
    printf("%d\n","Hello");
//    for(int y = 0; y<im->height; y++) {
//        for (int x = 0; x < im->width; x++) {
//            double r = (double) get_pixel(im, y, x, 0);
//            double g = (double) get_pixel(im, y, x, 1);
//            double b = (double) get_pixel(im, y, x, 2);
//            printf("%f\n",r);
//            printf("%f\n",g);
//            printf("%f\n",b);
//        }
//    }
        calc_energy(im,  &grad);

//    print_grad(grad);
    return 0;
}
