import sys
input = sys.stdin.readline


def solution(n, cows):
    cow_idx = [i for i,x in enumerate(cows) if x=='1']
    if len(cow_idx) == 0:
        return n - 1

    dis = sorted([cow_idx[i] - cow_idx[i-1] for i in range(1, len(cow_idx))])

    s, e = cow_idx[0], cow_idx[-1]
    if len(dis) == 0:
        return max(min(s, n-e-1), max(s//2, (n-e-1)//2))
    
    minD, maxD = dis[0], dis[-1]
    maxD2 = dis[-2] if len(dis) >= 2 else 0  # second max dis
    
    return max([1,
        min(s//2, minD), 
        min((n-1-e)//2, minD),
        min(min(s, n-1-e), minD),
        min(min(s, maxD//2), minD),
        min(min(n-1-e, maxD//2), minD),
        min(min(maxD//2, maxD2//2), minD),
        min(maxD//3, minD)])


n = int(input())
cows = input().strip()
print(solution(n, cows))
