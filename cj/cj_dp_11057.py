def keora(n):
    if n == 0:
        memojang[n] = [1 for j in range(10)]
        return 1
    for i in range(10):
        for j in range(i+1):
            memojang[n][i] += memojang[n-1][j]
    return 1


while True:
    n = int(input())
    memojang = [[0 for j in range(10)] for i in range(n)]
    print(memojang)
    for i in range(n): keora(i)
    print(sum(memojang[n-1]) % 10007)
