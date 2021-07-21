from sys import stdin
input = stdin.readline
 
n, m = map(int, input().split())
A = list(map(int, input().split()))
C = list(map(int, input().split()))
dp = [0] * 10001
sum_ = sum(C)
 
for i in range(n):
    for j in range(sum_, C[i] - 1, -1):
        dp[j] = max(dp[j], dp[j - C[i]] + A[i])
 
# n번의 앱까지 모든 탐색을 끝냈을 때 
# dp[j]의 값은 j의 비용으로 얻을 수 있는 최대의 메모리 크기.

# 사용할 수 있는 j의 비용이 늘어날수록 
# 얻을 수 있는 메모리도 늘어날 텐데 
# 처음으로 m을 넘는 j값이 바로 이 문제의 정답
cost = 0
while cost < sum_ and dp[cost] < m:
    cost += 1
 
print(cost)
