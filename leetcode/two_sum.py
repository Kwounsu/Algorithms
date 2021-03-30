def two_sum(nums: List[int], target: int) -> List[int]:
    nums_dict = {}
    for i, num in enumerate(nums):
        if target - num in nums_dict:
            return [nums_dict[target - num], i]
        nums_dict[num] = i
