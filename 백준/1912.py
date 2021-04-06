import sys
r = sys.stdin.readline


N = int(r())
a = list(map(int, r().split()))

for i in range(1, len(a)):
    a[i] = max(a[i - 1] + a[i], a[i])
        
print(max(a))
