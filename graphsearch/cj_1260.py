#고립 노드가 많아서 딕셔너리가 효과적
#근데 고립노드에서 시작하면 딕셔너리가 비네...
#class하고 implicit representation으로도 짜보기
def DFS(Adj, starting):
    visited = []
    stack = [starting]
    while len(stack) > 0 :
        cur = stack.pop()
        if cur not in visited: visited.append(cur)
        try:
            sorted_adj = sorted(Adj[cur], reverse= True)
        except(KeyError): return [starting]
        for node in sorted_adj:
            if node not in visited: stack.append(node)
    return visited

def BFS(Adj, starting):
    visited = []
    queue = [starting]
    while len(queue) > 0 :
        cur = queue.pop(0)
        if cur not in visited: visited.append(cur)
        try:
            sorted_adj = sorted(Adj[cur])
        except(KeyError): return [starting]
        for node in sorted_adj:
            if node not in visited: queue.append(node)
    return visited

V, E, starting = map(int, input().split())
Adj = {}
for e in range(E):
    nodes = list(map(int, input().split()))
    for i in range(2):
        if nodes[i] not in Adj.keys():
            Adj[nodes[i]] = [nodes[1-i]]
        else: Adj[nodes[i]].append(nodes[1-i])

print(' '.join(map(str, DFS(Adj, starting))))
print(' '.join(map(str, BFS(Adj, starting))))
