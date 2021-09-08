import sys
input = sys.stdin.readline

papnum = [0,0,0]
def count(Paper, r_i, c_i, side):
    temp = Paper[r_i][c_i]
    if side == 1:
        papnum[temp + 1] += 1
        return None
    for r in range(r_i, r_i + side):
        for c in range(c_i, c_i + side):
            if Paper[r][c] != temp:
                count(Paper, r_i, c_i, side//3) 
                count(Paper, r_i, c_i+side//3, side//3) 
                count(Paper, r_i, c_i+2*side//3, side//3) 
                count(Paper, r_i+side//3, c_i, side//3) 
                count(Paper, r_i+side//3, c_i+side//3, side//3) 
                count(Paper, r_i+side//3, c_i+2*side//3, side//3) 
                count(Paper, r_i+2*side//3, c_i, side//3) 
                count(Paper, r_i+2*side//3, c_i+side//3, side//3) 
                count(Paper, r_i+2*side//3, c_i+2*side//3, side//3) 
                return None
    papnum[temp + 1] += 1
    return None

N = int(input())
Paper = [list(map(int, input().split())) for n in range(N)]
count(Paper, 0, 0, N)
for p in papnum: print(p)
