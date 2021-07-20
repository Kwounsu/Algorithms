n = int(input())
 
if n % 2:
    print(0)
else:
    n//=2
    dp = [1,3]
    for i in range(2, n + 1):
        dp.append(dp[i - 1] * 4 - dp[i - 2])
    print(dp[n])
     
"""
n = int(input())
 
if n % 2:
    print(0)
else:
    dp = [1,0,3,0]
    for i in range(4, n + 1, 2):
        dp.append(dp[i - 2] * 4 - dp[i - 4])
        dp.append(0)
    print(dp[n])
"""
