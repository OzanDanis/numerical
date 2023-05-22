#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAX 25

typedef struct polynomial {
    double coef;
    double exp;
} polynomial;

typedef struct exponential {
    double f_coef;
    double base;
    double x_coef;
    double x_exp;
    double f_exp;
} exponential;

typedef struct logarithmic {
    double f_coef;
    double base;
    double x_coef;
    double x_exp;
    double f_exp;
} logarithmic;

typedef struct trigonometric {
    char name[MAX];
    double f_coef;
    double x_coef;
    double x_exp;
    double f_exp;
} trigonometric;

double poly_function(polynomial temp, double x);
double exp_function(exponential temp, double x);
double log_function(logarithmic temp, double x);
double tri_function(trigonometric temp, double x);


int main(){
    int control;
    int pol, log, tri, exp;
    int i, j;
    double start, stop, epsilon;
    int size;
    double matrix[MAX][MAX];

    exponential expo[5];
    polynomial poly[5];
    logarithmic logt[5];
    trigonometric trigo[5];

    printf("Number of polynomial elements: ");            
    printf("Number of polynomial elements: ");
    scanf("%d", &pol);
    printf("Number of logarithmic elements: ");
    scanf("%d", &log);
    printf("Number of trigonometric elements: ");
    scanf("%d", &tri);
    printf("Number of exponential elements: ");
    scanf("%d", &exp);     

   

    return 0;
}