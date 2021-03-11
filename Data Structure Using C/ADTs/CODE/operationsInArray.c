#include <stdio.h>

void setValue(int *arr, int n)
{
    printf("Enter the values into the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
}

void traverse (int *a, int n)
{
    printf("The values you entered in the array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int insertion(int *arr, int c, int *n)
{
    int index, element;
    printf("Enter the index value where you want to enter the number: ");
    scanf("%d", &index);
    
    printf("Enter the element you want to insert: ");
    scanf("%d", &element);

    if ((*n) >= c)
    {
        return -1;
    }
    
    for (int i = (*n); i >= index; i--)
    {
        arr[i] = arr[i-1]; 
    }
    arr[index] = element;
    (*n) = (*n) + 1;

    return 0;
}

void delete(int *arr, int *n)
{
    int index;
    printf("Enter the index value which you want to delete: ");
    scanf("%d", &index);

    for (int i = index + 1; i < (*n); i++)
    {
        arr[i-1] = arr[i];
    }
    (*n) = (*n) - 1;
}

int main()
{   
    int capacity;
    printf("Enter the capacity of the array you want to create: ");
    scanf("%d", &capacity);
    
    int arr[capacity], num;
    printf("Enter the no of elements in the array: ");
    scanf("%d", &num);

    setValue(arr, num);
    traverse(arr, num);

    int i = insertion(arr, capacity, &num);

    if (i == 0)
    {
        traverse(arr, num);
    }
    else
    {
        printf("The size of the array is exhausted: \n");
    }
    
    delete(arr, &num);
    traverse(arr, num);
    
    return 0;
}