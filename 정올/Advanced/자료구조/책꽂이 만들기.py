import sys, heapq as hq
input = sys.stdin.readline


n = int(input())
a = []
for _ in range(n):
    hq.heappush(a, int(input()))

n -= 1
cost = 0
while n:
    x = hq.heappop(a)
    x += hq.heappop(a)
    cost += x
    hq.heappush(a, x)
    n-=1

print(cost)


"""
from queue import PriorityQueue as pq
import sys
input = sys.stdin.readline


pq = pq()
n = int(input())
for _ in range(n):
    pq.put(int(input()))

cost = 0
while pq.qsize() > 1:
    x = pq.get() + pq.get()
    cost += x
    pq.put(x)
 
print(cost)
"""
