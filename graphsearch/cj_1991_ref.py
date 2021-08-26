import sys
from collections import deque
input = sys.stdin.readline


def pre(tree):
    stack.append('A')
    trav = []
    while stack:
        cur = stack.pop()
        if cur not in trav:
            trav.append(cur)
            if tree[cur][1] is not None: stack.append(tree[cur][1])
            if tree[cur][0] is not None: stack.append(tree[cur][0])
    return ''.join(trav)

def inorder(tree):
    stack.append('A')
    trav = []
    while stack:
        cur = stack.pop()
        if cur not in trav:
            if tree[cur][1] is not None: stack.append(tree[cur][1])
            if tree[cur][0] is not None and tree[cur][0] not in trav:
                stack.append(cur)
            else: trav.append(cur)
            if tree[cur][0] is not None: stack.append(tree[cur][0])
    return ''.join(trav)

def post(tree):
    stack.append('A')
    trav = []
    while stack:
        cur = stack.pop()
        if cur not in trav:
            if (tree[cur][0] is None or tree[cur][0] in trav) and (tree[cur][1] is None or tree[cur][1] in trav):
                trav.append(cur)
            else:
                stack.append(cur)
            if tree[cur][1] is not None: stack.append(tree[cur][1])
            if tree[cur][0] is not None: stack.append(tree[cur][0])
    return ''.join(trav)


N = int(input())
tree = {}


for i in range(N):
    n, l, r = input().split()
    if l == '.': l = None
    if r == '.': r = None
    tree[n] = [l,r]

stack = deque()

print(pre(tree))
print(inorder(tree))
print(post(tree))

