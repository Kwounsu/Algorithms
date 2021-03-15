memo = [0 for _ in range(101)]
memo[0],memo[1],after = 1,1,2
def fact(memo,n):
    if memo[n] == 0:
        for i in range(after,n+1):
            memo[i] = memo[i-1]*i
    return memo[n]
