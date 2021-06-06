import sys
input = sys.stdin.readline

# INPUT
N, M = map(int, input().split())
A = []
for _ in range(N):
    A.append(list(map(int, input().split())))
M, K = map(int, input().split())
B = []
for _ in range(M):
    B.append(list(map(int, input().split())))

# A * B = AB
def productMatrix(A, B):
    return [[sum(a*b for a, b in zip(A_row,B_col)) for B_col in zip(*B)] for A_row in A]

AB = productMatrix(A, B)

# Print
for row in AB:
    print(*row)
