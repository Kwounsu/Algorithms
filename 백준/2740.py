import sys
input = sys.stdin.readline

# INPUT
N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
M, K = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(M)]


def product_matrix(A, B):
    return [[sum(a*b for a, b in zip(A_row,B_col)) for B_col in zip(*B)] for A_row in A]


def product_print(A):
    for row in A:
        print(*row)

        
AB = product_matrix(A, B)
product_print(AB)
