def LIS(arr):
    DP = [1] * n
    for i in range(1, n):   # 1부터 시작 (j반복문이 i앞까지 탐색하기에 0은 아무것도 안함)
        for j in range(i):  # 0부터 i 전까지 검사
            if (arr[j] < arr[i] and DP[j] + 1 > DP[i]):  # arr[j]가 arr[i]보다 작고(순서에 맞고), 
                DP[i] = DP[j] + 1
    return max(DP)


n=int(input())
L = [int(input()) for _ in range(n)]
print(n - LIS(L))
