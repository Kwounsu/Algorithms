from collections import defaultdict


def solution(record):
    answer = []
    uid_nickname = defaultdict(str)

    for r in record:
        r = r.split()
        if r[0] == 'Change':
            uid_nickname[r[1]] = r[2]
        elif r[0] == 'Enter':
            uid_nickname[r[1]] = r[2]
            answer.append([r[1], '님이 들어왔습니다.'])
        elif r[0] == 'Leave':
            answer.append([r[1], '님이 나갔습니다.'])

    return [uid_nickname[line[0]] + line[1] for line in answer]
