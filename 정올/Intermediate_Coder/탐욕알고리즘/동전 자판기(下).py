import sys
input = sys.stdin.readline


w = int(input())
coin = [500, 100, 50, 10, 5, 1]
wallet = list(map(int, input().split()))
ans = [0] * 6
ans_cnt = 0
 
for i in range(5, -1, -1):
    if wallet[i] == 0: continue
    
    j = i - 1
    while j >= 0 and not wallet[j]:
        j -= 1
    if j < 0: j = i
 
    for k in range(wallet[i], -1, -1):
        x = w - k * coin[i]
        if x < 0:
            continue
        if x % coin[j] == 0 or x == 0:
            ans[i] = k
            ans_cnt += k
            w = x
            break
 
    if w == 0: break
 
print(ans_cnt)
print(*ans)
