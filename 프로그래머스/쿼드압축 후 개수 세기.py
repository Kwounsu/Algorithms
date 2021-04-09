def all_same(arr):
    for row in arr:
        for i in row:
            if i != arr[0][0]:
                return False
    return True


def solution(arr):
    answer = [0, 0]

    def quad_compress(arr):
        if len(arr) == 1 or all_same(arr):
            answer[arr[0][0]] += 1
            return

        half = len(arr) // 2
        a1, a2, a3, a4 = [], [], [], []
        for i in range(half):
            a1.append(arr[i][:half])
            a2.append(arr[i][half:])
        for i in range(half, len(arr)):
            a3.append(arr[i][:half])
            a4.append(arr[i][half:])

        quad_compress(a1)
        quad_compress(a2)
        quad_compress(a3)
        quad_compress(a4)

    quad_compress(arr)
    return answer
