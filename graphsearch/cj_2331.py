D1, P = map(int, input().split())
D = [D1]

while True:
    cur = D[-1]
    next = 0
    while cur > 0:
        next += pow(cur % 10, P)
        cur = cur // 10
    if next in D:
        print(D.index(next))
        break
    D.append(next)