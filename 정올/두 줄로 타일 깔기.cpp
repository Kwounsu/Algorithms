# 재귀

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def dp(x):
    if x==1: return 1
    if x==2: return 3
    if d[x] == 0:
        d[x] = (dp(x-1) + 2 * dp(x-2)) % 20100529
    return d[x]


n = int(input())
d = [0] * (n+1)
print(dp(n))


# for문          
          
import sys
input = sys.stdin.readline


n = int(input())
if n == 1: print(1)
elif n == 2: print(3)
else:
    a, b = 1, 3
    for _ in range(n-2):
        a, b = b, (a*2 + b) % 20100529
    print(b)
