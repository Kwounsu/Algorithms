import sys
input = sys.stdin.readline

N = int(input())
triangle = [list(map(int,input().split())) for _ in range(N)]

for i in range(1, N):
    for j in range(len(triangle[i])):
        left = triangle[i - 1][j - 1] if j - 1 >= 0 else 0
        right = triangle[i - 1][j] if j < len(triangle[i - 1]) else 0
        triangle[i][j] += max(left, right)
        
print(max(triangle[-1]))
