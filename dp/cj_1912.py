#수업 때 배웠을 때는 i번째에서 메모를 할 때
# i-1번째까지의 최대합(i-1번째 포함 안 해도 됨), i번째 아이템, i부터 왼쪽으로 더했을 때 최대
#3개를 비교해서 마지막에 메모한 배열을 최대값 찾으려고 한 번 더 도는 게 아니라 바로 답을 도출했던 것 같은데
#이렇게 짜는 게 시간복잡도가 더 낫지 않나...? 어케 생각?
n = int(input())
seq = list(map(int, input().split()))

memojang = [seq[0] for i in range(n)]

for i in range(1, n):
    memojang[i] = max(seq[i], seq[i] + memojang[i-1])

print(max(memojang))
