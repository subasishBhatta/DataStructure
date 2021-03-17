def print_list(arr, n):
    for val in range(0, n):
        print(arr[val], end=" ")
    print()


def merge_sort(arr):
    # This is the recursion end condition
    if len(arr) > 1:
        # Inorder to divide the array we find the middle element
        mid = len(arr)//2

        # Creating two lists which contain the left and right part of the main list
        left = arr[:mid]
        right = arr[mid:]

        # Recursive calling on both left and right list
        merge_sort(left)
        merge_sort(right)

        # Comparing the elements of the left list and right list and merge them into main list
        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
                k += 1
            else:
                arr[k] = right[j]
                j += 1
                k += 1

        # Checking which list still have some elements left in it add them to the main list
        while i < len(left):
            arr[k] = left[i]
            k += 1
            i += 1

        while j < len(right):
            arr[k] = right[j]
            k += 1
            j += 1


if __name__ == '__main__':
    new_list = list()
    size = int(input("Enter the size of the array: "))
    print(f"Enter the {size} numbers into the array")

    for number in range(0, size):
        x1 = int(input())
        new_list.append(x1)

    print_list(new_list, size)
    # print(new_list)
    merge_sort(new_list)
    print_list(new_list, size)
    # print(new_list)
