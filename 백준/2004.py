# 조합 0의 개수 (2004)

# 문제
# 이항계수의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

# 해설
# 마지막에 붙은 0의 개수를 따지는건 10이 몇번 곱해졌는가를 따진다고 판단된다.
# 그래서 5와 2가 몇번 들어갔는가를 따져서 10의 갯수를 파악했다.

import sys
input = sys.stdin.readline

# N: number being factorialized, num: counting unit
def num_in_N_fact(N, num):
    count = 0
    divNum = num
    while divNum <= N:
        count += N//divNum
        divNum *= num
    return count

def solution(n,k):
    two_count = num_in_N_fact(n,2)-num_in_N_fact(k,2)-num_in_N_fact(n-k,2)
    five_count = num_in_N_fact(n,5)-num_in_N_fact(k,5)-num_in_N_fact(n-k,5)
    return min(two_count,five_count)
    
if __name__=="__main__":
    a,b = map(int,input().split())
    print(solution(a,b))
