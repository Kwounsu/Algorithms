from collections import deque


def solution(s):
    s = deque(s)
    match = {']': '[', '}': '{', ')': '('}

    def is_balanced(s):
        stack = []
        for i in s:
            if i in '[{(':
                stack.append(i)
            else:
                if not stack:
                    return False
                elif stack.pop() != match[i]:
                    return False
        return len(stack) == 0

    def rotate():
        s.append(s.popleft())

    answer = 0
    for _ in range(len(s)):
        if is_balanced(s):
            answer += 1
        rotate()

    return answer
