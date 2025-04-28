#include <stdio.h>

int main() {
    // *Задача 1
    int n; //сюди ловимо розмірність матриці
    printf("Введіть розмірність матриці (n): ");
    scanf("%d", &n);

    int matrix1[n][n];

    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix1[%d][%d] = ", i, j); // Додано 1 до назви змінної, щоб відрізняти від matrix2 при вводі
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nГоловна діагональ: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", matrix1[i][i]);
    }
    printf("\n");

    printf("Бічна діагональ: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", matrix1[i][n - 1 - i]);
    }
    printf("\n");

    printf("Елементи вище головної діагоналі (збільшені в 2 рази): ");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("%d ", matrix1[i][j] * 2);
        }
    }
    printf("\n");

    // **Задача 2
    int m;
    printf("\nВведіть кількість рядків (n): ");
    scanf("%d", &n);
    printf("Введіть кількість стовпців (m): ");
    scanf("%d", &m);
    
    int matrix2[n][m];

    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("matrix2[%d][%d] = ", i, j); // Додано 2 до назви змінної, щоб відрізняти від matrix1 при вводі
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Ініціалізація minVal та maxVal першим елементом матриці
    int minVal = matrix2[0][0];
    int maxVal = matrix2[0][0];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix2[i][j] < minVal) {
                minVal = matrix2[i][j];
            }
            if (matrix2[i][j] > maxVal) {
                maxVal = matrix2[i][j];
            }
        }
    }

    double avg = (double)(minVal + maxVal) / 2.0;
    printf("Мінімальний елемент: %d\n", minVal);
    printf("Максимальний елемент: %d\n", maxVal);
    printf("Середнє арифметичне максимального та мінімального: %.2f\n", avg);

    return 0;
}