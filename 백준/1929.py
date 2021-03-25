import sys

def sieve_of_Eratosthenes(N):
    sieve = [False, False] + [True]*(N-1)
    p_range = int(N**0.5)+1
    for i in range(2, p_range):
        if sieve[i]:
            for j in range(i*2, N+1, i):
                sieve[j] = False
    return sieve

M,N = map(int,sys.stdin.readline().split())
sieve = sieve_of_Eratosthenes(N)
for i in range(M,N+1):
    if sieve[i]:
        print(i)
