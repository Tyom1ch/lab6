#include <stdio.h>
#include <limits.h> // Для INT_MAX та INT_MIN

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define WHITE   "\033[1;37m"
#define YELLOW  "\033[1;33m" // Жовтий, щоб мінімум світився
#define MAGENTA "\033[1;35m" // Маджента, щоб максимум сяяв
#define RESET   "\033[0m"

// Function to clear input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
    int choice;
    const int MAX_ROWS = 100;
    const int MAX_COLS = 100;
    int matrix[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;

    do {
        printf(WHITE"\n=== Чим сьогодні душу відведемо? ===\n"RESET);
        printf("1. Головна та бічна діагоналі квадратної матриці (діагоналі - то святе!)\n");
        printf("2. Мінімальний, максимальний елементи та їх середнє арифметичне (шукаємо золото партії!)\n");
        printf("3. Ввести матрицю (заповнюємо плацдарм!)\n");
        printf("4. Вивести матрицю (дивимося, що накопали!)\n");
        printf("0. На волю (Звалити)\n");
        printf("Твій вибір, фраєрок: ");

        // Input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            printf(RED "⚠️ Та ти шо, це навіть не цифра!  Давай нормально!\n" RESET);
            clear_input_buffer(); // Clear the invalid input
            choice = -1; // Set an invalid choice to force re-prompting
            continue;
        }

        switch (choice) {
            case 1: {
                if (rows == 0 || cols == 0) {
                    printf(RED "⚠️ Стривай, спочатку треба матрицю ввести, а то шось не по масті!\n" RESET);
                    break;
                }
                if (rows != cols) {
                    printf(RED "⚠️ Тут тільки квадратна матриця канає, не крути!\n" RESET);
                    break;
                }

                printf("Матриця, як на долоні:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (i == j) {
                            // Головна діагональ
                            if (matrix[i][j] > 0)
                                printf(GREEN "%5d " RESET, matrix[i][j]);
                            else if (matrix[i][j] < 0)
                                printf(RED "%5d " RESET, matrix[i][j]);
                            else
                                printf(WHITE "%5d " RESET, matrix[i][j]);
                        } else if (i + j == rows - 1) {
                            // Бічна діагональ
                            if (matrix[i][j] > 0)
                                printf(GREEN "%5d " RESET, matrix[i][j]);
                            else if (matrix[i][j] < 0)
                                printf(RED "%5d " RESET, matrix[i][j]);
                            else
                                printf(WHITE "%5d " RESET, matrix[i][j]);
                        } else if (matrix[i][j] > 0) {
                            printf(GREEN "%5d " RESET, matrix[i][j]);
                        } else if (matrix[i][j] < 0) {
                            printf(RED "%5d " RESET, matrix[i][j]);
                        } else {
                            printf(WHITE "%5d " RESET, matrix[i][j]);
                        }
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

                printf("Бічна діагональ, тіпа обхідний шлях: ");
                for (int i = 0; i < rows; i++) {
                    if (matrix[i][rows - 1 - i] > 0)
                        printf(GREEN "%d " RESET, matrix[i][rows - 1 - i]);
                    else if (matrix[i][rows - 1 - i] < 0)
                        printf(RED "%d " RESET, matrix[i][rows - 1 - i]);
                    else
                        printf(WHITE "%d " RESET, matrix[i][rows - 1 - i]);
                }
                printf("\n");

                printf("Елементи вище головної діагоналі (помножені на 2), ну тіпа подвійний профіт: ");
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
                    printf(RED "⚠️ Е, фраєр, де матриця? Без неї нікуди!\n" RESET);
                    break;
                }

                int minVal = matrix[0][0];
                int maxVal = matrix[0][0];

                // Шукаємо мінімальний та максимальний елементи, як скарб
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (matrix[i][j] < minVal) minVal = matrix[i][j];
                        if (matrix[i][j] > maxVal) maxVal = matrix[i][j];
                    }
                }

                printf("Матриця, дивись уважно:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (matrix[i][j] == minVal) {
                            printf(YELLOW "%5d " RESET, matrix[i][j]); // Мінімум світиться жовтим
                        } else if (matrix[i][j] == maxVal) {
                            printf(MAGENTA "%5d " RESET, matrix[i][j]); // Максимум сяє маджентою
                        } else {
                            printf(WHITE "%5d " RESET, matrix[i][j]);
                        }
                    }
                    printf("\n");
                }

                double avg = (minVal + maxVal) / 2.0;
                printf("Мінімальний елемент: " YELLOW "%d\n" RESET, minVal); // Як діамант у купі каміння
                printf("Максимальний елемент: " MAGENTA "%d\n" RESET, maxVal); // Золото партії!
                printf("Середнє арифметичне: " WHITE "%.2f" RESET"\n", avg); // Тут все по чесному
                break;
            }

            case 3: {
                printf("Скільки рядків будемо копати? ");
                if (scanf("%d", &rows) != 1) {
                    printf(RED "⚠️ Та ти шо, це навіть не цифра! Давай нормально!\n" RESET);
                    clear_input_buffer();
                    rows = 0;
                    cols = 0;
                    break;
                }
                printf("А стовпців скільки, щоб не завалило? ");
                if (scanf("%d", &cols) != 1) {
                    printf(RED "⚠️ І тут не цифра?  Знущаєшся?\n" RESET);
                    clear_input_buffer();
                    rows = 0;
                    cols = 0;
                    break;
                }

                if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
                    printf(RED "⚠️ Та ти шо, береги попутав? Розміри нормальні давай!\n" RESET, MAX_ROWS);
                    rows = cols = 0;
                    break;
                }

                printf("Вводи числа, як на допиті:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("matrix[%d][%d] = ", i, j);
                        if (scanf("%d", &matrix[i][j]) != 1) {
                            printf(RED "⚠️ Шось ти не те вводиш, я ж просив числа!\n" RESET);
                            clear_input_buffer(); // Clear bad input. Important!
                            // Set the current element to 0 or a default value and continue,
                            // or you could bail out entirely with rows = cols = 0; break;
                            matrix[i][j] = 0; // Example: set to 0
                        }
                    }
                }

                printf(GREEN "Матриця збережена, як в банку!\n" RESET);
                break;
            }
            case 4: {
                if (rows == 0 || cols == 0) {
                    printf(RED "⚠️ Ти дивись, знову без матриці! Шо за бардак?\n" RESET);
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
                break;
            }
            case 0:
                printf(GREEN "Звалюємо...\n" RESET); // На волю, як птах!
                break;

            default:
                printf(RED "⚠️ Ти шо, цифри переплутав? Давай ще раз, але по-людськи!\n" RESET);
                break;
        }

    } while (choice != 0);

    return 0;
}