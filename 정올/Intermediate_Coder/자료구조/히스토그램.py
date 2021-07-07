import sys
input = sys.stdin.readline

a = list(map(int, input().split()))
n, a = a[0], a[1:]
max_area = 0
stack = []

for i in range(n):
    while stack and stack[-1][0] > a[i]:
        h, h_i = stack.pop()
        w = (i - stack[-1][1] - 1) if stack else i
        area = h * w
        max_area = max(max_area, area)
    stack.append((a[i], i))
    
while stack:
    h, h_i = stack.pop()
    area = h * (n - h_i)
    max_area = max(max_area, area)
print(max_area)
