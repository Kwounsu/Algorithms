def get_divisor(n: int):
    factors = []
    factors_rev = []
    
    for i in range(1, int(n**(0.5)) + 1):
        if n % i == 0:
            factors.append(i)
            if n // i != i:
                factors_rev.append(n // i)

    return factors + factors_rev[::-1]
