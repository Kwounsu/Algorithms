def solution(dirs):
    d_idx = {'U': [-1, 0], 'D': [1, 0], 'L': [0, -1], 'R': [0, 1]}
    path = set()
    loc = [0, 0]

    for d in dirs:
        new_loc = [loc[0] + d_idx[d][0], loc[1] + d_idx[d][1]]
        if -5 <= new_loc[0] <= 5 and -5 <= new_loc[1] <= 5:
            new_path = ''.join(map(str, loc + new_loc))
            if ''.join(map(str, new_loc + loc)) not in path:
                path.add(new_path)
            loc = new_loc

    return len(path)
