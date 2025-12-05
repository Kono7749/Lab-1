#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int value[], int *row, int *col);

void GetMatrix(int value[], int *row, int *col) {
    int m, n;
    
    printf("Enter number of rows (m): ");
    if (scanf("%d", &m) != 1) {
        *row = 0;
        *col = 0;
        return;
    }
    *row = m;

    printf("Enter number of columns (n): ");
    if (scanf("%d", &n) != 1) {
        *row = 0;
        *col = 0;
        return;
    }
    *col = n;

    if (m <= 0 || n <= 0) {
        *row = 0;
        *col = 0;
        return;
    }

    int total_elements = m * n;
    
    printf("Enter %d elements (Row-Major):\n", total_elements);
    for (int i = 0; i < total_elements; i++) {
        printf("Element [%d]: ", i + 1);
        if (scanf("%d", &value[i]) != 1) {
            *row = 0;
            *col = 0;
            return;
        }
    }
}

int main() {
    int *data;
    int m, n;
    
    printf("Reading dimensions first...\n");
    printf("Enter number of rows (m): ");
    if (scanf("%d", &m) != 1) return 1;
    printf("Enter number of columns (n): ");
    if (scanf("%d", &n) != 1) return 1;

    if (m <= 0 || n <= 0) {
        printf("Invalid dimensions.\n");
        return 0;
    }

    data = (int *)malloc(m * n * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    
    printf("\nCalling GetMatrix to fill data...\n");
    
    void ReadData(int value[], int m, int n);
    ReadData(data, m, n);
    
    printf("\n--- Result ---\n");
    printf("Matrix size: %d rows x %d cols\n", m, n);
    printf("Elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", data[i * n + j]);
        }
        printf("\n");
    }
    
    free(data);
    return 0;
}

void ReadData(int value[], int m, int n) {
    int total_elements = m * n;
    printf("Enter %d elements (Row-Major):\n", total_elements);
    for (int i = 0; i < total_elements; i++) {
        printf("Element [%d]: ", i + 1);
        scanf("%d", &value[i]);
    }
}