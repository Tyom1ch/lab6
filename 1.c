// file: matrix_menu_colors.c

#include <stdio.h>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define WHITE   "\033[1;37m"
#define RESET   "\033[0m"

int main() {
    int choice;
    int maxRows = 100;
    int matrix[100][100]; // буферна матриця, ну або квадратна
    int rows = 0, cols = 0;

    do {
        printf(WHITE"\n=== Чим побалуємося? ===\n"RESET);
        printf("1. Головна та бічна діагоналі квадратної матриці\n");
        printf("2. Мінімальний, максимальний елементи та їх середнє арифметичне\n");
        printf("3. Ввести матрицю\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (rows == 0 || cols == 0) {
                    printf(RED "⚠ Спочатку введіть матрицю через пункт 3.\n" RESET);
                    break;
                }
                if (rows != cols) {
                    printf(RED "⚠ Ця опція доступна лише для квадратної матриці.\n" RESET);
                    break;
                }

                printf("Матриця:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (matrix[i][j] > 0)
                            printf(GREEN "%5d " RESET, matrix[i][j]);
                        else if (matrix[i][j] < 0)
                            printf(RED "%5d " RESET, matrix[i][j]);
                        else
                            printf(WHITE "%5d " RESET, matrix[i][j]);
                    }
                    printf("\n");
                }

                printf("\nГоловна діагональ: ");
                for (int i = 0; i < rows; i++) {
                    if (matrix[i][i] > 0)
                        printf(GREEN "%d " RESET, matrix[i][i]);
                    else if (matrix[i][i] < 0)
                        printf(RED "%d " RESET, matrix[i][i]);
                    else
                        printf(WHITE "%d " RESET, matrix[i][i]);
                }
                printf("\n");

                printf("Бічна діагональ: ");
                for (int i = 0; i < rows; i++) {
                    if (matrix[i][rows - 1 - i] > 0)
                        printf(GREEN "%d " RESET, matrix[i][rows - 1 - i]);
                    else if (matrix[i][rows - 1 - i] < 0)
                        printf(RED "%d " RESET, matrix[i][rows - 1 - i]);
                    else
                        printf(WHITE "%d " RESET, matrix[i][rows - 1 - i]);
                }
                printf("\n");

                printf("Елементи вище головної діагоналі (помножені на 2): ");
                for (int i = 0; i < rows; i++) {
                    for (int j = i + 1; j < cols; j++) {
                        int val = matrix[i][j] * 2;
                        if (val > 0)
                            printf(GREEN "%d " RESET, val);
                        else if (val < 0)
                            printf(RED "%d " RESET, val);
                        else
                            printf(WHITE "%d " RESET, val);
                    }
                }
                printf("\n");
                break;
            }

            case 2: {
                if (rows == 0 || cols == 0) {
                    printf(RED "⚠ Спочатку введіть матрицю через пункт 3.\n" RESET);
                    break;
                }

                printf("Матриця:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (matrix[i][j] > 0)
                            printf(GREEN "%5d " RESET, matrix[i][j]);
                        else if (matrix[i][j] < 0)
                            printf(RED "%5d " RESET, matrix[i][j]);
                        else
                            printf(WHITE "%5d " RESET, matrix[i][j]);
                    }
                    printf("\n");
                }

                int minVal = matrix[0][0];
                int maxVal = matrix[0][0];

                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (matrix[i][j] < minVal) minVal = matrix[i][j];
                        if (matrix[i][j] > maxVal) maxVal = matrix[i][j];
                    }
                }

                double avg = (minVal + maxVal) / 2.0;
                printf("Мінімальний елемент: ");
                if (minVal > 0)
                    printf(GREEN "%d\n" RESET, minVal);
                else if (minVal < 0)
                    printf(RED "%d\n" RESET, minVal);
                else
                    printf(WHITE "%d\n" RESET, minVal);
                printf("Максимальний елемент: ");
                if (maxVal > 0)
                    printf(GREEN "%d\n" RESET, maxVal);
                else if (maxVal < 0)
                    printf(RED "%d\n" RESET, maxVal);
                else
                    printf(WHITE "%d\n" RESET, maxVal);
                printf("Середнє арифметичне: " GREEN "%.2f" RESET"\n", avg);
                break;
            }

            case 3: {
                printf("Введіть кількість рядків: ");
                scanf("%d", &rows);
                printf("Введіть кількість стовпців: ");
                scanf("%d", &cols);

                if (rows <= 0 || cols <= 0 || rows > maxRows || cols > maxRows) {
                    printf(RED "Неприпустимі розміри. Обмеження: 1-%d\n" RESET, maxRows);
                    rows = cols = 0;
                    break;
                }

                printf("Введіть елементи матриці:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("matrix[%d][%d] = ", i, j);
                        scanf("%d", &matrix[i][j]);
                    }
                }

                printf(GREEN "Матриця збережена\n" RESET);
                break;
            }

            case 0:
                printf(GREEN "Бувай\n" RESET);
                break;

            default:
                printf(RED "Некоректний вибір! Повтори ще раз.\n" RESET);
                break;
        }

    } while (choice != 0);

    return 0;
}