import re


def solution(user_id, banned_id):
    def is_match(ban, user):
        regex = ban.replace('*', '.') + '$'
        if re.match(regex, user):
            return True
        return False

    matching_list = [list() for _ in range(len(banned_id))]

    for i, ban in enumerate(banned_id):
        for j, user in enumerate(user_id):
            if is_match(ban, user):
                matching_list[i].append(j)

    answer = set()

    N = len(matching_list)
    for i in matching_list[0]:
        stack = [[i, 0, [i]]]
        while stack:
            cur, idx, visit = stack.pop()
            if idx + 1 < N:
                for j in matching_list[idx + 1]:
                    if j not in visit:
                        stack.append([j, idx + 1, visit + [j]])
            else:
                answer.add(','.join(map(str, sorted(visit))))

    return len(answer)
