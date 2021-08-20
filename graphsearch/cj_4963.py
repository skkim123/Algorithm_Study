import sys
input = sys.stdin.readline

def Adj(cur,w,h):
    adj = []
    dx = [-1, 0, 1, -1, 1, -1, 0, 1]
    dy = [-1, -1, -1, 0, 0, 1, 1, 1]
    for i in range(8):
        nx = cur[1] + dx[i]
        ny = cur[0] + dy[i]
        if 0 <= nx < w and 0 <= ny < h:
            adj.append((ny, nx))
    return adj

def BFS(i,j,w,h):
    queue = [(i,j)]
    while queue:
        cur = queue.pop(0)
        if not visited[cur[0]][cur[1]]:
            visited[cur[0]][cur[1]] = True
            for adj in Adj(cur,w,h):
                if map1[adj[0]][adj[1]] and not visited[adj[0]][adj[1]]:
                    queue.append(adj)
    return None


while True:
    w, h = map(int, input().split())
    if (w,h) == (0,0): break
    map1 = [list(map(int, input().split())) for i in range(h)]
    visited = [[False for j in range(w)] for i in range(h)]
    count = 0
    for i in range(h):
        for j in range(w):
            if map1[i][j] and not visited[i][j]:
                BFS(i,j,w,h)
                count += 1
    print(count)