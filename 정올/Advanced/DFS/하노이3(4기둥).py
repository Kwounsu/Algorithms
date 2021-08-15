def hanoi3(n, s, a, e):
    if n <= 0:
        return
    hanoi3(n-1, s, e, a)
    print(f"{n} : {chr(s+64)} -> {chr(e+64)}")
    hanoi3(n-1, a, s, e)

def hanoi4(n, s, a, b, e):
    if n <= 0:
        return
    hanoi4(n-h[n]-1, s, b, e, a)
    hanoi3(h[n], s, b, e)
    hanoi4(n-h[n]-1, a, s, b, e)

N = int(input())
ans = ""
h3, h4, h = [0,1,3], [0,1,3], [0,0,1]
for i in range(3, N+1):
    h3.append(h3[i-1]*2+1)
    h4.append(h4[i-1]+h3[1]+h4[i-1])
    for j in range(2,i):
        val = h4[i-j]+h3[j]+h4[i-j]
        if h4[i] < val:
            h4[i] = val
            h[i] = j
print(h4[N])
hanoi4(N, 1, 2, 3, 4)
