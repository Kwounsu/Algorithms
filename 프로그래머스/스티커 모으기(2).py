def solution(a):
    if len(a) < 4:
        return max(a)
    
    dp1, dp2 = [a[0], 0, a[0] + a[2]], [0, a[1], a[2]]
    
    for i in range(3, len(a)):
        dp1.append(a[i] + max(dp1[i - 2], dp1[i - 3]))
        dp2.append(a[i] + max(dp2[i - 2], dp2[i - 3]))
        
    return max(max(dp1[:-1]), max(dp2))
