girl, boy, intern = map(int, input().split())

print(min(girl//2, boy, (girl+boy - intern)//3))

