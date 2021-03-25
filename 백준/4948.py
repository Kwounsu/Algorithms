def sieve_of_Eratosthenes(n):
    sieve = [0, 0] + [1]*(n-1)
    p_range = int(n**0.5)+1
    for i in range(2, p_range):
        if sieve[i]:
            for j in range(i*2, n+1, i):
                sieve[j] = 0
    return sieve

a = list(map(lambda x : int(x.rstrip()), sys.stdin.readlines()))[:-1]
s = sieve_of_Eratosthenes(max(a)*2)
for n in a:
    print(sum(s[n+1:n*2+1]))
