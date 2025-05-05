#include <stdio.h>

// Часікі і бібліотеки рандомайзера
#include <stdlib.h>
#include <time.h>

int main() {
  int choice;

  srand(time(NULL)); // Ініціалізація ДУЖЕ ЗРУЧНОГО генератора випадкових чисел

  while (1) {
    printf("\nЧим побалуємося?:\n");
    printf("1. Згенерувати двовимірний масив\n");
    printf("2. Ввести квадратну матрицю та знайти мінімальний елемент вище "
           "бічної діагоналі.\n");
    printf("0. Вихід\n");
    printf("Ваш вибір: ");
    scanf("%d", &choice);

    if (choice == 0) {
      printf("Сподіваюсь більше не пригожусь)\n");
      break;
    } else if (choice == 1) {
      int rows, cols;

      printf("Введіть кількість рядків: ");
      scanf("%d", &rows);
      printf("Введіть кількість стовпців: ");
      scanf("%d", &cols);

      if (rows <= 0 || cols <= 0) {
        printf("Кількість рядків та стовпців повинна бути більше нуля.\n");
        continue;
      }
      int matrix[rows][cols];
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          matrix[i][j] = (rand() % 201) -
                         100; // Генерація випадкових чисел від -100 до 100
        }
      }

      // Функція гарного виводу матриці
      printf("Матриця:\n");
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          printf("%5d ", matrix[i][j]); // Вирівнювання по ширині
        }
        printf("\n");
      }

    } else if (choice == 2) {
      int n;

      printf("Введіть розмірність квадратної матриці: ");
      scanf("%d", &n);

      if (n <= 0) {
        printf("Розмірність матриці повинна бути більше нуля.\n");
        continue;
      }

      int matrix[n][n];

      printf("Введіть елементи матриці:\n");
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          printf("matrix[%d][%d]: ", i, j);
          scanf("%d", &matrix[i][j]);
        }
      }

      // Функція гарного виводу матриці
      printf("Матриця:\n");
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          printf("%5d ", matrix[i][j]); // Вирівнювання по ширині
        }
        printf("\n");
      }

      int min_above_secondary = matrix[0][0]; // початкове значення мінімуму
      int found = 0; // Флаг, чи знайдено хоч один елемент вище бічної діагоналі
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) { // i + j < n - 1
          if (!found) {
            min_above_secondary = matrix[i][j];
            found = 1;
          }
          if (matrix[i][j] < min_above_secondary) {
            min_above_secondary = matrix[i][j];
          }
        }
      }

      if (!found) {
        printf("Немає елементів вище бічної діагоналі.\n");
      } else {
        printf("Мінімальний елемент вище бічної діагоналі: %d\n",
               min_above_secondary);
      }
    } else {
      printf("Невірний вибір. Спробуйте ще раз.\n");
    }
  }

  return 0;
}
