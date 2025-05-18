#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// === Кольори ===
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define MAGENTA "\033[1;35m"

int main() {
    int choice;
    srand(time(NULL));

    while (1) {
        printf("\n==== Що робимо? ===\n");
        printf("1. Згенерувати квадратну матрицю і знайти мінімум вище бічної діагоналі\n");
        printf("0. Вийти з програми\n");
        printf(MAGENTA "Ваш вибір: " RESET);
        scanf("%d", &choice);

        if (choice == 0) {
            printf(GREEN "Виходимо..\n" RESET);
            break;
        } else if (choice == 1) {
            int n;
            printf("Введи розмірність квадратної матриці (n): ");
            scanf("%d", &n);

            if (n <= 0) {
                printf(RED "Розмірність матриці має бути більше 0. Не сміши.\n" RESET);
                continue;
            }

            int matrix[n][n];

            // Генерація матриці
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = rand() % 201 - 100;
                }
            }

            // Вивід матриці з кольорами
            printf(MAGENTA "Згенерована матриця:\n" RESET);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] > 0) {
                        printf(GREEN "%5d " RESET, matrix[i][j]);
                    } else if (matrix[i][j] < 0) {
                        printf(RED "%5d " RESET, matrix[i][j]);
                    } else {
                        printf("%5d ", matrix[i][j]);
                    }
                }
                printf("\n");
            }

            // Пошук мінімуму вище бічної діагоналі
            int min = 0, found = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - 1 - i; j++) {
                    if (!found) {
                        min = matrix[i][j];
                        found = 1;
                    } else if (matrix[i][j] < min) {
                        min = matrix[i][j];
                    }
                }
            }

            if (found) {
                printf(MAGENTA "Мінімальний елемент вище бічної діагоналі: " RESET "%d\n", min);
            } else {
                printf(RED "Немає елементів вище бічної діагоналі.\n" RESET);
            }

        } else {
            printf(RED "Немає такого варіанту. Спробуй ще раз.\n" RESET);
        }
    }

    return 0;
}
