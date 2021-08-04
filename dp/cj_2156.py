#3칸은 건너뛸 수 없다
def keora(n):
    if n == 1:
        memojang[n] = wines[1]
        return 1
    if n == 2:
        memojang[n] = wines[1] + wines[2]
        return 1
    memojang[n] = wines[n] + max(memojang[n-2], wines[n-1] + memojang[n-3], wines[n-1] + memojang[n-4])


n = int(input())
wines = [0]
for i in range(n):
    wines.append(int(input()))

memojang = [0 for i in range(n+1)]
for i in range(n): keora(i+1)
print(max(memojang[n-1:])) #어차피 둘 중 하나
