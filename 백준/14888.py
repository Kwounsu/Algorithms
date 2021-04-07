import sys
read = sys.stdin.readline
MAX, MIN = sys.maxsize, -sys.maxsize


def solution(nums, ops):
    results = set()

    def recur(num, idx, add, sub, mul, div):
        if idx == N:
            results.add(num)
            return
        else:
            if add:
                recur(num + nums[idx], idx + 1, add - 1, sub, mul, div)
            if sub:
                recur(num - nums[idx], idx + 1, add, sub - 1, mul, div)
            if mul:
                recur(num * nums[idx], idx + 1, add, sub, mul - 1, div)
            if div and nums[idx] != 0:
                recur(int(num / nums[idx]), idx + 1, add, sub, mul, div - 1)

    recur(nums[0], 1, ops[0], ops[1], ops[2], ops[3])
    print(max(results), min(results), sep='\n')
    
    
if __name__ == '__main__':
    N = int(read())
    nums = list(map(int, read().split()))
    ops = list(map(int, read().split()))
    solution(nums, ops)
