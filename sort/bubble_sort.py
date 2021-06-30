
def bubble_sort(a):
    for i in range(len(a) - 1, 1, -1):
        for j in range(i):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
