N, K = map(int, input().split())

memo = [[1 for i in range(N+1)] for j in range(K)]
for i in range(1, K):
    for j in range(1, N+1):
        memo[i][j] = memo[i-1][j] + memo[i][j-1]
print(memo[K-1][N] % 1000000000)