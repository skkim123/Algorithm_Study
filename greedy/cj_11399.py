input()
A = sorted(list(map(int, input().split())), reverse=True)
print(sum([A[i]*(i+1) for i in range(len(A))]))