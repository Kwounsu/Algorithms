import sys,time
input = sys.stdin.readline

# 페르마의 소정리
# p:소수, a:정수 => a^(p-2) % p = (1/a) % p

# 즉, n!%p / (k!(n-k)!)%p = n!%p * (k!(n-k)!)^(p-2)%p

def C(n,k):
    p = 1000000007
    top, bottom = 1, 1
    
    for i in range(k+1, n+1):
        top = (top*i)%p
    for i in range(1, n-k+1):
        bottom = (bottom*i)%p
    
    bottom = pow(bottom,p-2,p) # a^(p-2) % p
    return (top*bottom)%p
    
if __name__=="__main__":
    s=time.time()
    
    n, k = map(int, input().split())    
    print(C(n,k))
    
    print(time.time()-s)
