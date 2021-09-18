V, H = map(int, input().split())

if V >= 3:
    if H >= 7: print(H-2)
    else: print(min(4, H))
elif V == 2: print(min(4, (H-1)//2 + 1))
else: print(1)
