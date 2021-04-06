import sys
r = sys.stdin.readline


s1 = r().rstrip()
s2 = r().rstrip()

# s1: 더 짧은 문자열
if len(s1) > len(s2):
    s1, s2 = s2, s1

dp = [0] * (len(s2) + 1)

for i in range(len(s1) - 1, -1, -1):
    for j in range(len(s2)):
        if s1[i] == s2[j]:
            dp[j] = max(dp[j + 1:]) + 1

print(max(dp))
