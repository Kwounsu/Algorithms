def LIS(arr):
    DP = [1] * n
    for i in range(n):
        for j in range(i):
            if (arr[j] < arr[i] and DP[j] + 1 > DP[i]):
                DP[i] = DP[j] + 1
    return max(DP)


n=int(input())
L = [int(input()) for _ in range(n)]
print(n - LIS(L))
