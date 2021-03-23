# 이항 계수 2 (11051)

# 문제
# 자연수 과 정수 가 주어졌을 때의 이항 계수를 10007로 나눈 나머지를 구하는 프로그램을 작성하시오.

import sys
input = sys.stdin.readline

def C(n,k):
    val = 1
    k = n-k if k>n//2 else k    # k가 커지면 효율이 떨어지기에 최적화
    for i in range(n-k+1,n+1):
        val *= i
    for i in range(2,k+1):
        val //= i
    return val

def solution(n,k):
    return C(n,k)%10007
    
if __name__=="__main__":
    n,k = map(int,input().split())
    print(solution(n,k))
