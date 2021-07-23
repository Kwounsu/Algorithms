n = int(input())
switch = list(map(int, input().split()))
light = list(map(int, input().split()))

dp = [1] * n
for i in range(1, n):
    for j in range(i):
        if (light.index(switch[i]) > light.index(switch[j])):
            dp[i] = max(dp[i], dp[j] + 1)

# 전구가 켜지게 하는 최대 스위치 수
ans = max(dp)
print(ans)

# 스위치 번호를 구하기 위한 LIS추적
idx = dp.index(ans)
nums = []
while idx >= 0:
    if dp[idx] == ans:
        nums.append(switch[idx])
        ans -= 1
    idx -= 1
print(*nums)
