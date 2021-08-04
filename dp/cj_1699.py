#아니 이게 이렇게 느릴 코든가..? topdown으로 하면 스택 터질 것 같아서 bottomup으로 짰는디...
import math

def keora(i):
    max_component = math.floor(math.sqrt(i))
    memojang[i] = 1 + min([memojang[i-(j+1)**2] for j in range(max_component)])


n = int(input())
memojang = [0 for i in range(n+1)]

for i in range(1, n+1): keora(i)
print(memojang[n])
