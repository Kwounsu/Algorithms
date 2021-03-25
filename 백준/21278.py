# 프로그래머스에서 진행된 제2회 류호석배 알고리즘 코딩 테스트 4번 문제

import sys
from collections import deque
input = sys.stdin.readline

def dijkstra(k,n):
    d = [sys.maxsize for i in range(n)]
    d[k-1] = 0
    q = deque([(k,0)])
    while q:
        current, distance = q.popleft()
        if d[current-1] < distance:
            continue
        for i in vertex[current]:
            nextDist = distance+2
            if d[i-1] > nextDist:
                d[i-1] = nextDist
                q.append((i,nextDist))
    return d

def solution(n,m,dp,vertex):
    for k in range(1,n+1):
        dp.append(dijkstra(k,n))
    min_weight = sys.maxsize
    a,b = 0,0
    for i in range(n):
        for j in range(n):
            if i!=j:
                two_sum = sum(map(min,zip(dp[i],dp[j])))
                if two_sum < min_weight:
                    min_weight = two_sum
                    a,b = i,j
    print(a+1,b+1,min_weight)
    
if __name__ == '__main__':
    n,m = map(int,input().split())
    dp = []
    vertex = {i:[] for i in range(n+1)}
    for i in range(m):
        u,v = map(int,input().split())
        vertex[u].append(v)
        vertex[v].append(u)
    solution(n,m,dp,vertex)
