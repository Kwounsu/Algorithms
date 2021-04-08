import collections


def solution(N, stages):
    fail_percent = [[0, i] for i in range(1, N + 1)]
    counts = collections.Counter(stages)
    
    # get number of players of each stages
    players = [0] * N
    for c in counts:
        r = c if c <= N else N
        for i in range(r):
            players[i] += counts[c]
    
    # calculate fail percent
    for i in range(N):
        if players[i] > 0:
            fail_percent[i][0] = counts[i + 1] / players[i]
        else:
            fail_percent[i][0] = 0
    
    # sort stages by fail percent
    fail_percent.sort(key=lambda x: (x[0], -x[1]), reverse = True)
    x, answer = zip(*fail_percent)
    
    return list(answer)
