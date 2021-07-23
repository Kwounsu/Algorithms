import sys
input = sys.stdin.readline


len1 = int(input())
str1 = input().strip()
len2 = int(input())
str2 = input().strip()

dp = [[0] * 1001 for _ in range(1001)]

for i in range(1, len1+1):
    for j in range(1, len2+1):
        if str1[i-1] == str2[j-1]:
            dp[i][j] = dp[i-1][j-1] + 3
        else:  # 음수면 0으로 초기화
            dp[i][j] = max(0, dp[i-1][j-1] - 2, dp[i][j-1] - 2, dp[i-1][j] - 2)

# dp[i][j] 최대값 찾기
ans = max([max(x) for x in dp])
print(ans)

# dp[i][j] 최대값 위치 찾기 (DNA문자 마지막 위치)
for i, x in enumerate(dp):
    if ans in x:
        e_i, e_j = i, x.index(ans)

s_i, s_j = e_i, e_j
# 역추적 - 시작점 찾기
while dp[s_i][s_j] != 0:
    if dp[s_i-1][s_j] == dp[s_i][s_j] + 2:
        s_i -= 1
    elif dp[s_i][s_j-1] == dp[s_i][s_j] + 2:
        s_j -= 1
    else:
        s_i -= 1
        s_j -= 1

# 문장 출력
print(str1[s_i:e_i])
print(str2[s_j:e_j])
