from collections import deque, defaultdict


def solution(n, edges):
    # find farthest node from the assigned node using dfs
    def dfs(node):
        q = deque([node])
        visited = [-1] * (n + 1)
        visited[node] = 0
        farthest = [0, [], 0]  # max_value, node_index, total_farthest_count

        while q:
            cur = q.popleft()
            for neighbor in graph[cur]:
                if visited[neighbor] == -1:
                    visited[neighbor] = visited[cur] + 1
                    q.append(neighbor)

                    # renew farthest
                    if farthest[0] < visited[neighbor]:
                        farthest = [visited[neighbor], [neighbor], 1]
                    elif farthest[0] == visited[neighbor]:
                        farthest[1].append(neighbor)
                        farthest[2] += 1

        return farthest

    # make graph
    graph = defaultdict(list)
    for a, b in edges:
        graph[a].append(b)
        graph[b].append(a)

    # find farthest node from random node
    end1 = dfs(1)
    # find "diameter"(지름)
    end2 = dfs(end1[1][0])

    if end2[2] >= 2:  # "diameter" is a "medium" if there are more than two diameters found
        return end2[0]
    else:
        # it couldn't find diameter before because it started from random node
        # but, it must be a diameter this time
        end3 = dfs(end2[1][0])
        if end3[2] >= 2:
            return end3[0]
        else:  # if it's a single line
            return end3[0] - 1
