MOD = 1000000007


# Memoization with list
memo = [0, 1, 1]

def fib(n):
    for i in range(3, n + 1):
        memo.append((memo[i - 2] + memo[i - 1]) % MOD)
    return memo[-1]

##################################################

# Memoization with two variables

def fib(n):
    first = second = 1
    for i in range(2, n):
        first, second = second, (first + second) % MOD
    return second

##################################################

# Matrix

#2^x 피보나치를 구해주는 함수
def matrix_mul_self(x):
    base = [[1, 1], [1, 0]]
    result = [[1, 1], [1, 0]]
    for _ in range(x):
        result = [[0, 0], 
                  [0, 0]]
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    result[i][j] += (base[i][k] * base[k][j]) % MOD
        base = result
        
    return result

#2*2 두 행렬의 곱을 구해주는 함수
def matrix_mul(a, b):
    result = [[0 ,0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                result[i][j] += (a[i][k] * b[k][j]) % MOD
                
    return result

n = bin(int(sys.stdin.readline()))[2:] #2진법으로 변환
result = [[1, 0], [0, 1]]

for i in range(len(n)):
    if n[-i - 1] == '1': #2^x 피보나치들만 구해준 다음 곱해줌
        result = matrix_mul(result, matrix_mul_self(i))
        
print(result[0][1] % MOD)

##################################################

def fibo(n):
    SIZE = 2
    ZERO = [[1, 0], [0, 1]] # 행렬의 항등원
    BASE = [[1, 1], [1, 0]] # 곱셈을 시작해 나갈 기본 행렬

    # 두 행렬의 곱을 구한다
    def square_matrix_mul(a, b, size=SIZE):
        new = [[0 for _ in range(size)] for _ in range(size)]

        for i in range(size):
            for j in range(size):
                for k in range(size):
                    new[i][j] += (a[i][k] * b[k][j]) % MOD

        return new

    # 기본 행렬을 n번 곱한 행렬을 만든다
    def get_nth(n):
        matrix = ZERO.copy()
        k = 0
        tmp = BASE.copy()

        while 2**k <= n:
            if n & (1 << k) != 0:
                matrix = square_matrix_mul(matrix, tmp)
            k += 1
            tmp = square_matrix_mul(tmp, tmp)

        return matrix

    return get_nth(n)[1][0]
