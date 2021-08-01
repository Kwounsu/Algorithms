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
