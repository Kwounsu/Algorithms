n, w = map(int, input().split())
jewels = sorted([list(map(int, input().split())) for _ in range(n)])

d = [0] * 10001

for i in range(1, w+1):
    m = 0
    for weight, value in jewels:
        if i < weight:
            break
        m = max(m, d[i - weight] + value)
    d[i] = m

print(d[w])
