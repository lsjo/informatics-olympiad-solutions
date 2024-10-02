invin = open("invin.txt", "r")
invout = open("invout.txt", "w")

from collections import defaultdict

neighbours = defaultdict(set)

r, c = map(int, invin.readline().split())
arr = []

for i in range(r):
    row = invin.readline().strip()
    arr.append(row)

for y in range(r):
    for x in range(c):
        self = arr[y][x]
        if y != r-1:
            a = arr[y+1][x]
            if a != self:
                neighbours[a].add(self)
                neighbours[self].add(a)
        if x != c - 1:
            a = arr[y][x+1]
            if a != self:
                neighbours[a].add(self)
                neighbours[self].add(a)

if not neighbours.values():
    invout.write("0")
else:
    neighbournums = list(map(len, list(neighbours.values())))
    invout.write(str(max(neighbournums)))
