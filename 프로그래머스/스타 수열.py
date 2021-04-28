from collections import Counter


def solution(a):
    gyo = Counter(a)
    answer = 0
    
    for k in gyo.keys():
        if gyo[k] > answer:
            i, count = 0, 0
            
            while i < len(a) - 1:
                if a[i] == a[i + 1] or (a[i] != k and a[i + 1] != k):
                    i += 1
                    continue
                count += 1
                i += 2
            
            answer = max(answer, count)
        
    return answer * 2
