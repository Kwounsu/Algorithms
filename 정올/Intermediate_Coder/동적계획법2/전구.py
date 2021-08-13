import sys
input = sys.stdin.readline


n = int(input())
switch = list(map(int, input().split()))
light = list(map(int, input().split()))
index = [light.index(switch[i]) for i in range(n)]

dp = [index[0]]
tmp = [[0, index[0]]]
for i in range(1, n):
    if dp[-1] < index[i]:
        dp.append(index[i])
        tmp.append([len(dp)-1, index[i]])
    else:
        new_pos = bisect.bisect_left(dp, index[i])
        dp[new_pos] = index[i]
        tmp.append([new_pos, index[i]])

ans = deque()
current_pos = len(dp) - 1
for i in range(n-1, -1, -1):
    p, x = tmp[i]
    if p == current_pos:
        ans.appendleft(x)
        current_pos -= 1
        if current_pos < 0:
            break
 
print_ans = [light[x] for x in ans]
print_ans.sort()
print(len(print_ans))
print(' '.join(map(str, print_ans)))
