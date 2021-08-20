import sys
input = sys.stdin.readline

def Adj(cur,size):
    adj = []
    if cur[0] != 0: adj.append((cur[0]-1, cur[1]))
    if cur[0] != size-1: adj.append((cur[0]+1, cur[1]))
    if cur[1] != 0: adj.append((cur[0], cur[1]-1))
    if cur[1] != size-1: adj.append((cur[0], cur[1]+1))
    return adj

def BFS(i,j,size):
    queue = [(i,j)]
    count = 0
    while queue:
        cur = queue.pop(0)
        if not visited[cur[0]][cur[1]]:
            visited[cur[0]][cur[1]] = True
            count +=1
            for adj in Adj(cur,size):
                if map1[adj[0]][adj[1]] and not visited[adj[0]][adj[1]]:
                    queue.append(adj)
    return count


size = int(input())
map1 = [list(map(int, list(input())[:-1])) for i in range(size)]
visited = [[False for j in range(size)] for i in range(size)]
house = []
for i in range(size):
    for j in range(size):
        if map1[i][j] and not visited[i][j]: house.append(BFS(i,j,size))
print(len(house))
for h in sorted(house): print(h)


