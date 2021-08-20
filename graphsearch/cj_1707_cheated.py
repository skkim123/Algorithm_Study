import sys
input = sys.stdin.readline

def BFS(i):
    queue = [i]
    visited[i] = 1
    while len(queue) > 0:
        cur = queue.pop(0)
        for next in Adj[cur]:
            if not visited[next]:
                visited[next] = -visited[cur]
                queue.append(next)
            elif visited[next] == visited[cur]: return 0
    return 1

cases = int(input())

for c in range(cases):
    V, E = map(int, input().split())
    Adj = {i: [] for i in range(1, V+1)}
    for e in range(E):
        a, b = list(map(int, input().split()))
        Adj[a].append(b)
        Adj[b].append(a)
    visited = [0 for i in range(V+1)]
    is_bipartite = 1
    for i in range(1, V+1):
        if not visited[i]:
            if not BFS(i):
                is_bipartite = 0
                print("NO")
                break
    if is_bipartite: print("YES")