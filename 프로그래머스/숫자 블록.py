def largest_factor(n):
    if n == 1:
        return 0

    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0 and n // i <= 10000000:
            return n // i

    return 1


def solution(begin, end):
    answer = []

    for i in range(begin, end + 1):
        answer.append(largest_factor(i))

    return answer
