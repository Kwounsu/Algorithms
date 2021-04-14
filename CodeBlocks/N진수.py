def n_ary(n, base):
    T = "0123456789ABCDEF"
    q, r = divmod(n, base)
    return T[r] if q == 0 else n_ary(q, base) + T[r]

        
# def n_ary(n, base):
#     result = []
#     while n > 0:
#         n, r = divmod(n, base)
#         result.append(r)
#     return ''.join(map(str, reversed(result)))
