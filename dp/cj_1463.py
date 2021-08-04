dict = {1: 0}

def memo(X):
    if X in dict.keys(): return dict[X]
    min = dict[X-1]
    if (X % 2 == 0) and dict[X//2] < min: min = dict[X//2]
    if (X % 3 == 0) and dict[X//3] < min: min = dict[X//3]
    dict[X] = 1 + min
    return 1


while True:
    N = int(input())
    for i in range(1, N + 1): memo(i)
    print(dict[N])
