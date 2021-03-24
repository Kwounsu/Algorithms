import sys

def solution(n,a):
    answer,stack,count = [],[],0
    for i in a:
        while count < i:
            count+=1
            stack.append(count)
            answer.append('+')
        if stack.pop() != i:
            return 'NO'
        answer.append('-')
        
    return '\n'.join(answer)

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    a = map(lambda x : int(x.rstrip()), sys.stdin.readlines())
    print(solution(n,a))
