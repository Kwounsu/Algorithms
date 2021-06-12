import sys
from collections import Counter
input = sys.stdin.readline

n = int(input())
a_n = list(map(int, input().split()))
m = int(input())
a_m = list(map(int, input().split()))

counts = Counter(a_n)
print(*[counts[i] for i in a_m])
