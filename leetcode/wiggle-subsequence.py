class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        N = len(nums)
        
        increase, decrease = 1, 1
        
        for j in range(1, N):
            if nums[j - 1] < nums[j]:
                increase = decrease + 1
            elif nums[j - 1] > nums[j]:
                decrease = increase + 1
                
        return max(increase, decrease)
        
  
    def wiggleMaxLength(self, nums: List[int]) -> int:
        N = len(nums)
        if N < 2:
            return N
        
        count = 1
        increasing = None
        prev_num = nums[0]
        
        for idx in range(1, N):
            num = nums[idx]
            
            if increasing != False and prev_num > num:
                increasing = False
                count += 1
            elif increasing != True and prev_num < num:
                increasing = True
                count += 1
                
            prev_num = num
            
        return count
