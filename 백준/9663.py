# N-Queen

# 문제
# N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
# N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 N이 주어진다. (1 ≤ N < 15)

# 출력
# 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

import sys


def nqueen(row, n, _col, _d1, _d2):
    count = 0
    if row == n:
        return 1
    
    for i in range(n):
        d1, d2 = row+i, n+row-i-1
        if _col[i] == _d1[d1] == _d2[d2] == False:
            _col[i] = _d1[d1] = _d2[d2] = True
            count += nqueen(row+1, n, _col, _d1, _d2)
            _col[i] = _d1[d1] = _d2[d2] = False
            
    return count


n = int(sys.stdin.readline())
_col, _d1, _d2 = [False] * 15,[False] * 30,[False] * 30
print(nqueen(0, n, _col, _d1, _d2))
