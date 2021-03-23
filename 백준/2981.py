# 검문

# 문제
# 상근이는 시간을 때우기 위해서 수학 게임을 하기로 했다.
# 먼저 근처에 보이는 숫자 N개를 종이에 적는다. 그 다음, 종이에 적은 수를 M으로 나누었을 때, 나머지가 모두 같게 되는 M을 모두 찾으려고 한다. M은 1보다 커야 한다.
# N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 종이에 적은 수의 개수 N이 주어진다. (2 ≤ N ≤ 100)
# 다음 줄부터 N개 줄에는 종이에 적은 수가 하나씩 주어진다. 이 수는 모두 1보다 크거나 같고, 1,000,000,000보다 작거나 같은 자연수이다. 같은 수가 두 번 이상 주어지지 않는다.
# 항상 M이 하나 이상 존재하는 경우만 입력으로 주어진다.

# 출력
# 첫째 줄에 가능한 M을 공백으로 구분하여 모두 출력한다. 이때, M은 증가하는 순서이어야 한다.

import sys
input = sys.stdin.readline

def divisor(n):
    l = []
    for i in range(2,int(n**(0.5))+1):
        if n%i==0:
            l.append(i)
            x = n//i
            if x != i:
                l.append(x)
    l.append(n)
    return sorted(set(l))

def gcd(a,b):
    if a<b:
        a,b = b,a
    while a%b:
        a,b = b,a%b
    return b

def solution(n,a):
    a.sort(reverse = True)
    diff = [a[i]-a[i+1] for i in range(n-1)]

    gcf = diff[0]
    for i in range(1,n-1):
        gcf = gcd(gcf,diff[i])
    return divisor(gcf)
    
if __name__=="__main__":
    n = int(input())
    a = [int(input()) for _ in range(n)]
    print(*solution(n,a))
