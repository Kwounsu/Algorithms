from collections import defaultdict
from bisect import bisect_left, bisect_right


def count_by_range(lst, start, end):
    return bisect_right(lst, end) - bisect_left(lst, start)


def solution(words, queries):
    answer = []

    # store words in length category
    dict = defaultdict(list)
    reverse_dict = defaultdict(list)
    for word in words:
        dict[len(word)].append(word)
        reverse_dict[len(word)].append(word[::-1])

    # sorting O(NlogN)
    for string in dict.values():
        string.sort()
    for string in reverse_dict.values():
        string.sort()

    # Search O(NlogM)
    for query in queries:
        if query[0] == '?':  # if prefix is wildcard
            lst = reverse_dict[len(query)]
            start, end = query[::-1].replace('?', 'a'), query[::-1].replace('?', 'z')
        else:  # if suffix is wildcard
            lst = dict[len(query)]
            start, end = query.replace('?', 'a'), query.replace('?', 'z')
        answer.append(count_by_range(lst, start, end))

    return answer
