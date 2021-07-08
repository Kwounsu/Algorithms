import sys
 

def dfs(length):
    for i in range(1, length // 2 + 1):
        if ans[-2 * i:-i] == ans[-i:]: 
            return
 
    if length == n:
        print(*ans, sep='')
        sys.exit(0)
  
    for i in range(1, 4):
        ans.append(i)
        dfs(length + 1)
        ans.pop()
 
 
n = int(sys.stdin.readline())
ans = []
dfs(0)
