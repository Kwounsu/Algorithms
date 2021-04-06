import sys
read = sys.stdin.readline


N = int(read())
a = list(map(int, read().split()))

for i in range(1, len(a)):
    a[i] = max(a[i - 1] + a[i], a[i])
        
print(max(a))
