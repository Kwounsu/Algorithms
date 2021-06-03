import sys
input = sys.stdin.readline
from collections import deque

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    priorities = list(map(int, input().split()))
    q = deque([(i, p) for i, p in enumerate(priorities)])
    priorities.sort()

    count = 0
    while q:
        cur = q.popleft()
        if cur[1] == priorities[-1]:
            count += 1
            if cur[0] == m:
                break
            priorities.pop()
        else:
            q.append(cur)
    print(count)
        
