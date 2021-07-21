"""
a일째 되는 날부터, 짚신벌레는 a일 전 개체수만큼 증가한다.
dp[k] = dp[k - 1] + dp[k - a]이다. (단, k >= a)

최초 개체가 증식을 멈추기 시작하는 b일째부터 b일 전 개체수만큼 증식을 멈춘다.
dp[k] = dp[k - 1] + dp[k - a] - dp[k - b]이다. (단, k >= b)
"""

a, b, d, N = map(int, input().split())

# a일 전까지
dp = [1] * a + [0] * (N + 1 - a)

# a일 이후, 그리고 b일부터 b일전 개체수 만큼 증식 멈추기
for i in range(a, N + 1):
    dp[i] = (dp[i - 1] + dp[i - a]) % 1000
    if i >= b: dp[i] -= dp[i - b]

if N >= d:
    # 죽이기
    print((dp[N] - dp[N - d]) % 1000)
else:
    print(dp[N])
