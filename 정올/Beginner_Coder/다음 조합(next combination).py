import sys
from itertools import combinations
input = sys.stdin.readline

N, M = map(int, input().split())
NUM = list(map(int, input().split()))

flag = 0
c = combinations(range(1, N + 1), M)
for x in c:
    if flag == 1:
        print(*x)
        flag = 2
        break
    if sorted(x) == sorted(NUM):
        flag = 1

if flag < 2:
    print("NONE")
