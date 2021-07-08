import sys
input = sys.stdin.readline

def solution(n, arr):
    def scan():
        ret = []
        for i in range(n):
            if abs(arr[i] - arr[(i + 1) % n]) != 1 and abs(arr[i]-arr[(i+1)%n]) !=n-1:
                ret.append((i+1) % n)
        return ret
    
    def right_rotated():
        return [arr[-1]] + arr[:-1]
    
    def reverse(s, e):
        return arr[:s] + arr[s:e][::-1] + arr[e:]
    
    for i in range(1, n):
        arr = right_rotated()
        
        l = scan()
        if not l:
            l.append(0)
            l.append(n)
        if l[0] > l[1]:
            l[0], l[1] = l[1], l[0]
        
        arr = reverse(l[0], l[1])
        
        if len(scan()) == 0 and arr[0] != 1 and arr[1] - arr[0] == 1:
            print(arr[0] - 1)
            print(l[0] + 1, l[1])
            print(i)
            return
        
        arr = reverse(l[0], l[1])
        

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    solution(n, arr)
