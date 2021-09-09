def Hanoi(plates, start, end, left):
    if plates == 1:
        ans[0] += 1
        ans.append(str(start)+' '+str(end))
        return 0
    else: 
        Hanoi(plates-1,start,left,end)
        Hanoi(1,start,end,left)
        Hanoi(plates-1,left,end,start)

N = int(input())
ans = [0]
Hanoi(N, 1, 3, 2)
for a in ans: print(a)