def gcd(a, b):
    if a < b:
        a, b = b, a
    while b:
        a, b = b, a % b
    return a

def gcd(a, b):
    return gcd(b, a % b) if b else a

def lcm(a, b):
    return a * b // gcd(a, b)
