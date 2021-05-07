def solution(cookie):
    answer = 0

    for m in range(len(cookie) - 1):
        left, right = m, m + 1
        left_sum, right_sum = cookie[left], cookie[right]

        if left_sum == right_sum:
            answer = max(answer, left_sum)

        while True:
            if left_sum > right_sum:
                right += 1
                if right > len(cookie) - 1:
                    break
                right_sum += cookie[right]
            else:
                left -= 1
                if left < 0:
                    break
                left_sum += cookie[left]

            if left_sum == right_sum:
                answer = max(answer, left_sum)

    return answer
    
    
    
def solution(cookie):
    answer = 0
    for m in range(1, len(cookie)):
        lsum = 0
        rsum = 0
        lsums = set()
        for i in range(m-1, -1, -1):
            lsum += cookie[i]
            lsums.add(lsum)
        for j in range(m, len(cookie)):
            rsum += cookie[j]
            if rsum in lsums:
                answer = max(answer, rsum)
    return answer



from itertools import accumulate


def solution(cookie):
    answer = 0
    for m in range(len(cookie) - 1):
        a = set(accumulate(reversed(cookie[:m+1])))
        b = set(accumulate(cookie[m+1:]))
        c = a & b

        if c:
            answer = max(*c, answer)
    return answer
