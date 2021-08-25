from collections import deque
import sys
input = sys.stdin.readline

def BFS(row, col):
    q = deque()
    q.append((0, 0))
    visited[0][0] = 1
    dc = [0, -1, 1, 0]
    dr = [-1, 0, 0, 1]
    while q:
        i, j = q.popleft()
        for a in range(4):
            i_n = i + dr[a]
            j_n = j + dc[a]
            if 0 <= i_n < row and 0 <= j_n < col and maze[i_n][j_n] and not visited[i_n][j_n]:
                visited[i_n][j_n] = visited[i][j] + 1
                if (i_n, j_n) == (row - 1, col - 1):
                    return visited[i_n][j_n]
                q.append((i_n,j_n))
    return 1

row, col = map(int, input().split())
maze = [list(map(int, list(input())[:-1])) for i in range(row)]

visited = [[0 for j in range(col)] for i in range(row)]

print(BFS(row,col))