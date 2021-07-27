import sys
from collections import defaultdict
input = sys.stdin.readline


n = int(input())
votes = defaultdict(list)
scores = [0, 0, 0, 0]
for _ in range(n):
    a, b, c = map(int, input().split())
    votes[1].append(a)
    votes[2].append(b)
    votes[3].append(c)
    scores[1] += a
    scores[2] += b
    scores[3] += c

# 후보군
indices = []

# 점수만 가지고 비교
top_score = max(scores)
for i in range(1, 4):
    if scores[i] == top_score:
        indices.append(i)

if len(indices) == 1:
    print(indices[0], top_score)
else:
    for i in indices:
        votes[i].sort(reverse=True)

    president = [0, 0, 0, 0]
    target = 3
    i = 0
    while i < n:
        flag = True
        for j in indices:
            if votes[j][i] == target:
                president[j] += target
                flag = False
        # 탈락 후보군 배제
        top = max(president)
        for j in indices:
            if president[j] < top:
                indices.remove(j)
        # 다음 높은 점수 투표 계산시작
        if flag and target > 0:
            target -= 1
        else:
            i += 1

    if len(indices) == 1:
        print(indices[0], max(president))
    else:
        print(0, max(president))
