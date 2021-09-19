import sys
input = sys.stdin.readline

N = int(input())
A = []
for i in range(N): A.append(int(input()))
A.sort()
memo = [A[0] for i in range(N)]
if N > 1: memo[1] = max(A[0]*A[1], A[0] + A[1])
for i in range(2, N):
    memo[i] = max(memo[i-1]+A[i], memo[i-2] + A[i-1]*A[i])

print(memo[-1])


