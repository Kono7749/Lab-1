#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *size_ptr);
int *GetSet(int *size_ptr){
    int size;
    int *data_set;

    printf("Enter the number of elements in the set: ");
    if (scanf("%d", &size) != 1){
        *size_ptr = 0;
        return NULL;
    }

*size_ptr = size;

if (size <= 0)
{
    return NULL;
}

data_set = (int *)malloc(size * sizeof(int));
if (data_set == NULL)
{
    fprintf(stderr, "Memory allocation failed.\n");
    *size_ptr = 0;
    return NULL;
}

printf("Enter %d elements:\n", size);
for (int i = 0; i < size; i++)
{
    printf("Element %d: ", i + 1);
    if (scanf("%d", &data_set[i]) != 1)
    {
        free(data_set);
        *size_ptr = 0;
        return NULL;
    }
}

return data_set;
}
    int main(){
        int *data;
        int num;

        data = GetSet(&num);

        printf("\n--- Result ---\n");
        if (data == NULL){
            printf("Set creation failed or size is 0.\n");
        } else {
            printf("Set size (num): %d\n", num);
            printf("Set elements: ");
            for (int i = 0; i < num; i++)
            {
                printf("%d ", data[i]);
            }
            printf("\n");
            free(data);
        }
        return 0;
    }

