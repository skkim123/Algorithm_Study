def blank(upper_row, l):
    for i in range(l):
        square[upper_row + i].append(' ' * l)
    return 0

def make_srpnski_carpet(upper_row,l):
    if l == 1: 
        square[upper_row].append('*')
        return 0
    else:
        make_srpnski_carpet(upper_row,l//3)
        make_srpnski_carpet(upper_row,l//3)
        make_srpnski_carpet(upper_row,l//3)
        make_srpnski_carpet(upper_row + l//3,l//3)
        blank(upper_row + l//3,l//3)
        make_srpnski_carpet(upper_row + l//3,l//3)
        make_srpnski_carpet(upper_row + 2*l//3,l//3)
        make_srpnski_carpet(upper_row + 2*l//3,l//3)
        make_srpnski_carpet(upper_row + 2*l//3,l//3)
    return 0


N = int(input())
square = [[] for i in range(N)]
make_srpnski_carpet(0,N)
for l in square: print(''.join(l))