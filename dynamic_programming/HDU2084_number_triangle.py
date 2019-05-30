layer = int(input())
li = []
for i in range(layer):
    li.append([int(x) for x in input().split()])

while layer > 1:
    for i in range(1, layer):
        li[layer-2][i-1] += li[layer-1][i-1] if li[layer-1][i-1] > li[layer-1][i] else li[layer-1][i]
    layer -= 1

print(li[0][0])
