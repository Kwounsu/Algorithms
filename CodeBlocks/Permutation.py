from itertools import permutations
a = [1,2,3]
permute = permutations(a,2)
print(list(permute))
'''
결과
'''
[(1,2),(1,3),(2,1),(2,3),(3,1),(3,2)]

from itertools import combinations
a = [1,2,3]
combi = combinations(a,2)
    
print(list(combi))
'''
결과
'''
[(1,2),(1,3),(2,3)]
