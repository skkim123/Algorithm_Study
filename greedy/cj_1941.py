import sys
input = sys.stdin.readline

N = int(input())
conference = []
for i in range(N): conference.append(list(map(int, input().split())))
conference.sort(key = lambda x: (x[1], x[0]))
count = 0
end = 0
for i in conference:
    if i[0] >= end:
        count += 1
        end = i[1]

print(count)