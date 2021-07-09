import sys
input = sys.stdin.readline
 
 
def solution(k, a, b):
    def count_remaining_games():
        # get difference
        diff = a - b
 
        if diff >= 2:
            return 0
        return 2 - diff
     
    # make sure A is greater than or equals to B
    if a < b:
        a, b = b, a
     
    # if score already exceeded k
    if a >= k:
        return count_remaining_games()
     
    # if not reached to k yet
    ans = k - a
    a += ans
    return ans + count_remaining_games()
 
 
N = int(input())
for _ in range(N):
    K, A, B = map(int, input().split())
    print(solution(K, A, B))
