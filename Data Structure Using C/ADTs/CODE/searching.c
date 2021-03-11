#include <stdio.h>

int linear(int *arr, int val, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        if (arr[i] == val)
        {
            return i + 1;
        }
        
    }
    return -1;
}

int binary(int *arr, int val, int num)
{
    int low = 0, high = num - 1, mid;
    while ((low <= high))
    {
        mid = (low + high) / 2;
        if(arr[mid] == val)
        {
            return mid+1;
        }
        else if (arr[mid] > val)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
         
    }
    return -1;
}

int main()
{
    int capacity, ch, val, res;
    printf("Enter the capacity of the array you want to create: ");
    scanf("%d", &capacity);

    int arr[capacity], num;
    printf("Enter the no of elements in the array: ");
    scanf("%d", &num);
    
    printf("Enter the values into the array: \n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The values you entered into the array are: \n");
    for (int i = 0; i < num; i++)
    {
        printf("%d) %d\n", i+1, arr[i]);
    }
    

    printf("Enter the value you want to found in the array: ");
    scanf("%d", &val);

    printf("---------------------------------------------------\n");
    printf("This is a searching menu...\n");
    printf("If the array you entered is sorted then go for binary otherwise stick to linear\n");
    printf("1. For linear search\n");
    printf("2. For Binary search\n");

    printf("Enter your choice: ");
    scanf("%d", &ch);

    if (ch == 1)
    {   
        res = linear(arr, val, num);
    }
    else
    {
        res = binary(arr, val, num);
    }

    if (res != -1)
    {
        printf("The element is found at the location %d\n", res);
    }
    else
    {
        printf("The element you entered is not found!!!\n");
    }
    
    

    return 0;
}