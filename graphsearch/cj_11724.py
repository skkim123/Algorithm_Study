#어차피 다 순회해야되니 adj도 다 할당해놓으면 예외처리 할 필요x
def DFS(Adj, starting):
    stack = [starting]
    while len(stack) > 0:
        cur = stack.pop()
        visited[cur-1] = True
        for node in Adj[cur]:
            if not visited[node-1]: stack.append(node)
    return None


V, E = map(int, input().split())
Adj = {i: [] for i in range(1,V+1)}
for e in range(E):
    a, b = list(map(int, input().split()))
    Adj[a].append(b)
    Adj[b].append(a)

visited = [False for i in range(V)]
connected_comp = 0
for v in range(1, V+1):
    if not visited[v-1]:
        DFS(Adj, v)
        connected_comp += 1

print(connected_comp)