# Collections.Counter 이용
import sys
input = sys.stdin.readline
from collections import Counter

n = int(input())
a_n = list(map(int, input().split()))
m = int(input())
a_m = list(map(int, input().split()))

counts = Counter(a_n)
print(*[counts[i] for i in a_m])


# 이진탐색 (bisect)
import sys
input = sys.stdin.readline
from bisect import bisect_right, bisect_left


def count(array, target):
    left = bisect_left(array, target)
    right = bisect_right(array, target)
    return right - left


n = int(input())
a_n = sorted(list(map(int, input().split())))
m = int(input())
a_m = list(map(int, input().split()))

print(*[count(a_n, i) for i in a_m])
