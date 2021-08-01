import sys, heapq
input = sys.stdin.readline


n = int(input())
a = list(map(int, input().split()))
heapq.heapify(a)

cost = 0
for i in range(1, len(a)):
    x = heapq.heappop(a)
    x += heapq.heappop(a)
    heapq.heappush(a, x)
    cost += x

print(cost)
