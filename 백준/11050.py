# 이항 계수 1 (11050)

# 문제
# 자연수 과 정수 가 주어졌을 때 이항 계수를 구하는 프로그램을 작성하시오.
import sys
input = sys.stdin.readline

dp = [1,1]
def fact(n):
    if n>=2:
        for i in range(len(dp),n+1):
            dp.append(dp[i-1]*i)
    return dp[n]

def C(n,k):
    return fact(n)//(fact(n-k)*fact(k))

def solution(n,k):
    return C(n,k)
    
if __name__=="__main__":
    n,k = map(int,input().split())
    print(solution(n,k))
