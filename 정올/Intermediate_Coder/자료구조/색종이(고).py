import sys
input = sys.stdin.readline

table = [[0 for i in range(100)] for j in range(100)]
N = int(input())
mx = 0
for i in range(N):
    x, y = map(int,input().split())
    for i in range(10):
        for j in range(10):
            table[x + i][y + j] = 1
def his(h):
    N = len(h)
    h = [100000001] + h
    mx = 0
     
    R = [N] * N
    stk = [0]
 
    for i in range(1, N + 1):
        A = h[i]
        while h[stk[-1]] > A:
            R[stk[-1] - 1] = i - 1
            stk.pop()
            if stk == []:
                break
        stk.append(i)
 
    L = [0] * N
    stk = [N]
 
    for i in range(N,0,-1):
        A = h[i]
        while h[stk[-1]] > A:
            L[stk[-1] - 1] = i
            stk.pop()
            if stk == []:
                break
        stk.append(i)
 
    for i in range(1,N + 1):
        if mx < (R[i-1] - L[i-1]) * h[i]:
            mx = (R[i-1] - L[i-1]) * h[i]
 
    return(mx)
 
for i in range(100):
    h = []
    for j in table:
        sum = 0
        for k in range(i,100):
            if j[k] == 1:
                sum += 1
            else:
                break
        h.append(sum)
    mx = max( mx, his(h))
 
print( mx)
