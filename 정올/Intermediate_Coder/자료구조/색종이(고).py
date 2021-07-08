import sys
input = sys.stdin.readline


def find_largest_rectangle_area():
    ans = 0
    
    for i in range(100):
        for j in range(100):
            if matrix[i][j] == 1:
                matrix[i][j] += matrix[i - 1][j]

    for r in range(1, 100):
        for c in range(1, 100):
            height = 100
            for k in range(c, 100):
                if height > 0:
                    height = min(height, matrix[r][k])
                    area = height * (k - c + 1)
                    ans = max(ans, area)
                else:
                    break
    return ans

def attach_paper(x, y):
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            matrix[i][j] = 1


n = int(input())
matrix = [[0] * 101 for _ in range(101)]

for _ in range(n):
    x, y = map(int, input().split())
    attach_paper(x, y)

print(find_largest_rectangle_area())
