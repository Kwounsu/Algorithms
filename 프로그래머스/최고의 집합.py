def solution(n, s):
    if n > s:
        return [-1]
    
    answer = []
    for i in range(n - 1):
        x = s // (n - i)
        s -= x
        answer.append(x)
    answer.append(s)
    
    return answer
