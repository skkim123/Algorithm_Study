def keora(n):
    if n == 0:
        memojang[n] = [0,1,1,1,1,1,1,1,1,1]
        return 1
    for i in range(10):
        lower = 0
        higher = 0
        if i-1 >= 0: lower = memojang[n-1][i-1]
        if i+1 <= 9: higher = memojang[n-1][i+1]
        memojang[n][i] = lower + higher
    return 1


while True:
    n = int(input())
    memojang = [[0 for j in range(10)] for i in range(n)]
    for i in range(n): keora(i)
    print(sum(memojang[n-1]))
