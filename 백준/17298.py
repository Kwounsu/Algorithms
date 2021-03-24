# 오큰수 (17298)

# 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

import sys
input = sys.stdin.readline

def solution(n,a):
    answer = [-1]*n
    stack = [0]
    for i in range(1,n):
        try:
            while a[stack[-1]] < a[i]:
                answer[stack.pop()] = a[i]
        except:
            pass
        stack.append(i)
    return answer

if __name__ == '__main__':
    n = int(input())
    a = list(map(int,input().split()))
    print(*solution(n,a))
