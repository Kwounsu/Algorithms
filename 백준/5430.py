from sys import stdin, stdout


def AC(command, n, a):
    command.replace('RR', '')
    l, r, d = 0, 0, True
    for c in command:
        if c == 'R': 
            d = not d
        elif c == 'D':
            if d: 
                l += 1
            else: 
                r += 1
    if l + r <= n:
        res = a[l:n - r]
        if d: 
            return '[' + ','.join(res) + ']\n'
        else: 
            return '[' + ','.join(res[::-1]) + ']\n'
    else:
        return 'error\n'


T = int(stdin.readline())
for _ in range(T):
    com = stdin.readline()
    n = int(stdin.readline())
    a = stdin.readline().rstrip()[1:-1].split(',')
    if n == 0 : 
        a = []
    stdout.write(AC(com, n, a))
