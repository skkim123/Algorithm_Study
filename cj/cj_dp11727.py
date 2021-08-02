#11726은 생략
dict = {1: 1, 2: 3}

def memo(n):
    if n in dict.keys(): return 1
    dict[n] = dict[n-1] + 2 * dict[n-2]
    return 1

while True:
    n = int(input())
    for i in range(1, n+1): memo(i)
    print(dict[n] % 10007)
    print(dict)
