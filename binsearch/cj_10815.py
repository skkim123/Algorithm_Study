import sys
input = sys.stdin.readline

input()
sg = set(input().split())
input()
print(' '.join(map(lambda card: '1' if card in sg else '0', input().split())))