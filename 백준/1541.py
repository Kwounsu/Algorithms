import sys

formula = sys.stdin.readline()
f1 = formula.split('-')
for i, f in enumerate(f1):
    if '+' in f:
        f2 = f.split('+')
        val = sum([int(n) for n in f2])
        f1[i] = val
    else:
        f1[i] = int(f)

print(f1[0] - sum(f1[1:]))
        
