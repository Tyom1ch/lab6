#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// === Кольори ===
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define YELLOW  "\033[1;33m" // Колір для мінімуму

int main() {
    int choice;
    srand(time(NULL));

    while (1) {
        // Вивід меню
        printf("\n==== Шо робим, пацани? ====\n");
        printf("1. Замутити квадратну матрицю і знайти мінімум вище бічної діагоналі\n");
        printf("0. Звалити звідси\n");
        printf(MAGENTA "Твій вибір, братан: " RESET);
        // Введення вибору
        scanf("%d", &choice);

        if (choice == 0) {
            printf(GREEN "Звалюємо...\n" RESET);
            break;
        } else if (choice == 1) {
            int n;
            printf("Введи розмірність квадратної матриці (n): ");
            if (scanf("%d", &n) != 1) {
                printf(RED "Шось ти не те ввів, братан. Давай число!\n" RESET);
                while (getchar() != '\n'); // Очистка буфера вводу
                continue;
            }

            if (n <= 0) {
                printf(RED "Розмірність матриці має бути більше 0. Ти шо, гониш?\n" RESET);
                continue;
            }

            int matrix[n][n];

            // Генерація матриці
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = rand() % 201 - 100;
                }
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

            // Вивід матриці з кольорами
            printf(MAGENTA "Замучена матриця:\n" RESET);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i < n && j < n - 1 - i && found && matrix[i][j] == min) {
                        printf(YELLOW "%5d " RESET, matrix[i][j]); // Мінімум жовтим
                    } else if (matrix[i][j] > 0) {
                        printf(GREEN "%5d " RESET, matrix[i][j]); // Додатні зелені
                    } else if (matrix[i][j] < 0) {
                        printf(RED "%5d " RESET, matrix[i][j]);   // Від'ємні червоні
                    } else {
                        printf("%5d ", matrix[i][j]);            // Нулі звичайним кольором
                    }
                }
                printf("\n");
            }

            if (found) {
                printf(MAGENTA "Мінімальний елемент вище бічної діагоналі: " RESET YELLOW "%d" RESET "\n", min);
            } else {
                printf(RED "Немає елементів вище бічної діагоналі, братан.\n" RESET);
            }

        } else {
            printf(RED "Немає такого варіанту, фраєр. Спробуй ще раз.\n" RESET);
        }
    }

    return 0;
}
