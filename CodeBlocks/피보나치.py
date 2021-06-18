# Memoization with list
memo = [0, 1, 1]
def fib(n):
    for i in range(3, n + 1):
        memo.append(memo[i - 2] + memo[i - 1])
    return memo[-1]


# Memoization with two variables
def fib(n):
    first = second = 1
    for i in range(2, n):
        first, second = second, first + second
    return second
