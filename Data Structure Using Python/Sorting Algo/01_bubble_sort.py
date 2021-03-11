def print_list(arr, n):
    for val in range(0, n):
        print(arr[val], end=" ")
    print()


def bubble_sort(new_list1, n):
    for num in range(0, n-1):
        for z in range(0, n-num-1):
            if new_list1[z] > new_list1[z+1]:
                new_list1[z], new_list1[z+1] = new_list1[z+1], new_list1[z]


new_list = list()
size = int(input("Enter the size of the array: "))
print(f"Enter the {size} numbers into the array")

for number in range(0, size):
    x1 = int(input())
    new_list.append(x1)

print_list(new_list, size)
# print(new_list)
bubble_sort(new_list, size)
print_list(new_list, size)
# print(new_list)
