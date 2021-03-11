#include <stdio.h>
#include <stdlib.h>

void setValue(int *arr, int n)
{
    printf("Enter the values into the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int choose()
{
    int ch;
    printf("\nChoose from the below menu: \n");
    printf("0. Quit from the program\n");
    printf("1. Traverse the array\n");
    printf("2. Insert an element in the array\n");
    printf("3. Delete an element from the array\n");
    printf("4. To search an element in the array\n");
    printf("------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    return ch;
}

void traverse(int *a, int n)
{
    printf("The values you entered in the array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertion(int *arr, int c, int *n)
{
    int index, element;
    printf("Enter the index value where you want to enter the number: ");
    scanf("%d", &index);

    printf("Enter the element you want to insert: ");
    scanf("%d", &element);

    if ((*n) >= c)
    {
        printf("The array size is exhausted.\n");
        return;
    }

    for (int i = (*n); i >= index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    (*n) = (*n) + 1;

    return;
}

void search(int *arr, int num)
{
    int val, res = 0;
    printf("Enter the value you want to found in the array: ");
    scanf("%d", &val);

    for (int i = 0; i < num; i++)
    {
        if (arr[i] == val)
        {
            res = i + 1;
        }
        
    }
    if (res != 0)
    {
        printf("The number %d is found at loacation %d\n", val, res);
    }
    else
    {
        printf("The number you entered is not present in the array\n");
    }

}

void delete (int *arr, int *n)
{
    int index;
    printf("Enter the index value which you want to delete: ");
    scanf("%d", &index);

    for (int i = index + 1; i < (*n); i++)
    {
        arr[i - 1] = arr[i];
    }
    (*n) = (*n) - 1;
}

int main()
{
    int capacity, ch;
    printf("Enter the capacity of the array you want to create: ");
    scanf("%d", &capacity);

    int arr[capacity], num;
    printf("Enter the no of elements in the array: ");
    scanf("%d", &num);

    setValue(arr, num);

    ch = choose();

    while (1)
    {
        switch (ch)
        {
        case 0:
            exit(0);

        case 1:
            traverse(arr, num);
            // ch = choose();
            break;
        case 2:
            insertion(arr, capacity, &num);
            // ch = choose();
            break;
        case 3:
            delete (arr, &num);
            // ch = choose();
            break;
        case 4:
            search (arr, num);
            break;
        }
        ch = choose();
    }

    // setValue(arr, num);
    // traverse(arr, num);

    // int i = insertion(arr, capacity, &num);

    // if (i == 0)
    // {
    //     traverse(arr, num);
    // }
    // else
    // {
    //     printf("The size of the array is exhausted: \n");
    // }

    // delete (arr, &num);
    // traverse(arr, num);

    return 0;
}