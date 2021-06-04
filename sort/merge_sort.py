def merge_sort(a):
    def sort(low, high):
        if high - low < 2:
            return
        mid = (low + high) // 2
        sort(low, mid)
        sort(mid, high)
        merge(low, mid, high)
        
    def merge(low, mid, high):
        tmp = []
        l, h = low, mid
        
        while l < mid and h < high:
            if a[l] < a[h]:
                tmp.append(a[l])
                l += 1
            else:
                tmp.append(a[h])
                h += 1
                
        for i in range(l, mid):
            tmp.append(a[i])
        for i in range(h, high):
            tmp.append(a[i])
        
        for i in range(low, high):
            a[i] = tmp[i - low]
        
    sort(0, len(a))
