#include <stdio.h>
#include <math.h>

#define MAX 25

double function(double arr[], int size, double x);
double bisection_method(double arr[], int size, double lower, double upper, double error);

int main() {
    double polynom[MAX], x, lower, upper, error;
    int i = 0, derece = 0;
    double deneme = 0;

    printf("fonksiyonun derecesini giriniz:");
    scanf("%d", &derece);

    for (i = 0 ; i <= derece ; i++){
        printf("x^%d li terimin katsayisini giriniz:", i);
        scanf("%lf", &polynom[i]);
    }

    printf("error, lower ve upper degerlerini giriniz:");
    scanf("%lf %lf %lf", &error, &lower, &upper);

    bisection_method(polynom, derece, lower, upper, error);

    return 0;
}

double function(double arr[], int size, double x) {
    int i;
    double sum = 0, tmp = x;
    sum = arr[0];

    for (i = 1 ; i <= size ; i++) {
        sum = sum + (arr[i] * tmp);
        tmp = tmp * x;
    }

    return sum;
}

double bisection_method(double arr[], int size, double lower, double upper, double error) {
    double tmp = 0, x, y;
    int control = 0;

    while (fabs(lower - upper) > error) {
        tmp = (lower + upper) / 2;
        x = function(arr, size, tmp);
        y = function(arr, size, upper);

        if (x == 0) {
            printf("kok degeri:%lf", tmp);
            return tmp;
        }
        else if (x * y < 0) {
            lower = tmp;
        }
        else {
            upper = tmp;
        }

        control++;
    }

    printf("yaklasik deger:%lf\n", tmp);
    printf("iterasyon sayisi:%d", control);

    return tmp;
}
