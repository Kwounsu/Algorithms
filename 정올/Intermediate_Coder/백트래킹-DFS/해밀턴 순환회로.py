import sys
input = sys.stdin.readline
 
def dfs(step, city, cost):
    if cost >= answer[0]:
        return
    if step == N - 1:
        if costs[city][0] != 0 and cost + costs[city][0] < answer[0]:
            answer[0] = cost + costs[city][0]
        return
     
    for i in range(1, N):
        if not visited[i] and costs[city][i] != 0:
            visited[i] = True
            dfs(step + 1, i, cost + costs[city][i])
            visited[i] = False
 
 
N = int(input())
costs = []
for _ in range(N):
    costs.append(list(map(int, input().split())))
 
visited = [False] * N;
visited[0] = True
 
answer = [float('inf')]
 
dfs(0, 0, 0)
print(answer[0])
