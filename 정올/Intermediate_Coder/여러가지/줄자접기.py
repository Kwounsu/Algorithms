import sys
input = sys.stdin.readline


def cut(a, b):
    return 0 if a == b else (a + b) / 2 

n = int(input())
r1, r2 = map(int, input().split())
b1, b2 = map(int, input().split())
y1, y2 = map(int, input().split())

c = cut(r1, r2)
n = max(n - c, c)
b1, b2, y1, y2 = abs(b1 - c), abs(b2 - c), abs(y1 - c), abs(y2 - c)

c = cut(b1, b2)
n = max(n - c, c)
y1, y2 = abs(y1 - c), abs(y2 - c)

c = cut(y1, y2)
n = max(n - c, c)

print(n)
