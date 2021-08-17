import sys
input = sys.stdin.readline


def inter_len(x1,y1,x2,y2):
    if x1 > x2 or (x1 == x2 and y1 > y2):
        x1,y1,x2,y2 = x2,y2,x1,y1
    if y1 < x2:
        return 0
    if x1 <= x2 and y2 <= y1:
        return y2 - x2 + 1
    return y1 - x1 + 1


def solution():
    if a*b <= c:
        print(m - n + 1, 0, sep='\n')
        return
    ans, i = 0, 1
    while True:
        s = (i - 1) * b + 1
        e = c * i // a
        if s > m or s > e:
            break
        ans += inter_len(s, e, n, m)
        i+=1
    
    print(ans, m - n + 1 - ans, sep='\n')


a,b,c = map(int, input().split())
n, m = map(int, input().split())
solution()
