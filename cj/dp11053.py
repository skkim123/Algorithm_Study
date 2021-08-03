def keora(n):
    if n == 0: return 1
    candidates = [memojang[i] for i in range(n) if seq[i] < seq[n]]
    candidates.append(0)
    memojang[n] = 1 + max(candidates)


n = int(input())
seq = list(map(int, input().split()))

memojang = [1 for i in range(n)]
for i in range(n): keora(i)
print(max(memojang))
