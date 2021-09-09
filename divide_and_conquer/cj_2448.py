def blank(upper_row, l, N):
    for i in range(l):
        if upper_row + i < N: triangle[upper_row + i].append(' ' * (l-i-1))
    return 0

def make_srpnski_triangle(upper_row,l):
    if l == 3: 
        triangle[upper_row].append('*')
        triangle[upper_row+1].append('* *')
        triangle[upper_row+2].append('*****')
        return 0
    else:
        make_srpnski_triangle(upper_row,l//2)
        make_srpnski_triangle(upper_row + l//2,l//2)
        blank(upper_row + l//2,l//2+1,N)
        blank(upper_row + l//2,l//2,N)
        make_srpnski_triangle(upper_row + l//2,l//2)
    return 0


N = int(input())
triangle = [[] for i in range(N)]
blank(0,N,N)
make_srpnski_triangle(0, N)
blank(0,N,N)
for l in triangle: print(''.join(l))