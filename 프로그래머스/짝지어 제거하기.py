def solution(s):
    stack = []

    for l in s:
        if len(stack) > 0 and stack[-1] == l:
            stack.pop()
        else:
            stack.append(l)

    return int(len(stack) == 0)
