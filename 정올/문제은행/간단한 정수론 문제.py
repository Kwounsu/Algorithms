from itertools import combinations
from collections import Counter
from math import prod
import sys
input = sys.stdin.readline


def solution(A, B):
    # 소인수 구해주는 함수
    def factor(n):
        k = 2
        while n != 1:
            if n % k == 0:
                factors.append(k)
                n /= k
            else:
                k += 1
 
    def get_x(step, num):
        if num > sq: return;
        if step == len(factors):
            x[0] = max(x[0], num)
            return

        get_x(step + 1, num * factors[step])
        get_x(step + 1, num)

    # 소인수분해로 총 소인수 개수 구하기
    factors = []
    factor(A)
    factor(B)
 
    # 소인수 목록에서 짝수개의 소인수 제거하기
    factors_counter = Counter(factors)
    factors = set(factors)
    for val in factors_counter:
        if factors_counter[val] % 2 == 0:
            factors.remove(val)
    factors = list(factors)
 
    # 소인수들의 곱 조합 중 합의 최솟값인 조합의 답 찾기
    total_mul = prod(factors)
    sq = sqrt(total_mul)
    x = [1]
    get_x(0, 1)
     
    # 답 출력
    print(x[0], total_mul // x[0])


N = int(input())
for _ in range(N):
    A, B = map(int, input().split())
    solution(A, B)
