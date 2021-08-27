from collections import deque
import sys
input = sys.stdin.readline

N = int(input())
adj = [[] for i in range(N+1)] #(adj, distance) 형태로 저장
edges = [0 for i in range(N+1)]
for e in range(N-1):
    p, c, d = map(int, input().split())
    adj[p].append((c, d))
    adj[c].append((p, d))
    edges[p] += 1
    edges[c] += 1

q = deque()

distance = [[0,0] for i in range(N+1)] # [1st, 2nd]
diameter = 0

for i in range(1, N+1):
    if edges[i] == 1: q.append(i)

while q:
    cur = q.popleft()
    edges[cur] -= 1
    diameter = max(sum(distance[cur]), diameter)
    for a in adj[cur]:
        node, edgelen = a[0], a[1]
        if edges[node] > 0:
            edges[node] -= 1
            new = distance[cur][0] + edgelen
            if new >= distance[node][0]:
                distance[node][1] = distance[node][0]
                distance[node][0] = new
            elif new >= distance[node][1]:
                distance[node][1] = new
            if edges[a[0]] == 1: q.append(a[0])

print(diameter)
