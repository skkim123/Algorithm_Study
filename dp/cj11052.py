n = int(input())
price = list(map(int, input().split()))

memo = [0 for i in range(n+1)]
memo[1] = price[1]
for i in range(1, n+1):
    memo[i] = max([price[j-1] + memo[i-j] for j in range(1,i+1)])

print(memo[n])
