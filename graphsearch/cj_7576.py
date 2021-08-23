import sys
from collections import deque
input = sys.stdin.readline


col, row = map(int, input().split())

box = [list(map(int, input().split())) for i in range(row)]

dr = [-1, 0, 0, 1]
dc = [0, -1, 1, 0]
queue = deque()
empty = 0
count = 0
cur = (0,0)

for i in range(row):
    for j in range(col):
        if box[i][j] == 1:
            count += 1
            queue.append((i,j))
        if box[i][j] == -1:
            empty += 1
            count += 1

while queue:
    cur = queue.popleft()
    for i in range(4):
        nr = cur[0] + dr[i]
        nc = cur[1] + dc[i]
        if 0 <= nr < row and 0 <= nc < col and not box[nr][nc]:
            count += 1
            box[nr][nc] = box[cur[0]][cur[1]] + 1
            queue.append((nr, nc))

print(box[cur[0]][cur[1]] - 1 if count == col * row else -1)



