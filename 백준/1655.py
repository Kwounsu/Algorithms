import sys,heapq as hq
l,r = [],[]
t=int(sys.stdin.readline())
for _ in range(t):
    x = int(sys.stdin.readline())
    if len(l)==len(r):
        hq.heappush(l, (-x,x))
    else:
        hq.heappush(r, (x,x))

    if r and l[0][1] > r[0][1]:
        a,b = hq.heappop(l)[1],hq.heappop(r)[1]
        hq.heappush(l,(-b,b))
        hq.heappush(r,(a,a))
    print(l[0][1])
