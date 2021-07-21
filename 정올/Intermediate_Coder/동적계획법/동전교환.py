def solution(w):
    for i in range(coin[len(coin) - 1], w + 1):
        m = float('inf')
        for j in coin:
            if d[i - j] == 0:
                continue
            if m > d[i - j] + 1:
                    m = d[i - j] + 1
        if m != float('inf'):
            d[i] = m
    if d[w] == 0:
        return "impossible"
    else:
        return d[w]
 
   
n = int(input().strip())
coin = sorted(list(map(int, input().split())))
w = int(input().strip())

d = [0] * (w + 1)
for c in coin:
    d[c] = 1

print(solution(w))
