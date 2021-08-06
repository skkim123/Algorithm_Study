def tiles(n):
    if n % 2 == 1: return 0
    memo = [1 for i in range(n//2 + 1)]
    memo[1] = 3
    for i in range(2, n//2 + 1):
        memo[i] = 3 * memo[i-1] + 2 * sum(memo[:i-1])
    return memo[-1]


print(tiles(int(input())))