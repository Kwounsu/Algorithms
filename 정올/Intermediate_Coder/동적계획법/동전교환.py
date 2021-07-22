n = int(input())
coin = list(map(int, input().split()))
w = int(input())

d = [-1] * (w + 1)
for c in coin:
    d[c] = 1

for i in range(1, w + 1):
    for c in coin:
        if c <= i and d[i - c] != -1:
            if d[i] != -1:
                d[i] = min(d[i], d[i - c] + 1)
            else:
                d[i] = d[i - c] + 1

if d[w] == -1:
    print("impossible")
else:
    print(d[w])
