#include<stdio.h>
#include<math.h>

#define MAX 25

double function(double arr[], int size, double x);
double regula_falsi(double arr[], int size, double lower, double upper, double error);

int main (){
    double polynom[MAX], lower, upper, error;
    int i = 0, derece = 0;

    printf("fonksiyonun derecesini giriniz:");
    scanf("%d", &derece);

    for (i = 0 ; i <= derece ; i++){
        printf("x^%d li terimin katsayisini giriniz:", i);
        scanf("%lf", &polynom[i]);
    }

    printf("error, lower ve upper degerlerini giriniz:");
    scanf("%lf %lf %lf", &error, &lower, &upper);
    
    regula_falsi(polynom, derece, lower, upper, error);

    return 0;
}

double regula_falsi(double arr[], int size, double lower, double upper, double error){
    double x_1, x_2, x_3, x;
    int control=0;
    while(fabs(lower-upper) > error){
        x_1 = function(arr, size, lower);
        x_2 = function(arr, size, upper);
        x_3= ((upper*x_1)-(x_2*lower))/(x_1-x_2);
        x = function(arr, size, x_3);
        control++;
        if(fabs(x) < error ){
            printf("kok degeri:%lf", x_3);
            return x_3;
        }
        else if(x_1 * x < 0){
            upper = x_3;
        }
        else{
            lower = x_3;    
        }
        
    }

    printf("yaklasik deger:%lf\n", x_3);
    printf("iterasyon sayisi: %d", control);

    return x_3;
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
