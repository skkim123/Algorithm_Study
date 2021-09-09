import sys
input = sys.stdin.readline


def quad(BnW, r_i, c_i, side):
    temp = BnW[r_i][c_i]
    if side == 1:
        quaded.append(temp)
        return None
    for r in range(r_i, r_i + side):
        for c in range(c_i, c_i + side):
            if BnW[r][c] != temp:
                quaded.append('(')
                quad(BnW, r_i, c_i, side//2) 
                quad(BnW, r_i, c_i+side//2, side//2) 
                quad(BnW, r_i+side//2, c_i, side//2) 
                quad(BnW, r_i+side//2, c_i+side//2, side//2) 
                quaded.append(')')
                return None
    quaded.append(temp)
    return None

N = int(input())
BnW = [list(input().strip()) for n in range(N)]
quaded = []
quad(BnW, 0, 0, N)
print(''.join(quaded))
