import sys
input = sys.stdin.readline

def check(h, trees, M):
    return True if sum((i - mid) * (i-mid >= 0) for i in trees) >= M else False

N, M = map(int, input().split())
trees = list(map(int, input().split()))

l = 0
r = max(trees)

while l <= r:
    mid = (l + r) // 2
    if check(mid, trees, M):
        l = mid + 1
    else: r = mid - 1

print(r)






