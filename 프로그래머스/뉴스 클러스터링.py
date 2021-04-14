def solution(str1, str2):
    list1 = [str1[n:n + 2].lower() for n in range(len(str1) - 1) if str1[n:n + 2].isalpha()]
    list2 = [str2[n:n + 2].lower() for n in range(len(str2) - 1) if str2[n:n + 2].isalpha()]

    union = set(list1) | set(list2)

    if union:
        sum_of_sets = []  # 합집합
        intersection = []  # 교집합
        for i in union:
            sum_of_sets.extend([i] * max(list1.count(i), list2.count(i)))
            intersection.extend([i] * min(list1.count(i), list2.count(i)))

        return int(len(intersection) / len(sum_of_sets) * 65536)

    return 65536
