from collections import deque


def solution(s):
    answer = []

    for num in s:
        stack = []
        count = 0
        for i in num:
            if i == '0' and stack[-2:] == ['1', '1']:
                for _ in range(2):
                    stack.pop()
                count += 1
            else:
                stack.append(i)
        
        if count == 0:
            answer.append(num)
        else:
            q = deque()
            while stack:
                if stack[-1] == '1':
                    q.append(stack.pop())
                else:
                    break
                    
            while count > 0:
                q.extendleft('011')
                count -= 1
            
            while stack:
                q.appendleft(stack.pop())
            answer.append(''.join(q))

    return answer
  
###############################################

def f(n):
    # extract '110's
    stack = []
    count = 0
    for i in n:
        stack.append(i)
        if i == '0' and stack[-3:] == ['1', '1', '0']:
            del stack[-3:]
            count += 1
    
    # find last '0' and insert '110's after that, or in front.
    index = -1
    for i in range(len(stack)):
        if stack[i] == '0':
            index = i + 1
    if index < 0:
        result = "110" * count + ''.join(stack)
    else:
        result = ''.join(stack[:index]) + "110" * count + ''.join(stack[index:])
    return result


def solution(s):
    return [f(x) for x in s]
