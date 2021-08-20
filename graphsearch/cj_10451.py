case = int(input())

for c in range(case):
    length = int(input())
    visited = [False for i in range(length)]
    perm = list(map(int, input().split()))
    cycle = 0
    for i in range(length):
        cycled = 0
        while not visited[i]:
            cycled = 1
            visited[i] = True
            i = perm[i] - 1
        if cycled: cycle += 1
    print(cycle)
