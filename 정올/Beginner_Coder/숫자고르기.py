import sys
read = sys.stdin.readline


n = int(read())
a = [0]

for _ in range(n):
    a.append(int(read()))

answer = []
    
for i in range(1, n + 1):
    visited = []
    q = [i]
    while q:
        cur = q.pop()
        if cur not in visited:
            visited.append(cur)
            q.append(a[cur])
    if visited[0] == a[visited[-1]]:
        answer.extend(visited)

answer = sorted(set(answer))
print(len(answer))
print(*answer, sep='\n')
