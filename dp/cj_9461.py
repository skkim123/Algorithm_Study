cases = int(input())

for case in range(cases):
    n = int(input())
    memo = [0, 1, 1, 1, 2]
    for i in range(5, n + 1):
        memo.append(memo[i - 5] + memo[i - 1])
    print(memo[n])
