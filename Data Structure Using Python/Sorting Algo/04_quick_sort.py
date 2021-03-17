def print_list(arr, n):
    for val in range(0, n):
        print(arr[val], end=" ")
    print()


# Taking high as pivot
def partition(arr, low, high):
    pivot = arr[high]
    i = low-1
    j = low
    for num in range(low, high):
        if arr[num] <= pivot:
            i = i+1
            arr[i], arr[num] = arr[num], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1


def quick_sort(arr, low, high):
    if low < high:
        partionIndex = partition(arr, low, high)
        quick_sort(arr, low, partionIndex-1)
        quick_sort(arr, partionIndex+1, high)


new_list = list()
size = int(input("Enter the size of the array: "))
print(f"Enter the {size} numbers into the array")

for number in range(0, size):
    x1 = int(input())
    new_list.append(x1)

print_list(new_list, size)
# print(new_list)
quick_sort(new_list, 0, size-1)
print_list(new_list, size)
# print(new_list)
