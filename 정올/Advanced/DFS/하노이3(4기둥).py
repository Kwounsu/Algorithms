def hanoi3(n, s, a, e):
    if n == 0:
        return
    hanoi3(n-1, s, e, a)
    print(f"{n} : {chr(s+64)} -> {chr(e+64)}")
    hanoi3(n-1, a, s, e)

def hanoi4(n, s, a, b, e):
    if n == 0:
        return
    hanoi4(n-1, s, b, e, a)
    hanoi3(n-1, s, b, e)
    hanoi4(n-1, a, s, b, e)

N = int(input())
hanoi4(N, 1, 2, 3, 4)
