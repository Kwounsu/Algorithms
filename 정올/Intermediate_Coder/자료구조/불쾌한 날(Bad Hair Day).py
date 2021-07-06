import sys
input = sys.stdin.readline

N = int(input())
a = []
for i in range(N):
    a.append(int(input()))
    
stack = []
result = 0
for i in range(N):
    while stack and a[stack[-1]] <= a[i]:
        stack.pop()
    result += len(stack)
    stack.append(i)
    
print(result)
