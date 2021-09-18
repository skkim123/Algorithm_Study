N, K = map(int, input().split())
coins = []
i = -1
for j in range(N):
    c = int(input())
    if c <= K: i += 1
    coins.append(c)

count = 0

for j in range(i, -1, -1):
    count += K//coins[j]
    K = K % coins[j]

print(count)
