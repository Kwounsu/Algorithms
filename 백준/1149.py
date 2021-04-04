import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6) # 런타임 에러 (RecursionError) 해결용

def rgb(costs) -> int:
    dp = [[0, 0, 0] for _ in range(len(costs))]
    def dfs(house_num: int, color: int) -> int:
        if house_num >= len(costs) - 1:
            return costs[house_num][color]
        
        colors = [i for i in range(0, 3) if i != color]
        if dp[house_num][color] == 0:
            dp[house_num][color] = min(
                dfs(house_num + 1, colors[0]) + costs[house_num][color],
                dfs(house_num + 1, colors[1]) + costs[house_num][color]
            )
        return dp[house_num][color]
    return min(dfs(0, 0), dfs(0, 1), dfs(0, 2))


costs = []
for _ in range(int(input())):
    costs.append(list(map(int,input().split())))
print(rgb(costs))
