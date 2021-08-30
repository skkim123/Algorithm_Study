import sys
input = sys.stdin.readline

def check(d, house, C):
    count = 1
    cur = 0
    while cur < len(house):
        i = 1
        while cur + i < len(house) and house[cur + i] - house[cur] < d:
            i += 1
        cur += i
        if cur < len(house):
            count += 1
    return True if count >= C else False


N, C = map(int, input().split())
house = []
for i in range(N):
    house.append(int(input()))

house.sort()

l = 1
r = (max(house) - min(house)) // (C-1) + 1

while l <= r:
    mid = (l + r) // 2
    if check(mid, house, C):
        l = mid + 1
    else: r = mid - 1
print(r)