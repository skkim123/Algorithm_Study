from collections import deque
import sys
input = sys.stdin.readline


def bridge_BFS(N, border, mod):
    bridge = 2*N
    bridge_made = False
    while border:
        y, x = border.popleft()
        for a in range(4):
            ny = y + dy[a]
            nx = x + dx[a]
            if 0 <= ny < N and 0 <= nx < N:
                if not colored_world[ny][nx] and not bridge_made:
                    colored_world[ny][nx] = colored_world[y][x] + mod
                    border.append((ny,nx))
                elif (colored_world[ny][nx] % mod) != (colored_world[y][x] % mod):
                    bridge = min(bridge, colored_world[ny][nx] // mod + colored_world[y][x] // mod)
    return bridge



N = int(input())

world = [list(map(int, input().split())) for i in range(N)]

continent_num = 0
colored_world = [[0 for j in range(N)] for i in range(N)]
q = deque()
border = deque()
dx = [0,-1,1,0]
dy = [-1,0,0,1]

for i in range(N): #row
    for j in range(N): #col
        if world[i][j] and not colored_world[i][j]:
            continent_num += 1
            colored_world[i][j] = continent_num
            q.append((i,j))
            while q:
                y, x = q.popleft()
                border_checked = False
                for a in range(4):
                    ny = y + dy[a]
                    nx = x + dx[a]
                    if 0 <= ny < N and 0 <= nx < N:
                        if world[ny][nx] and not colored_world[ny][nx]:
                            q.append((ny,nx))
                            colored_world[ny][nx] = continent_num
                        elif not world[ny][nx] and not border_checked:
                            border_checked = True
                            border.append((y,x))

print(bridge_BFS(N, border, continent_num+1))
