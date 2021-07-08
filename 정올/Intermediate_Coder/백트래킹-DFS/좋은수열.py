import sys


def dfs(length):
    for i in range(1, length // 2 + 1):
        if ans[-2 * i:-i] == ans[-i:]: 
            return 1

    if length == n:
        return 0
 
    for i in range(1, 4):
        ans.append(i)
        if dfs(length + 1) == 0:
            return 0
        ans.pop()


n = int(sys.stdin.readline())
ans = []
dfs(0)
print(*ans, sep='')
