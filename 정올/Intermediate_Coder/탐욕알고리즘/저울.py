import sys
input = sys.stdin.readline

n = int(input())
weights = sorted(list(map(int, input().split())))

total = 0
for i in range(n):
    if weights[i] > total + 1:
        break
    total += weights[i]

print(total + 1)
