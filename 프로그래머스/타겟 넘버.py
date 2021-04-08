def solution(numbers, target):
    answer = [0]
    
    def dfs(nums, result):
        if len(nums) == 1:
            if result - nums[0] == target:
                answer[0] += 1
            if result + nums[0] == target:
                answer[0] += 1
            return
        
        dfs(nums[1:], result + nums[0])
        dfs(nums[1:], result - nums[0])
    
    dfs(numbers, 0)
    return answer[0]
