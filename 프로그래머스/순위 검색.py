from bisect import bisect_left


def solution(info, query):
    data = {}
    for a in ['cpp', 'java', 'python', '-']:
        for b in ['backend', 'frontend', '-']:
            for c in ['junior', 'senior', '-']:
                for d in ['chicken', 'pizza', '-']:
                    data[(a, b, c, d)] = []
        
    for i in info:
        i = i.split()
        for a in [i[0], '-']:
            for b in [i[1], '-']:
                for c in [i[2], '-']:
                    for d in [i[3], '-']:
                        data[(a, b, c, d)].append(int(i[4]))

    for k in data:
        data[k].sort()

    answer = list()
    for q in query:
        q = q.split()
        
        pool = data[(q[0], q[2], q[4], q[6])]
        find = int(q[7])
        
        answer.append(len(pool) - bisect_left(pool, find))

    return answer
