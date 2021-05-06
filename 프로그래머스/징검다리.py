def solution(distance, rocks, n):
    rocks.sort()

    left, right = 0, distance
    while left < right:
        mid = (left + right + 1) // 2

        prev = rock_remove_count = 0
        for rock in rocks:
            if rock - prev < mid:
                rock_remove_count += 1
            else:
                prev = rock
                
        if rock_remove_count > n:
            right = mid - 1
        else:
            left = mid

    return right
