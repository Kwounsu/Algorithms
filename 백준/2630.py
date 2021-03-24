# 색종이 만들기 (2630

# 분할 정복!

import sys
input = sys.stdin.readline

def d(i,j,n,a):
    if n==1:
        return [0, 1] if a[i][j] == '1' else [1, 0]
    
    a1 = d(i,j,n//2,a)
    a2 = d(i,j+n//2,n//2,a)
    a3 = d(i+n//2,j,n//2,a)
    a4 = d(i+n//2,j+n//2,n//2,a)
    
    if a1==a2==a3==a4==[1,0] or a1==a2==a3==a4==[0,1]:
        return a1
    else:
        return list(map(sum,zip(a1,a2,a3,a4)))

if __name__ == '__main__':
    n = int(input())
    a = [input().split() for _ in range(n)]
    print(*d(0,0,n,a),sep='\n')
