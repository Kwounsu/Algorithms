def quick_sort(a):
    def sort(low, high):
        if low >= high:
            return
        mid = partition(low, high)
        sort(low, mid - 1)
        sort(mid, high)
        
    def partition(low, high):
        pivot = a[(low + high) // 2]
        while low <= high:
            while a[low] < pivot:
                low += 1
            while a[high] > pivot:
                high -= 1
            if low <= high:
                a[low], a[high] = a[high], a[low]
                low, high = low + 1, high - 1
        return low
    
    sort(0, len(a) - 1)
