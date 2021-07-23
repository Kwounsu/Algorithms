n = int(input())
# block = [번호, 밑면의넓이, 높이, 무게]
block = sorted([[i] + list(map(int, input().split())) for i in range(1, n+1)],
                key=lambda x:x[1], reverse=True)  # 넓이 내림차순 정렬

# 높이 저장
dp = [block[i][2] for i in range(n)]

for i in range(1, n):
    for j in range(i):
        if block[i][3] < block[j][3]:  # 무게 비교
            dp[i] = max(dp[i], dp[j] + block[i][2])

# 가장 높은 탑 쌓은 dp 탐색
max_height = max(dp)
mh_i = dp.index(max_height)

# 탑 번호 높이를 토대로 역산
ans = []
while mh_i >= 0:
    if dp[mh_i] == max_height:
        ans.append(block[mh_i][0])
        max_height -= block[mh_i][2]
    mh_i -= 1

# 벽돌 수와 각 번호 출력
print(len(ans))
print(*ans, sep='\n')
