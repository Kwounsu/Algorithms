def solution(people, limit):
    boats = 1
    people.sort()
    
    capacity = 0
    left, right = 0, len(people) - 1
    while left <= right:
        if capacity + people[left] + people[right] <= limit:
            capacity += people[left] + people[right]
            left += 1
            right -= 1
        elif capacity + people[right] <= limit:
            capacity += people[right]
            right -= 1
        elif capacity + people[left] <= limit:
            capacity += people[left]
            left += 1
        else:
            boats += 1
            capacity = 0
    
    return boats
