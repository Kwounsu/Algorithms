import sys
read = sys.stdin.readline

def solution(N, M):
    # Funtion to count needed end parts
    def make(n):
        if end_part[n] != -1:
            end_part[n] += 1;
        else:
            for i in range(1, N):
                if need[n][i] != 0:
                    for j in range(1, need[n][i] + 1):
                        make(i)
    
    # get inputs
    need = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
    end_part = [0 for _ in range(N + 1)]
    for _ in range(M):
        x, y, k = map(int, read().split())
        need[x][y] = k
        end_part[x] = -1
    
    # call recursion funtion
    make(N)
    
    # print result
    for i in range(1, N + 1):
        if end_part[i] >= 0:
            print(i, end_part[i])
    
# Read input
N = int(read())
M = int(read())

solution(N, M)
