import sys
input = sys.stdin.readline
from collections import deque


def front(arr, target):
    count = 0
    for i in arr:
        if i == target:
            return count
        count += 1
    return -1
    

n, m = map(int, input().split())
a = deque(list(map(int, input().split())))

q = deque(list(range(1, n + 1)))

answer = 0
while a:
    loc = front(q, a[0])
    if loc == 0:
        q.popleft()
        a.popleft()
    elif loc <= len(q) / 2:
        q.append(q.popleft())
        answer += 1
    else:
        q.appendleft(q.pop())
        answer += 1
    
print(answer)
