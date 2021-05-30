from itertools import combinations
import sys
input = sys.stdin.readline

# Get data from input
N = int(input())
S = []
for _ in range(N):
    S.append(list(map(int, input().split())))

# Calculate team stat
def stat(team):
    total = 0
    for i in range(len(team)):
        mi = team[i]
        for j in range(i + 1, len(team)):
            mj = team[j]
            total += S[mi][mj] + S[mj][mi]
    return total

# answer: minimum diffrence of stats between two teams
answer = float('inf')

# make possible combination of team members 
# and get stats to find difference
c = list(combinations(range(N), N // 2))
for i in range(len(c) // 2):
    team_blue = c[i]
    team_red = c[-1-i]
    answer = min(answer, abs(stat(team_blue) - stat(team_red)))
    
print(answer)
