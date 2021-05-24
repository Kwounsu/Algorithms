import sys
input = sys.stdin.readline


def solution(N, T, M, P, R):
    def solve(i, t):
        if i == N:
            return 0
        
        score = dp[i][t]
        if score != -1:
            return score
        
        score = solve(i + 1, t)
        dp[i][t] = score
        if t + A[i][2] <= T:
            score = max(score, A[i][0] - (t + A[i][2])
                        * A[i][1] + solve(i + 1, t + A[i][2]))
            dp[i][t] = score
        return score
    
    # sort: Ri / Pi <= Rj / Pj =>  i -> j
    A = [[M[i], P[i], R[i]] for i in range(N)]
    A.sort(key=lambda x: x[2] / x[1])
    
    # calculate
    dp = [[-1] * (T + 1) for _ in range(N)]
    answer = solve(0, 0)

    return answer


N, T = map(int,input().split())
M = list(map(int,input().split()))
P = list(map(int,input().split()))
R = list(map(int,input().split()))

print(solution(N, T, M, P, R))
