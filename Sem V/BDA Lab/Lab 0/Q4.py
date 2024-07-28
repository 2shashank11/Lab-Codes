def binary_search(a, key):
    low = 0
    high = len(a) - 1

    while low <= high:
        mid = (low + high) // 2
        
        if a[mid] == key:
            return mid
        elif a[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1

a = eval(input("Enter a list: "))
value = int(input("Enter a value to search: "))

index = binary_search(a, value)

if index != -1:
    print(f"Value '{value}' found at index {index}")
else:
    print(f"Value '{value}' not found in the list")