from collections import Counter
import sys
input = sys.stdin.readline


def find_second_most_common(a):
    common = Counter(a).most_common()
    most_occ = common[0][1]
    most_common = []
    
    for num, occ in common:
        if occ != most_occ:
            break
        most_common.append(num)
        
    if len(most_common) > 1:
        most_common.sort()
        return most_common[1]
    else:
        return most_common[0]

a = []
N = int(input())
for _ in range(N):
    a.append(int(input()))
a.sort()

# 산술평균 : N개의 수들의 합을 N으로 나눈 값. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
print(round(sum(a) / N))
# 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
print(a[N // 2])
# 최빈값 : N개의 수들 중 가장 많이 나타나는 값. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
print(find_second_most_common(a))
# 범위 : N개의 수들 중 최댓값과 최솟값의 차이
print(a[-1] - a[0])
