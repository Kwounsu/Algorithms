# 스택과 백트래킹을 사용한 방법

def solution(n):
    result = []

    def dfs(braces, open_left, close_left):
        if open_left == close_left == 0:
            if len(braces) == 0:
                result.append(1)
            return

        if open_left > 0:
            dfs(braces + '(', open_left - 1, close_left)
        if len(braces) > 0 and close_left > 0:
            if braces[-1] == '(':
                dfs(braces[:-1], open_left, close_left - 1)
            else:
                dfs(braces + ')', open_left, close_left - 1)

    dfs('', n, n)
    return len(result)
    
    
# 카탈란 수를 사용한 방법
from math import factorial as f


def solution(n):
    return f(2 * n) // (f(n)**2 * (n + 1))
