def dfs(m):
    global size, cnt
    if m < 0:
        for x in range(10):
            for j in range(size):
                if x == 0 and j == 0:
                    continue
                A = ''.join(arr[:j]) + str(x) + ''.join(arr[j:])
                B = ''.join(arr)
                if int(A) + int(B) == n:
                    ans.append((A,B))
        return
    for i in range(10):
        arr.append(str(i))
        dfs(m-1)
        arr.pop()

n = int(input())
size = len(str(n))
arr, ans = [], []

dfs(size - 2)

ans.sort()
print(len(ans))
for A, B in ans:
    print(f"{A} + {B} = {n}")
