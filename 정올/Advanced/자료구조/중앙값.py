import sys, heapq as hq
input = sys.stdin.readline


n = int(input())
m = int(input())
print(m)
ltree, rtree = [], []

for _ in range((n-1)//2):
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a
    if a <= m and m <= b:
        hq.heappush(ltree, -a)
        hq.heappush(rtree, b)
    elif a > m:
        hq.heappush(ltree, -m)
        hq.heappush(rtree, a)
        hq.heappush(rtree, b)
        m = hq.heappop(rtree)
    elif b < m:
        hq.heappush(ltree, -a)
        hq.heappush(ltree, -b)
        hq.heappush(rtree, m)
        m = -hq.heappop(ltree)
    print(m)
