# binary search: check if element is in given interval
# Hash search with set or dict is more effective when we have to check if elemnet is in list
# in dict = in dict.keys() != in dict.values
# map(lambda element -similar as f(x)-: some fcn, iterable)
input()
sg = {}
for card in input().split():
    if card not in sg:
        sg[card] = 1
    else: sg[card] += 1
input()
print(' '.join(map(lambda card: str(sg[card]) if card in sg else '0', input().split())))

