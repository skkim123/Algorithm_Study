n = int(input())
seq = list(map(int, input().split()))

memojang = [[1, 1] for i in range(n)]

for i in range(1, n):
    ascending = [memojang[j][0] for j in range(i) if seq[j] < seq[i]]
    ascending.append(0)
    memojang[i][0] = 1 + max(ascending)

    descending = [memojang[n-1-j][1] for j in range(i) if seq[n-1-j] < seq[n-1-i]]
    descending.append(0)
    memojang[n-1-i][1] = 1 + max(descending)

bitonic = [sum(i) - 1 for i in memojang]
print(max(bitonic))
