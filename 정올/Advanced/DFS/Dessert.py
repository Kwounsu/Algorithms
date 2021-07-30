from sys import stdin
input = stdin.readline

LIMIT = 12345678910
n = int(input())
count = [0]
op = [''] * 20


def output():
    print("1", end=' ')
    for i in range(2, n + 1):
        print(op[i], i, end=' ')
    print()

"""
a: (+,-) 이전까지의 결과
b: (+,-) 이후부터 0개이상의 .을 계산한 수
"""
def dfs(depth, a, b):
    # 12345678910 이후는 0을 만들 수 없음. (백트래킹)
    if abs(a) >= LIMIT or abs(b) >= LIMIT:
        return
    
    if depth > n:
        if a + b == 0:
            count[0] += 1
            if count[0] > 20:
                return
            output()
        return


    op[depth] = '+'
    dfs(depth+1, a+b, depth)
    op[depth] = '-'  
    dfs(depth+1, a+b, -depth)          

    op[depth] = '.'
    base = 10 if depth < 10 else 100
    dfs(depth+1, a, b*base+depth)

dfs(2, 0, 1)
print(count[0])
