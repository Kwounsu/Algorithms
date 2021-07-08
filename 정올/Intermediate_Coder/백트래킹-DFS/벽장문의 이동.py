import sys
input = sys.stdin.readline


def dfs(idx, count):
    global answer
 
    if idx >= m:
        answer = min(answer, count)
        return
 
    if door[nums[idx]]: 
        dfs(idx + 1, count)
    else:
        lpos = 1
        for i in range(nums[idx], 1, -1):
            if door[i]:
                lpos = i
                break
        rpos = n
        for i in range(nums[idx], n+1):
            if door[i]:
                rpos = i
                break
 
        if door[lpos]:
            door[nums[idx]] = 1
            door[lpos] = 0
            dfs(idx+1, count + nums[idx] - lpos)
            door[nums[idx]] = 0
            door[lpos] = 1
 
        if door[rpos]:
            door[nums[idx]] = 1
            door[rpos] = 0
            dfs(idx+1, count + rpos - nums[idx])
            door[nums[idx]] = 0
            door[rpos] = 1

if __name__=='__main__':
    n = int(input())
    a, b = map(int, input().split())
    m = int(input().strip())
    nums = [int(input()) for _ in range(m)]
    
    door = [0 for i in range(n+1)]
    door[a] = door[b] = 1
    
    answer = float('inf')
    dfs(0, 0)
    
    print(answer)
