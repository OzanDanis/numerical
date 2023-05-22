#include <stdio.h>
#include <math.h>

#define MAX 25

void gaus_seidel(double arr[][MAX], int size, double epsilon);

int main() {
    double arr[MAX][MAX];
    int i, j;
    int size;
    double epsilon;
    int max_index;
    double temp;

    printf("Enter the size of the augmented matrix: ");
    scanf("%d", &size);

                if (size <= 0 || size > MAX) {
                    printf("Invalid matrix size.\n");
                    return 1;
                }

            for (i = 0; i < size; i++) {
                for (j = 0; j < size + 1; j++) {
                    printf("Enter the %dth row, %dth column: ", i + 1, j + 1);
                    scanf("%lf", &arr[i][j]);
                }
            }
            printf("Enter the epsilon:");
            scanf("%lf", &epsilon);

            for (i = 0; i < size; i++) {
                temp = fabs(arr[i][i]);
                max_index = i;
                for (j = i + 1; j < size; j++) {
                    if (fabs(arr[j][i]) > temp) {
                        temp = fabs(arr[j][i]);
                        max_index = j;
                    }
                }
                if (max_index != i) {
                    for (j = i; j < size + 1; j++) {
                        double temp_2 = arr[i][j];
                        arr[i][j] = arr[max_index][j];
                        arr[max_index][j] = temp_2;
                    }
                }
            }

    gaus_seidel(arr, size, epsilon);

    return 0;
}

void gaus_seidel(double arr[][MAX], int size, double epsilon) {
    double x[MAX] = {0}; 
    int i, j;
    double sum;
    double diff;
    int iterations = 0;

    int continueLoop = 1;
    while (continueLoop) {
        diff = 0;

        for (i = 0; i < size; i++) {
            sum = 0;

            for (j = 0; j < size; j++) {
                if (j != i) {
                    sum += arr[i][j] * x[j];
                }
            }

            double newX = (arr[i][size] - sum) / arr[i][i];
            diff += fabs(newX - x[i]);
            x[i] = newX;
        }

        iterations++;

        if (diff < epsilon || iterations >= 100) {
            continueLoop = 0;
        }
    }

    printf("Result:\n");
    for (i = 0; i < size; i++) {
        printf("x%d = %lf\n", i + 1, x[i]);
    }
}
