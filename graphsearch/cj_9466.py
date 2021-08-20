import sys
input = sys.stdin.readline

case = int(input())

for c in range(case):
    length = int(input())
    choice = list(map(int, input().split()))
    visited = [False for i in range(length+1)]
    outsider = 0
    for i in range(1, length+1):
        route = [i]
        while not visited[i]:
            visited[i] = True
            route.append(choice[i-1])
            i = choice[i-1]
        outsider += len(route[:route.index(i)])

    print(outsider)