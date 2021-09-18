N = list(map(int, input()))

A = [0 for i in range(10)]
sum = 0
max30 = -1
for n in N:
    A[n] += 1
    sum += n

if A[0] and not sum % 3:
    max30 = int(''.join([str(i) * A[i] for i in range(9, -1, -1)]))

print(max30) 