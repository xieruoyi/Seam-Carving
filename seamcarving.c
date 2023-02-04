#include "seamcarving.h"
#include <stdio.h>
#include <math.h>

void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    create_img(&im,im->height,im->width);
    for(int i = 0; i<im->height;i++){
        for(int j = 0; j < im->width; j++){
            if( i == 0 && j == im->width -1){
                double r1;
                double g1;
                double b1;
                r1 =get_pixel(im,i+1,j,0);
                g1 =get_pixel(im,i+1,j,1);
                b1 =get_pixel(im,i+1,j,2);
//                printf("%f\n",r1);
//                printf("%f\n",g1);
//                printf("%f\n",b1);
                double r2;
                double g2;
                double b2;
                r2 =get_pixel(im,im->height-1,j,0);
                g2 =get_pixel(im,im->height-1,j,1);
                b2 =get_pixel(im,im->height-1,j,2);
                double r3;
                double g3;
                double b3;
                r3 =get_pixel(im,i,j-1,0);
                g3 =get_pixel(im,i,j-1,1);
                b3 =get_pixel(im,i,j-1,2);
                double r4;
                double g4;
                double b4;
                r4 =get_pixel(im,i,0,0);
                g4 =get_pixel(im,i,0,1);
                b4 =get_pixel(im,i,0,2);
                double res = sqrt(pow((r1 - r2),2) + pow((g1 - g2),2) + pow((b1 - b2),2) + pow((r3 - r4),2) + pow((g3 - g4),2) + pow((b3 - b4),2));
                res = res / 10;
//                printf("%f\n",res);
                uint8_t b = res;
//                printf("%hhu\n",b);
            }
            if( i != 0 && i !=im->height -1 && j == im->width-1){
                double r1;
                double g1;
                double b1;
                r1 =get_pixel(im,i+1,j,0);
                g1 =get_pixel(im,i+1,j,1);
                b1 =get_pixel(im,i+1,j,2);
                double r2;
                double g2;
                double b2;
                r2 =get_pixel(im,i-1,j,0);
                g2 =get_pixel(im,i-1,j,1);
                b2 =get_pixel(im,i-1,j,2);
                double r3;
                double g3;
                double b3;
                r3 =get_pixel(im,i,j-1,0);
                g3 =get_pixel(im,i,j-1,1);
                b3 =get_pixel(im,i,j-1,2);
                double r4;
                double g4;
                double b4;
                r4 =get_pixel(im,i,0,0);
                g4 =get_pixel(im,i,0,1);
                b4 =get_pixel(im,i,0,2);
                double res = sqrt(pow((r1 - r2),2) + pow((g1 - g2),2) + pow((b1 - b2),2) + pow((r3 - r4),2) + pow((g3 - g4),2) + pow((b3 - b4),2));
                res = res / 10;
                uint8_t b = res;
//                printf("%f\n",res);
//                printf("%hhu\n",b);
            }
            if( j == 0 && i == im->height-1){
                double r1;
                double g1;
                double b1;
                r1 =get_pixel(im,i-1,j,0);
                g1 =get_pixel(im,i-1,j,1);
                b1 =get_pixel(im,i-1,j,2);
                double r2;
                double g2;
                double b2;
                r2 =get_pixel(im,0,j,0);
                g2 =get_pixel(im,0,j,1);
                b2 =get_pixel(im,0,j,2);
                double r3;
                double g3;
                double b3;
                r3 =get_pixel(im,i,j+1,0);
                g3 =get_pixel(im,i,j+1,1);
                b3 =get_pixel(im,i,j+1,2);
                double r4;
                double g4;
                double b4;
                r4 =get_pixel(im,i,im->width-1,0);
                g4 =get_pixel(im,i,im->width-1,1);
                b4 =get_pixel(im,i,im->width-1,2);
                double res = sqrt(pow((r1 - r2),2) + pow((g1 - g2),2) + pow((b1 - b2),2) + pow((r3 - r4),2) + pow((g3 - g4),2) + pow((b3 - b4),2));
                res = res / 10;
                uint8_t b = res;
//                printf("%f\n",res);
//                printf("%hhu\n",b);
            }

            if( j != 0 && j != im->width -1 && i == im->height-1){
                double r1;
                double g1;
                double b1;
                r1 =(double)get_pixel(im,0,j,0);
                g1 =(double)get_pixel(im,0,j,1);
                b1 =(double)get_pixel(im,0,j,2);
                double r2;
                double g2;
                double b2;
                r2 =(double)get_pixel(im,i-1,j,0);
                g2 =(double)get_pixel(im,i-1,j,1);
                b2 =(double)get_pixel(im,i-1,j,2);
                double r3;
                double g3;
                double b3;
                r3 =(double)get_pixel(im,i,j-1,0);
                g3 =(double)get_pixel(im,i,j-1,1);
                b3 =(double)get_pixel(im,i,j-1,2);
                double r4;
                double g4;
                double b4;
                r4 =(double)get_pixel(im,i,j+1,0);
                g4 =(double)get_pixel(im,i,j+1,1);
                b4 =(double)get_pixel(im,i,j+1,2);
                double res = sqrt(pow((r1 - r2),2) + pow((g1 - g2),2) + pow((b1 - b2),2) + pow((r3 - r4),2) + pow((g3 - g4),2) + pow((b3 - b4),2));
                res = res / 10;
                uint8_t b = res;
                printf("%f\n",res);
                printf("%hhu\n",b);
            }

            if(i == 0 && j == 0){
                double r1;
                double g1;
                double b1;
                r1 =get_pixel(im,i+1,j,0);
                g1 =get_pixel(im,i+1,j,1);
                b1 =get_pixel(im,i+1,j,2);
                double r2;
                double g2;
                double b2;
                r2 =get_pixel(im,im->height-1,j,0);
                g2 =get_pixel(im,im->height-1,j,1);
                b2 =get_pixel(im,im->height-1,j,2);
                double r3;
                double g3;
                double b3;
                r3 =get_pixel(im,i,j+1,0);
                g3 =get_pixel(im,i,j+1,1);
                b3 =get_pixel(im,i,j+1,2);
                double r4;
                double g4;
                double b4;
                r4 =get_pixel(im,i,im->width-1,0);
                g4 =get_pixel(im,i,im->width-1,1);
                b4 =get_pixel(im,i,im->width-1,2);
                double res = sqrt(pow((r1 - r2),2) + pow((g1 - g2),2) + pow((b1 - b2),2) + pow((r3 - r4),2) + pow((g3 - g4),2) + pow((b3 - b4),2));
                res = res / 10;
                uint8_t b = res;
//                printf("%f\n",res);
//                printf("%hhu\n",b);
            }
            if(i == im->height-1 && j == im->width-1){
                double r1;
                double g1;
                double b1;
                r1 =get_pixel(im,i-1,j,0);
                g1 =get_pixel(im,i-1,j,1);
                b1 =get_pixel(im,i-1,j,2);
                double r2;
                double g2;
                double b2;
                r2 =get_pixel(im,0,j,0);
                g2 =get_pixel(im,0,j,1);
                b2 =get_pixel(im,0,j,2);
                double r3;
                double g3;
                double b3;
                r3 =get_pixel(im,i,j-1,0);
                g3 =get_pixel(im,i,j-1,1);
                b3 =get_pixel(im,i,j-1,2);
                double r4;
                double g4;
                double b4;
                r4 =get_pixel(im,i,0,0);
                g4 =get_pixel(im,i,0,1);
                b4 =get_pixel(im,i,0,2);
                double res = sqrt(pow((r1 - r2),2) + pow((g1 - g2),2) + pow((b1 - b2),2) + pow((r3 - r4),2) + pow((g3 - g4),2) + pow((b3 - b4),2));
                res = res / 10;
                uint8_t b = res;
//                printf("%f\n",res);
//                printf("%hhu\n",b);
            }
            if(i == 0 && j != 0 && j !=im->width-1){
                double r1;
                double g1;
                double b1;
                r1 =(double)get_pixel(im,i+1,j,0);
                g1 =(double)get_pixel(im,i+1,j,1);
                b1 =(double)get_pixel(im,i+1,j,2);
                printf("%f\n",r1);
                printf("%f\n",g1);
                printf("%f\n",b1);
                double r2;
                double g2;
                double b2;
                r2 =(double)get_pixel(im,im->height-1,j,0);
                g2 =(double)get_pixel(im,im->height-1,j,1);
                b2 =(double)get_pixel(im,im->height-1,j,2);
                printf("%f\n",r2);
                printf("%f\n",g2);
                printf("%f\n",b2);
                double r3;
                double g3;
                double b3;
                r3 =(double)get_pixel(im,i,j+1,0);
                g3 =(double)get_pixel(im,i,j+1,1);
                b3 =(double)get_pixel(im,i,j+1,2);
                printf("%f\n",r3);
                printf("%f\n",g3);
                printf("%f\n",b3);
                double r4;
                double g4;
                double b4;
                r4 =(double)get_pixel(im,i,j-1,0);
                g4 =(double)get_pixel(im,i,j-1,1);
                b4 =(double)get_pixel(im,i,j-1,2);
                printf("%f\n",r4);
                printf("%f\n",g4);
                printf("%f\n",b4);
                double res = sqrt(pow((r1 - r2),2) + pow((g1 - g2),2) + pow((b1 - b2),2) + pow((r3 - r4),2) + pow((g3 - g4),2) + pow((b3 - b4),2));
                res = res / 10;
                uint8_t b = res;
//                printf("%f\n",res);
//                printf("%hhu\n",b);

            }
            if(j == 0 && i != 0 && i !=im->height -1){
                double r1;
                double g1;
                double b1;
                r1 =get_pixel(im,i+1,j,0);
                g1 =get_pixel(im,i+1,j,1);
                b1 =get_pixel(im,i+1,j,2);
                double r2;
                double g2;
                double b2;
                r2 =get_pixel(im,i-1,j,0);
                g2 =get_pixel(im,i-1,j,1);
                b2 =get_pixel(im,i-1,j,2);
                double r3;
                double g3;
                double b3;
                r3 =get_pixel(im,i,j+1,0);
                g3 =get_pixel(im,i,j+1,1);
                b3 =get_pixel(im,i,j+1,2);
                double r4;
                double g4;
                double b4;
                r4 =get_pixel(im,i,im->width-1,0);
                g4 =get_pixel(im,i,im->width-1,1);
                b4 =get_pixel(im,i,im->width-1,2);
                double res = sqrt(pow((r1 - r2),2) + pow((g1 - g2),2) + pow((b1 - b2),2) + pow((r3 - r4),2) + pow((g3 - g4),
                                                                                                                  2) + pow((b3 - b4),2));
                res = res / 10;
//                printf("%f\n",res);
                uint8_t b = res;
//                printf("%hhu\n",b);
            }
            if(i != 0 && j != 0 && i != im->height-1 && j != im->width-1){
                double r1;
                double g1;
                double b1;
                r1 =get_pixel(im,i+1,j,0);
                g1 =get_pixel(im,i+1,j,1);
                b1 =get_pixel(im,i+1,j,2);
                double r2;
                double g2;
                double b2;
                r2 =get_pixel(im,i-1,j,0);
                g2 =get_pixel(im,i-1,j,1);
                b2 =get_pixel(im,i-1,j,2);
                double r3;
                double g3;
                double b3;
                r3 =get_pixel(im,i,j+1,0);
                g3 =get_pixel(im,i,j+1,1);
                b3 =get_pixel(im,i,j+1,2);
                double r4;
                double g4;
                double b4;
                r4 =get_pixel(im,i,j-1,0);
                g4 =get_pixel(im,i,j-1,1);
                b4 =get_pixel(im,i,j-1,2);

                double res = sqrt(pow((r1 - r2),2) + pow((g1 - g2),2) + pow((b1 - b2),2) + pow((r3 - r4),2) + pow((g3 - g4),
                                                                                                                  2) + pow((b3 - b4),2));
                res = res / 10;
//                printf("%f\n",res);
                uint8_t b = res;
//                printf("%hhu\n",b);
            }
        }
    }

}
