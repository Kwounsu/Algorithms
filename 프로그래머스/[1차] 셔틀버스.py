def to_num_time(str_time):
    mm, ss = map(int, str_time.split(':'))
    return mm * 60 + ss


def to_str_time(num_time):
    mm, ss = map(str, divmod(num_time, 60))
    while len(mm) < 2:
        mm = '0' + mm
    while len(ss) < 2:
        ss = '0' + ss
    return f'{mm}:{ss}'


def solution(n, t, m, timetable):
    bus = {}
    last_bus_time = 540 + (n - 1) * t
    for bus_time in range(540, last_bus_time + 1, t):
        bus[bus_time] = []

    timetable = sorted(list(map(lambda x: to_num_time(x), timetable)))
    for t in timetable:
        for i in bus:
            if t <= i and len(bus[i]) < m:
                bus[i].append(t)
                break

    last_bus = bus[last_bus_time]
    N = len(last_bus)
    if N == 0 or N < m:
        return to_str_time(last_bus_time)

    answer = last_bus[0] - 1
    for t in last_bus:
        if answer + 1 < t:
            answer = t - 1

    return to_str_time(answer)
