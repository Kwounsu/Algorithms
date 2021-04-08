import collections


def solution(dartResult):
    answer, prev, num = 0, 0, 0
    dartResult = collections.deque(list(dartResult))
    
    while dartResult:
        cur = dartResult.popleft()
        
        if cur.isnumeric():
            answer += num
            prev, num = num, int(cur)
            
            if num == 1:
                post = dartResult.popleft()
                if post == '0':  # handling case score 10
                    num = 10
                else:
                    dartResult.appendleft(post)
        elif cur == 'S':
            pass
        elif cur == 'D':
            num = num**2
        elif cur == 'T':
            num = num**3
        elif cur == '#': # 아차상
            num *= -1
        elif prev == 0:  # 스타상
            num *= 2
        else:
            num = num * 2
            answer += prev
        
    return answer + num
