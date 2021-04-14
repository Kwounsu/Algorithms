from collections import deque


def solution(cache_size, cities):
    if cache_size == 0:
        return len(cities) * 5

    exe_time = 0
    cache = deque([])  # 큐!

    for c in cities:
        city = c.lower()

        if city in cache:
            cache.remove(city)
            cache.append(city)
            exe_time += 1
        else:
            if len(cache) == cache_size:
                cache.popleft()
            cache.append(city)
            exe_time += 5

    return exe_time
