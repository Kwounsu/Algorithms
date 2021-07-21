def solution(num):
    dp = [1, 1]
    for i in range(1, len(num)):
        if num[i] == '0':
            if num[i-1] > '3':
                return 0
            else:
                dp.append(dp[i])
        # 1~34
        elif num[i-1] != '0' and (int)(num[i-1])*10 + (int)(num[i]) <= 34:
            dp.append(dp[i-1] + dp[i])
        else:
            dp.append(dp[i])
    return dp[-1]

num = input().strip()
print(solution(num))
