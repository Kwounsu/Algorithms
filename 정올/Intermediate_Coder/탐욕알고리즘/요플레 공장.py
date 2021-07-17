def solution(n, s, c, y):
    total = c[0] * y[0]
    bestprice = c[0]
    for i in range(1, n):
        bestprice = min(bestprice + s, c[i])
        total += bestprice * y[i]
    return total

n, s = map(int, input().split())
c = [0 for _ in range(n)]
y = [0 for _ in range(n)]

for i in range(n):
    c[i], y[i] = map(int, input().split())
 
print(solution(n, s, c, y))
