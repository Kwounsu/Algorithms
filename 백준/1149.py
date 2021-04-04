# 타뷸레이션

import sys
input = sys.stdin.readline


def rgb(costs) -> int:
    dp = [[0, 0, 0] for _ in range(len(costs))]
    
    dp[0][0] = costs[0][0]
    dp[0][1] = costs[0][1]
    dp[0][2] = costs[0][2]
    
    for i in range(1, len(costs)):
        dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2])
        dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2])
        dp[i][2] = costs[i][2] + min(dp[i - 1][0], dp[i - 1][1])
    
    return min(dp[len(costs) - 1])


costs = []
for _ in range(int(input())):
    costs.append(list(map(int,input().split())))
print(rgb(costs))

# --------------------------------------------------------------

# 메모이제이션

# import sys
# input = sys.stdin.readline
# sys.setrecursionlimit(10**6) # 런타임 에러 (RecursionError) 해결용

# def rgb(costs) -> int:
#     dp = [[0, 0, 0] for _ in range(len(costs))]
#     def dfs(house_num: int, color: int) -> int:
#         if house_num >= len(costs) - 1:
#             return costs[house_num][color]
        
#         colors = [i for i in range(0, 3) if i != color]
#         if dp[house_num][color] == 0:
#             dp[house_num][color] = min(
#                 dfs(house_num + 1, colors[0]) + costs[house_num][color],
#                 dfs(house_num + 1, colors[1]) + costs[house_num][color]
#             )
#         return dp[house_num][color]
#     return min(dfs(0, 0), dfs(0, 1), dfs(0, 2))


# costs = []
# for _ in range(int(input())):
#     costs.append(list(map(int,input().split())))
# print(rgb(costs))
