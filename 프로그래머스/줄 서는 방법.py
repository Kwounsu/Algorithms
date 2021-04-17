import math


def solution(n, k):
    answer = []
    origin = list(range(1, n + 1))

    for i in range(n, 0, -1):
        f = math.factorial(i - 1)
        index = math.ceil(k / f)
        k %= f
        answer.append(origin.pop(index - 1))

    return answer
