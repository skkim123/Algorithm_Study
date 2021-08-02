def keora(n):
    if n == 0:
        memojang[n] = [0, 1]
        return 1
    memojang[n][0] = sum(memojang[n-1])
    memojang[n][1] = memojang[n-1][0]
    return 1


while True:
    n = int(input())
    memojang = [[0 for j in range(2)] for i in range(n)]
    for i in range(n): keora(i)
    print(sum(memojang[n-1]))
