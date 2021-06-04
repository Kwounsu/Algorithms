def selection_sort(a):
    for i in range(len(a)):
        min_index, min_val = i, a[i]
        for j in range(i, len(a)):
            if a[min_index] > a[j]:
                min_index = j
        a[i], a[min_index] = a[min_index], a[i]
