def solution(money):
    n = len(money)

    # rob first house
    dp1 = [0] * n
    dp1[0] = dp1[1] = money[0]
    # not rob first house
    dp2 = [0] * n
    dp2[1] = money[1]

    for i in range(2, n - 1):
        dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1])
    for i in range(2, n):
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1])

    return max(dp1[-2], dp2[-1])
