#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *) malloc(tSize * sizeof(int));

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *) malloc(tSize * sizeof(int));
}

void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    { 
        printf("Enter the value of the element %d: ", i + 1);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
    
}

void showArray(struct myArray *a)
{
    printf("The values in the array are: \n");
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d) %d\n",i + 1, (a->ptr)[i]);
    }
    
}

int main()
{
    struct myArray marks;
    int m, n;
    printf("Enter the total size of the array: ");
    scanf("%d", &m);
    printf("Enter the used size of the array: ");
    scanf("%d", &n);

    createArray(&marks, m, n);
    setVal(&marks);
    showArray(&marks);

    return 0;
}