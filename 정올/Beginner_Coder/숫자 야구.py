import sys
input = sys.stdin.readline


possible = []
for i in range(1, 10):
    for j in range(1, 10):
        for k in range(1, 10):
            if i != j != k != i:
                possible.append([i, j, k])
            
N = int(input())
for _ in range(N):
    guess, match, include = map(int, input().split())
    
    if match == 3:
        possible = [guess]
        break
    
    a, b, c = guess // 100, (guess % 100) // 10, guess % 10
    
    new = []
    for l in possible:
        strike, ball = 0, 0
        if a == l[0]:
            strike += 1
        elif a in l:
            ball += 1
        if b == l[1]:
            strike += 1
        elif b in l:
            ball += 1
        if c == l[2]:
            strike += 1
        elif c in l:
            ball += 1
        
        if match == strike and include == ball:
            new.append(l)
    possible = new
    
    
print(len(possible))
