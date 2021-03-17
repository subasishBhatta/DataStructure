def print_list(arr, n):
    for val in range(0, n):
        print(arr[val], end=" ")
    print()


def selection_sort(arr, n):
    for i in range(0, n-1):
        mini = i
        for j in range(i+1, n):
            if arr[j] < arr[mini]:
                mini = j
        arr[i], arr[mini] = arr[mini], arr[i]


new_list = list()
size = int(input("Enter the size of the array: "))
print(f"Enter the {size} numbers into the array")

for number in range(0, size):
    x1 = int(input())
    new_list.append(x1)

print_list(new_list, size)
# print(new_list)
selection_sort(new_list, size)
print_list(new_list, size)
# print(new_list)

