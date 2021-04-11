def solution(arr):
    def gcd(a, b):
        if a < b:
            a, b = b, a
        while b:
            a, b = b, a % b
        return a
    
    def lcm(a, b):
        return a * b // gcd(a, b)
    
    x = arr[0]
    for i in range(1, len(arr)):
        x = lcm(x, arr[i])
    
    return x
