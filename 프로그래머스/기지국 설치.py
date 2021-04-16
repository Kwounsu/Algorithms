import math


def solution(n, stations, w):
    answer, i = 0, 1
    
    block_size = w * 2 + 1
    for s in stations:
        answer += math.ceil((s - w - i) / block_size)
        i = s + w + 1
    
    if i <= n:
        answer += math.ceil((n + 1 - i) / block_size)
        
    return answer


# another way. little slower than above code

def solution(n, stations, w):
    answer, i, loc = 0, 0, 1
    
    while loc <= n:
        if i < len(stations) and loc >= stations[i] - w:
            loc = stations[i] + w + 1
            i += 1
        else:
            loc += 2 * w + 1
            answer += 1
            
    return answer
