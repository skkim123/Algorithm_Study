n = int(input())
stairs = [0]
for i in range(n):
    stairs.append(int(input()))

memo = [0 for i in range(n+1)]
memo[1] = stairs[1]

for i in range(2, n+1):
    memo[i] = stairs[i] + max(stairs[i-1] + memo[i-3], memo[i-2])

print(memo[n])