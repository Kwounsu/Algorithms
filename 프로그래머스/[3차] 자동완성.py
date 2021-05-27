def solution(words):
    def get_diff(a, b):
        d = 0
        for j in range(len(a)):
            d += 1
            if j >= len(b) or a[j] != b[j]:
                break
        return d

    answer = 0
    words.sort()
    for i in range(len(words)):
        diff = 0
        pre_i, post_i = i - 1, i + 1
        if pre_i >= 0:
            diff = max(diff, get_diff(words[i], words[pre_i]))
        if post_i < len(words):
            diff = max(diff, get_diff(words[i], words[post_i]))
        answer += diff
    return answer
