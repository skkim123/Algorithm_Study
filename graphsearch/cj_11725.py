from collections import deque
import sys
input = sys.stdin.readline


N = int(input())

adj = {i : [] for i in range(N+1)}
parent = [None for i in range(N+1)] # 1 빼고는 다 parent가 None이 아니기 때문에 visited로도 활용 가능

for i in range(N-1): #tree의 node가 N개일 때 edge는 N-1개
    a, b  = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

stack = deque()
stack.append(1)
parent[1] = 0 # 1 바로 다음 노드에서 adj를 조사할 때 1이 stack에 추가될 수 있으므로 임의로 0으로 잡음

while stack:
    cur = stack.pop()
    for next in adj[cur]:
        if parent[next] is None:
            parent[next] = cur
            stack.append(next)

for i in range(2, N+1):
    print(parent[i])
