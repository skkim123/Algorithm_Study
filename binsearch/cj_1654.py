import sys
input = sys.stdin.readline

def check(l, cords, N):
    return True if sum([i // l for i in cords]) >= N else False


K, N = list(map(int, input().split()))

cords = []

for i in range(K): cords.append(int(input()))

minlen = 1
maxlen = sum(cords)//N

while maxlen >= minlen:
    newlen = (minlen + maxlen) // 2
    if check(newlen, cords, N): minlen = newlen + 1 #같으면 무한루프
    else: maxlen = newlen - 1 #마찬가지 #한 번 비교로 끝내는 게 binsearch의 장점

print(maxlen)
