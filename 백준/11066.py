import sys
read = sys.stdin.readline
MAX = sys.maxsize

    
def solution(N, A):
    dp = [[0] * N for _ in range(N)]
    
    # 첫번째부터 N번짹 까지의 파일크기합 한번 합칠때 추가비용
    sums = [0]
    for i in A:
        sums.append(sums[-1] + i)
        
    # Knuth's Optimization 각 구간에서 나오는 k 저장
    knuth = [[0] * N for _ in range(N)]  
    for i in range(N):  #초기화
        knuth[i][i] = i
    
    for d in range(1, N):
        for i in range(N - d):
            j = d + i
            dp[i][j] = MAX
            
            # [i:j]를 k를 기준으로 나눠 최솟값 계산
            for k in range(knuth[i][j-1], knuth[i+1][j] + 1):
                if k < N - 1 and dp[i][j] > dp[i][k] + dp[k + 1][j] + sums[j + 1] - sums[i]:
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + sums[j + 1] - sums[i]
                    knuth[i][j] = k
                
    return dp[0][-1]
    

if __name__ == '__main__':
    T = int(read())
    for _ in range(T):
        N = int(read())
        A = list(map(int, read().split()))
        print(solution(N, A))
