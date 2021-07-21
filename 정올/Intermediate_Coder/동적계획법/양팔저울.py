"""
 i번째의 무게추를 
1.저울에 올릴 것인지, 
2.구슬 쪽 저울에 올릴 것인지, 
3.아무것도 하지 않을 것인지
"""

n = int(input())
weights = list(map(int, input().split()))
g = int(input())
marbles = list(map(int, input().split()))

dp1 = [0] * 50000
dp2 = [0] * 50000
dp1[0] = dp2[0] = 1

m = 0
for w in weights:
    m += w
    for j in range(m + 1):
        if dp1[j] == 1:
            dp2[abs(j - w)] = 1 # 반대편 저울에 올리기
            dp2[w + j] = 1      # 구슬쪽 저울에 올리기
    for j in range(m + 1):
        dp1[j] = dp2[j]

for marble in marbles:
    if dp1[marble]: 
        print("Y", end=' ')
    else: 
        print("N", end=' ')
