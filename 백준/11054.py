import sys, bisect
input = sys.stdin.readline


N = int(input())
a = list(map(int,input().split()))
dp_asc = [0] * N
dp_desc = [0] * N

def set_dp(s, e, d, arr):
    tmp = [a[s]]
    l = 0
    
    for i in range(s + d, e, d):
        if tmp[-1] < a[i]:
            tmp.append(a[i])
            l += 1
            arr[i] = l
        else:
            j = bisect.bisect_left(tmp, a[i])
            tmp[j] = a[i]
            arr[i] = j
        
set_dp(0, N, 1, dp_asc)
set_dp(N - 1, -1, -1, dp_desc)

print(max(map(sum, zip(dp_asc, dp_desc))) + 1)
