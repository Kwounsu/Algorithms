# Two Pointer
def trap(height: List[int]) -> int:
    answer = 0
    left, right = 0, len(height) - 1
    left_max, right_max = height[left], height[right]

    while left < right:
        left_max = max(left_max, height[left])
        right_max = max(right_max, height[right])
        if left_max < right_max:
            answer += left_max - height[left]
            print(left, left_max, answer)
            left += 1
        else:
            answer += right_max - height[right]
            print(right, right_max, answer)
            right -= 1
    return answer
