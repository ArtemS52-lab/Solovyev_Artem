#include <stdio.h>
double Weight();
int main(void)
{
    float weight = Weight();
    printf("The total weight of the cabinet: %.3f kg\n",weight);
}
double Weight ()
{
    double h, w, d;          
    double density_dsp, density_dvp, density_wood;
    double dsp_volume, dvp_volume, wood_volume;
    const double thick_dvp = 0.5;   
    const double thick_dsp = 1.5;  
    const double thick_wood = 1.0;  
    const double shelf_step = 40.0;

    printf("Enter the height of the cabinet h (cm, 180-220):\n");
    if (scanf("%lf", &h) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Enter the width of the cabinet w (cm, 80-120): \n");
    if (scanf("%lf", &w) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Enter the depth of the cabinet d (cm, 50-90):\n");
    if (scanf("%lf", &d) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    if (h < 180 || h > 220 || w < 80 || w > 120 || d < 50 || d > 90) {
        printf("Dimensions are outside the permissible range!\n");
        return 1;
    }
    printf("Enter the density of the chipboard (g/cm³): \n");
    if (scanf("%lf", &density_dsp) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Enter the density of the fiberboard (g/cm³):\n ");
    if (scanf("%lf", &density_dvp) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Enter the density of the wood (g/cm³):\n ");
    if (scanf("%lf", &density_wood) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    
    int num_shelves = 0;
    for (double y = shelf_step; y < h; y += shelf_step) {
        num_shelves++;
    }
    dvp_volume = h * w * thick_dvp;
    dsp_volume = (2.0 * h * d * thick_dsp)+(2.0 * w * d * thick_dsp)+(num_shelves * w * d * thick_dsp);
    wood_volume = w * h * thick_wood;

   
    
    double mass_g = dvp_volume*density_dvp+ dsp_volume*density_dsp+wood_volume*density_wood ;
    double mass_kg = mass_g / 1000.0;

    return 0;
}