#include <stdio.h>
#include <stdlib.h>

int *GetMatrix(int *row, int *col);
int *GetMatrix(int *row, int *col) {
    int m, n;
    int *data_matrix;

    printf("Enter number of rows (m): ");
    if (scanf("%d", &m) != 1) {
        *row = 0;
        *col = 0;
        return NULL;
    }
    
    printf("Enter number of columns (n): ");
    if (scanf("%d", &n) != 1) {
        *row = 0;
        *col = 0;
        return NULL;
    }

    if (m <= 0 || n <= 0) {
        *row = 0;
        *col = 0;
        return NULL;
    }

    *row = m;
    *col = n;

    int total_elements = m * n;
    
    data_matrix = (int *)malloc(total_elements * sizeof(int));
    
    if (data_matrix == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        *row = 0;
        *col = 0;
        return NULL;
    }

    printf("Enter %d elements (Row-Major):\n", total_elements);
    for (int i = 0; i < total_elements; i++) {
        printf("Element [%d]: ", i + 1);
        if (scanf("%d", &data_matrix[i]) != 1) {
            free(data_matrix);
            *row = 0;
            *col = 0;
            return NULL;
        }
    }

    return data_matrix;
}

int main() {
    int *data, m, n;
    data = GetMatrix(&m, &n);
    
    printf("\n--- Result ---\n");
    if (data == NULL) {
        printf("Matrix creation failed or invalid dimensions.\n");
    } else {
        printf("Matrix size: %d rows x %d cols\n", m, n);
        printf("Elements (Row-Major):\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d\t", data[i * n + j]); 
            }
            printf("\n");
        }
        
        free(data);
    }

    
    return 0;
}