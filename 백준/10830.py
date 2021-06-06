from sys import stdin

input = stdin.readline

# INPUT
N, B = map(int, input().split())
A = [list(map(lambda x: x % 1000, map(int, input().split()))) for _ in range(N)]


def product_matrix(A, B):
    return [[sum(a * b for a, b in zip(A_row, B_col)) % 1000 for B_col in zip(*B)] for A_row in A]


def divide_and_conquer(A, B):
    if B == 1:
        return A
    half = divide_and_conquer(A, B // 2)
    A_pow = product_matrix(half, half)
    if B % 2 == 0:
        return A_pow
    else:
        return product_matrix(A_pow, A)


def product_print(A):
    for row in A:
        print(*row)


A = divide_and_conquer(A, B)
product_print(A)
