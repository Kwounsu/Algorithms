import sys
input = sys.stdin.readline


parent = dict()
# children = defaultdict(list)
n = int(input())
# root_check = [True] * (n+1)
# root_check[0] = False

for _ in range(n-1):
    p, c = map(int, input().split())
    parent[c] = p
#     children[p].append(c)
#     root_check[c] = False
# root = root_check.index(True)

# depth = {root:0}
# stack = [(root, 0)]
# visit = [False] * (n + 1)
# while stack:
#     cur, d = stack.pop()
#     visit[cur] = True
#     depth[cur] = d
#     for c in children[cur]:
#         if not visit[c]:
#             stack.append((c, d+1))

# 더 나은 방법: 높이를 맞춰준 뒤 제곱으로 부모로 올라감
# 현재 방법: 한 노드에서 루트까지 부모를 타고 올라가며 기록,
#           다른 노드에서 같은방법을 하다가 기록된 노드 만나면 lca
def slow_lca(a, b):
    visit = [False] * (n+1)
    visit[a] = True
    try:
        while True:
            a = parent[a]
            visit[a] = True
    except:
        if visit[b]:
            return b
        try:
            while True:
                b = parent[b]                
                if visit[b]:
                    return b
        except:
            pass

    
a, b = map(int, input().split())
print(slow_lca(a, b))
