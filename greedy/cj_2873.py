import sys
input = sys.stdin.readline


def neighbor(i, j):
    nexts = list(filter(lambda x: (0 <= x[0] < R and 0 <= x[1] < C),[[i + dr[k], j + dc[k], directions[k]] for k in range(4)]))
    nexts = list(filter(lambda x: connected[x[0]][x[1]],nexts))
    for node in nexts: connected[node[0]][node[1]] -= 1
    return nexts

R, C = map(int, input().split())
G = [list(map(int, input().split())) for i in range(R)]
connected = [[3 if j == 0 or j == C-1 or i == 0 or i == R-1 else 4 for j in range(C)] for i in range(R)]
connected[0][0] = connected[0][C-1] = connected[R-1][0] = 2
connected[R-1][C-1] = 5
route = ['Start']
dr = [-1, 0, 0, 1]
dc = [0, -1, 1, 0]
directions = ['U', 'L', 'R', 'D']
par_R, par_C = R % 2, C % 2

if not(par_R or par_C):
    min_i, min_j = 0, 1
    for i in range(R):
        for j in range(C):
            if (i + j) % 2:
                if G[i][j] < G[min_i][min_j]:
                    min_i, min_j = i, j
    connected[min_i][min_j] = 0
    neighbor(min_i, min_j)

i, j = 0, 0
while (i, j) != (R-1, C-1):
    connected[i][j] = 0
    nexts = neighbor(i,j)
    next_i, next_j, nextdir = min(nexts, key = lambda x: (connected[x[0]][x[1]] != 1, x[0] + x[1], not(x[2] == route[-1])))
    route.append(nextdir)
    i = next_i
    j = next_j
print(''.join(route[1:]))
