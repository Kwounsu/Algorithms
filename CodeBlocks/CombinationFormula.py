memo = [0 for _ in range(101)]
memo[0],memo[1],after = 1,1,2
def fact(n):
    if memo[n] == 0:
        for i in range(after,n+1):
            memo[i] = memo[i-1]*i
        after = n+1
    return memo[n]

def C(n,r):
    return fact(n) / (fact(n-r) * fact(r))
