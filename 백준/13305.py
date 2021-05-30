import sys
input = sys.stdin.readline

N = int(input())
distances = list(map(int, input().split()))
prices = list(map(int, input().split()))

total_cost = 0
min_price = prices[0]
for i, d in enumerate(distances):
    min_price = min(min_price, prices[i])
    total_cost += min_price * d
    
print(total_cost)
