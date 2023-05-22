#include<stdio.h>
#include<math.h>

#define MAX 25

double det_calculator(double arr[][MAX], int size);
void inverse_calculator(double arr[][MAX], int size);

int main() {
    int size;
    int i, j;
    double matrix[MAX][MAX];
    printf("Tersi hesaplanacak kare matrisin boyutunu giriniz:");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Matrisin %d. satır %d. sütun elemanını giriniz:", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
    inverse_calculator(matrix, size);

    return 0;
}

double det_calculator(double arr[][MAX], int size) {
    double determinant = 0;
    int i, j, k;

    if (size == 1) {
        determinant = arr[0][0];
    } else if (size == 2) {
        determinant = (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);
    } else if (size == 3) {
        determinant = (arr[0][0] * arr[1][1] * arr[2][2]) +
                      (arr[1][0] * arr[2][1] * arr[0][2]) +
                      (arr[2][0] * arr[0][1] * arr[1][2]) -
                      (arr[0][2] * arr[1][1] * arr[2][0]) -
                      (arr[1][2] * arr[2][1] * arr[0][0]) -
                      (arr[2][2] * arr[0][1] * arr[1][0]);
    } else {
        for (i = 0; i < size; i++) {
            double submatrix[MAX][MAX];
            int col = 0;

            for (j = 1; j < size; j++) {
                col = 0;

                for (k = 0; k < size; k++) {
                    if (k != i) {
                        submatrix[j - 1][col] = arr[j][k];
                        col++;
                    }
                }
            }

            determinant += arr[0][i] * pow(-1, i) * det_calculator(submatrix, size - 1);
        }
    }

    return determinant;
}

void inverse_calculator(double arr[][MAX], int size) {
    int i, j, k;
    double adj_matrix[MAX][MAX];
    double temp_matrix[MAX][MAX];
    double det;
	int l;
    det = det_calculator(arr, size);
	int sub_i = 0, sub_j = 0;
    if (det == 0) {
        printf("Matrisin tersi bulunamaz.\n");
        return;
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            sub_j=0;
            sub_i=0;
            for (k = 0; k < size; k++) {
                if (k != i) {
                    sub_j = 0;
                    for ( l = 0; l < size; l++) {
                        if (l != j) {
                            temp_matrix[sub_i][sub_j] = arr[k][l];
                            sub_j++;
                        }
                    }
                    sub_i++;
                }
            }

            double sub_det = det_calculator(temp_matrix, size - 1);
            adj_matrix[i][j] = sign * sub_det;
        }
    }

    double adj_transpose[MAX][MAX];

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            adj_transpose[i][j] = adj_matrix[j][i] / det;
        }
    }

    printf("Matrisin tersi:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%lf\t", adj_transpose[i][j]);
        }
        printf("\n");
    }
}