def keora(n):
    if n == 0: return 1

    if n == 1:
        memojang[0][n] = memojang[1][0] + sticker[0][1]
        memojang[1][n] = memojang[0][0] + sticker[1][1]
        return 1

    higher = max(memojang[0][n-2], memojang[1][n-2])
    memojang[0][n] = sticker[0][n] + max(memojang[1][n-1], higher)
    memojang[1][n] = sticker[1][n] + max(memojang[0][n-1], higher)
    return 1


n = int(input())
for i in range(n):
    l = int(input())
    primero = list(map(int, input().split()))
    segundo = list(map(int, input().split()))
    sticker = [primero, segundo]
    memojang = [[primero[0] for i in range(len(primero))], [segundo[0] for i in range(len(primero))]]
    for i in range(l): keora(i)
    print(max(memojang[0][l-1], memojang[1][l-1]))
