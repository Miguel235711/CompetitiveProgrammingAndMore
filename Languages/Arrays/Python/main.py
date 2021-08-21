lim=10
def main():
    arr=[10]*lim
    print(arr)
    arr.append(3)
    print(arr)
    arr[3]=5
    print(arr)
    arr.pop(3)
    print(arr)
    arr.remove(3)
    print(arr)
    for a in arr:
        print(a,end=' ')
    print()
main()