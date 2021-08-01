import sys
input = sys.stdin.readline


dp = [1]
ugly = {2, 3, 5}
 
for i in range(1, 1500) :
    min_val = min(ugly)
    dp.append(min_val)
    ugly.remove(min_val)
    ugly.add(min_val * 2)
    ugly.add(min_val * 3)
    ugly.add(min_val * 5)

while True:
    n = int(input())
    if n == 0:
        break
    print(dp[n-1])
