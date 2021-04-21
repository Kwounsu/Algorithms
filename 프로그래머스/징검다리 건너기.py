def solution(stones, k):
    def is_possible(people_num: int) -> bool:
        disconnected = 0
        for stone in stones:
            if stone < people_num:
                disconnected += 1
            else:
                disconnected = 0

            if disconnected >= k:
                return False
        return True

    left, right = 1, 200000001
    while left < right - 1:
        mid = (left + right) // 2

        if is_possible(mid):
            left = mid
        else:
            right = mid

    return left


print(solution([i for i in range(200000, 0, -1)], 5000))
