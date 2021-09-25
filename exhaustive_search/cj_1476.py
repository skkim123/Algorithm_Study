r = list(map(int, input().split()))
n = [6916, 4845, 4200]
print((sum([r[i]*n[i] for i in range(3)])-1) % 7980 + 1)