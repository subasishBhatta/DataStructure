def print_list(arr, n):
    for val in range(0, n):
        print(arr[val], end=" ")
    print()


# Logic for Insertion sort
def insertion_sort(new_list1, n):
    for num in range(1, n):
        key = new_list1[num]
        j = num-1
        while new_list1[j] > key and j >= 0:
            new_list1[j+1] = new_list1[j]
            j = j-1
        new_list1[j+1] = key


new_list = list()
size = int(input("Enter the size of the array: "))
print(f"Enter the {size} numbers into the array")

for number in range(0, size):
    x1 = int(input())
    new_list.append(x1)

print_list(new_list, size)
# print(new_list)
insertion_sort(new_list, size)
print_list(new_list, size)
# print(new_list)
