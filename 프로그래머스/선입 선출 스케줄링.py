def solution(n, cores):
    if n <= len(cores):
        return n

    n -= len(cores)

    def get_time():
        left, right = 0, n * min(cores)
        while left < right:
            mid = (left + right) // 2

            count = 0
            for core in cores:
                count += mid // core

            if n > count:
                left = mid + 1
            else:
                right = mid
        return right

    t = get_time()

    for core in cores:
        n -= (t - 1) // core

    for i in range(len(cores)):
        if t % cores[i] == 0:
            n -= 1
            if n == 0:
                return i + 1
