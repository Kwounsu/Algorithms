"""
합의 법칙 -> 두 사건이 동시에 일어나지 않을 경우 더한다.
곱의 법칙 -> 두 사건이 동시에 일어날 경우 곱한다.
  
1. 좌석을 옮기지 않는 경우 -> dp[n-1]
2. 좌석을 옮기는 경우 -> dp[n-2]
dp[n] = dp[n-1] + dp[n-2]
"""
  
n = int(input())
m = int(input())
  
dp = [1, 1, 2]
for i in range(3, n + 1):
    dp.append(dp[i-1] + dp[i-2])
  
ans = 1

# ans = [0~fix1] * [fix1~fix2] * [fix2~n+1]
if m > 0:
    pre = 0
    for _ in range(m):
        fixed_seat = int(input())
        ans *= dp[fixed_seat - pre - 1]
        pre = fixed_seat
    ans *= dp[n-fixed_seat]
else:
    ans = dp[n]
  
print(ans)
