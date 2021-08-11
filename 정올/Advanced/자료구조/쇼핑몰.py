import sys
input = sys.stdin.readline
 
 
n, k = map(int, input().split())
customers = [list(map(int, input().split())) for _ in range(n)] # [id, items#]
  
cashers = []
try:
    for i in range(k):
        cashers.append(customers[i])
except:
    pass
idx = k
ans = 0
ans_cnt = 1
exit = []
 
while ans_cnt < n+1:
    try:
        for i, val in enumerate(cashers):
            if val[1] > 0:
                cashers[i] = [val[0], val[1]-1]
                if val[1] == 1:
                    exit.append(val[0])
                    if idx < n:
                        cashers[i] = customers[idx]
                        idx += 1
    except:
        pass
    while exit:
        ans += exit[-1] * ans_cnt
        exit.pop()
        ans_cnt += 1
  
print(ans)
