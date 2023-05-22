#include <stdio.h>
#include <math.h>
#include <string.h>

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

void bisection(polynomial poly[], int sizep, exponential exp[], int sizex, logarithmic log[], int sizel, trigonometric tri[], int sizet, double start, double stop, double epsilon);
void regula_falsi(polynomial poly[], int sizep, exponential exp[], int sizex, logarithmic log[], int sizel, trigonometric tri[], int sizet, double start, double stop, double epsilon);
void newton_raphson(polynomial poly[], int sizep, exponential exp[], int sizex, logarithmic log[], int sizel, trigonometric tri[], int sizet, double start, double epsilon);

int main() {
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

    do {
        printf("QUIT: 0\nBISECTION: 1\nREGULA-FALSI: 2\nNEWTON RAPHSON: 3\nINVERSE MATRIX: 4\nGAUS ELIMINATION: 5\n");
        printf("GAUS-SEIDEL: 6\nNUMERICAL DIFFERENTIATION: 7\nSIMPSON'S RULE: 8\nTRAPEZOIDAL RULE: 9\nGREGORY-NEWTON: 10\n");
        scanf("%d", &control);

        if (control < 0 || control > 10) {
            printf("You entered the wrong command, please re-enter: ");
            scanf("%d", &control);
        }

        if (control != 0) {
            printf("Number of polynomial elements: ");
            scanf("%d", &pol);
            printf("Number of logarithmic elements: ");
            scanf("%d", &log);
            printf("Number of trigonometric elements: ");
            scanf("%d", &tri);
            printf("Number of exponential elements: ");
            scanf("%d", &exp);

            for (i = 0; i < pol; i++) {
                printf("Enter the coefficient of the polynomial element %d: ", i + 1);
                scanf("%lf", &poly[i].coef);
                printf("Enter the exponent of the polynomial element %d: ", i + 1);
                scanf("%lf", &poly[i].exp);
            }

            for (i = 0; i < log; i++) {
                printf("Enter the coefficient of the logarithmic function %d: ", i + 1);
                scanf("%lf", &logt[i].f_coef);
                printf("Enter the base of the logarithmic element %d: ", i + 1);
                scanf("%lf", &logt[i].base);
                printf("Enter the x coefficient of the logarithmic element %d: ", i + 1);
                scanf("%lf", &logt[i].x_coef);
                printf("Enter the x exponent of the logarithmic element %d: ", i + 1);
                scanf("%lf", &logt[i].x_exp);
                printf("Enter the function exponent of the logarithmic element %d: ", i + 1);
                scanf("%lf", &logt[i].f_exp);
            }

            for (i = 0; i < exp; i++) {
                printf("Enter the coefficient of the exponential function %d: ", i + 1);
                scanf("%lf", &expo[i].f_coef);
                printf("Enter the base of the exponential element %d: ", i + 1);
                scanf("%lf", &expo[i].base);
                printf("Enter the x coefficient of the exponential element %d: ", i + 1);
                scanf("%lf", &expo[i].x_coef);
                printf("Enter the x exponent of the exponential element %d: ", i + 1);
                scanf("%lf", &expo[i].x_exp);
                printf("Enter the function exponent of the exponential element %d: ", i + 1);
                scanf("%lf", &expo[i].f_exp);
            }

            for (i = 0; i < tri; i++) {
                printf("Enter the name of the trigonometric function %d: ", i + 1);
                scanf("%s", trigo[i].name);
                printf("Enter the %dst trigonometric function coefficient: ", i + 1);
                scanf("%lf", &trigo[i].f_coef);
                printf("Enter the %dst trigonometric function x coefficient: ", i + 1);
                scanf("%lf", &trigo[i].x_coef);
                printf("Enter the %dst trigonometric function x exponent: ", i + 1);
                scanf("%lf", &trigo[i].x_exp);
                printf("Enter the %dst trigonometric function exponent: ", i + 1);
                scanf("%lf", &trigo[i].f_exp);
            }
        }

        if (control == 1) {
            printf("\t\t!YOU ARE USING BISECTION!\n");
            printf("Enter the start: ");
            scanf("%lf", &start);
            printf("Enter the end: ");
            scanf("%lf", &stop);
            printf("Enter the epsilon: ");
            scanf("%lf", &epsilon);

            bisection(poly, pol, expo, exp, logt, log, trigo, tri, start, stop, epsilon);
        }
        else if(control == 2){
            printf("\t\t!YOU ARE USING REGULA-FALSI!\n");
            printf("Enter the start: ");
            scanf("%lf", &start);
            printf("Enter the end: ");
            scanf("%lf", &stop);
            printf("Enter the epsilon: ");
            scanf("%lf", &epsilon);

            regula_falsi(poly, pol, expo, exp, logt, log, trigo, tri, start, stop, epsilon);
        }
        else if(control == 3){
            printf("\t\t!YOU ARE USING NEWTON RAPHSON!\n");
            printf("Enter the start: ");
            scanf("%lf", &start);
            printf("Enter the epsilon: ");
            scanf("%lf", &epsilon);

            newton_raphson(poly, pol, expo, exp, logt, log, trigo, tri, start, epsilon);
        }
        else if(control == 4){
            
        }

    } while (control != 0);

    return 0;
}

double poly_function(polynomial temp, double x) {
    return temp.coef * pow(x, temp.exp);
}

double exp_function(exponential temp, double x) {
    return temp.f_coef * pow(pow(temp.base, temp.x_coef * pow(x, temp.x_exp)), temp.f_exp);
}

double log_function(logarithmic temp, double x) {
    if(temp.x_coef * pow(x, temp.x_exp) == 0){
        printf("\t404 not found!!!\n");
        return 0;
    }
    return temp.f_coef * pow(log(temp.x_coef * pow(x, temp.x_exp)) / log(temp.base), temp.f_exp);
}

double tri_function(trigonometric temp, double x) {
    if (strcmp(temp.name, "sin") == 0) {
        return temp.f_coef * pow(sin(temp.x_coef * pow(x, temp.x_exp) * M_PI / 180), temp.f_exp);
    } else if (strcmp(temp.name, "cos") == 0) {
        return temp.f_coef * pow(cos(temp.x_coef * pow(x, temp.x_exp) * M_PI / 180), temp.f_exp);
    } else if (strcmp(temp.name, "tan") == 0) {
        return temp.f_coef * pow(tan(temp.x_coef * pow(x, temp.x_exp) * M_PI / 180), temp.f_exp);
    } else if (strcmp(temp.name, "cot") == 0) {
        return temp.f_coef * pow(1 / tan(temp.x_coef * pow(x, temp.x_exp) * M_PI / 180), temp.f_exp);
    } else if (strcmp(temp.name, "sec") == 0) {
        return temp.f_coef * pow(1 / cos(temp.x_coef * pow(x, temp.x_exp) * M_PI / 180), temp.f_exp);
    } else if (strcmp(temp.name, "csc") == 0) {
        return temp.f_coef * pow(1 / sin(temp.x_coef * pow(x, temp.x_exp) * M_PI / 180), temp.f_exp);
    } else {
        printf("Invalid trigonometric function name.\n");
        return 0;
    }
}

void bisection(polynomial poly[], int sizep, exponential exp[], int sizex, logarithmic log[], int sizel, trigonometric tri[], int sizet, double start, double stop, double epsilon) {
    double a = start;
    double b = stop;
    double c = (a + b) / 2;
    double fa, fb, fc;
    int i;

    do {
        fa = 0;
        fb = 0;
        fc = 0;

        for (i = 0; i < sizep; i++) {
            fa += poly_function(poly[i], a);
            fb += poly_function(poly[i], b);
            fc += poly_function(poly[i], c);
        }

        for (i = 0; i < sizex; i++) {
            fa += exp_function(exp[i], a);
            fb += exp_function(exp[i], b);
            fc += exp_function(exp[i], c);
        }

        for (i = 0; i < sizel; i++) {
            fa += log_function(log[i], a);
            fb += log_function(log[i], b);
            fc += log_function(log[i], c);
        }

        for (i = 0; i < sizet; i++) {
            fa += tri_function(tri[i], a);
            fb += tri_function(tri[i], b);
            fc += tri_function(tri[i], c);
        }

        if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
        }

        c = (a + b) / 2;

    } while (fabs(fc) > epsilon);

    printf("The root of the function is: %f\n", c);
}

void regula_falsi(polynomial poly[], int sizep, exponential exp[], int sizex, logarithmic log[], int sizel, trigonometric tri[], int sizet, double start, double stop, double epsilon){
    double a = start;
    double b = stop;
    double c;
    double fa, fb, fc;
    int i;

    do{
        fa = 0;
        fb = 0;
        fc = 0;

        for (i = 0; i < sizep; i++) {
            fa += poly_function(poly[i], a);
            fb += poly_function(poly[i], b);
        }

        for (i = 0; i < sizex; i++) {
            fa += exp_function(exp[i], a);
            fb += exp_function(exp[i], b);
        }

        for (i = 0; i < sizel; i++) {
            fa += log_function(log[i], a);
            fb += log_function(log[i], b);
        }

        for (i = 0; i < sizet; i++) {
            fa += tri_function(tri[i], a);
            fb += tri_function(tri[i], b);
        }
        
        c=((a*fb)-(b*fa))/(fb-fa);

        for (i = 0; i < sizep; i++) {
            fc += poly_function(poly[i], c);
        }

        for (i = 0; i < sizex; i++) {
            fc += exp_function(exp[i], c);
        }

        for (i = 0; i < sizel; i++) {
            fc += log_function(log[i], c);
        }

        for (i = 0; i < sizet; i++) {
            fc += tri_function(tri[i], c);
        }

        if(fa * fc < 0){
            b = c;
        }
        else{
            a = c;
        }
    }while (fabs(fc) > epsilon);

    printf("The root of the function is: %f\n", c);
}

void newton_raphson(polynomial poly[], int sizep, exponential exp[], int sizex, logarithmic log[], int sizel, trigonometric tri[], int sizet, double start, double epsilon){
    double a = start;
    double c;
    double fa, fd, fc;
    int i;
    int step = 0;
    double h = 0.000001;

    do{
        fa = 0;
        fd = 0;
        fc = 0;

        for (i = 0; i < sizep; i++) {
            fa += poly_function(poly[i], a);
        }

        for (i = 0; i < sizex; i++) {
            fa += exp_function(exp[i], a);
        }

        for (i = 0; i < sizel; i++) {
            fa += log_function(log[i], a);
        }

        for (i = 0; i < sizet; i++) {
            fa += tri_function(tri[i], a);
        }

        

        for (i = 0; i < sizep; i++) {
            fd += poly_function(poly[i], a+h);
        }

        for (i = 0; i < sizex; i++) {
            fd += exp_function(exp[i], a+h);
        }

        for (i = 0; i < sizel; i++) {
            fd += log_function(log[i], a+h);
        }

        for (i = 0; i < sizet; i++) {
            fd += tri_function(tri[i], a+h);
        }

        c = a - fa/((fd - fa)/h);
        for (i = 0; i < sizep; i++) {
            fc += poly_function(poly[i], c);
        }

        for (i = 0; i < sizex; i++) {
            fc += exp_function(exp[i], c);
        }

        for (i = 0; i < sizel; i++) {
            fc += log_function(log[i], c);
        }

        for (i = 0; i < sizet; i++) {
            fc += tri_function(tri[i], c);
        }
        step++;

    }while(fabs(fc) > epsilon && step < 100);

    printf("The root of the function is: %f\n", c);
}