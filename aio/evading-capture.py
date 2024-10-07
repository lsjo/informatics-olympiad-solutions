def nodesinit():
    return [10000000000, 10000000000]
 
from collections import defaultdict
 
evadingin = open("evadingin.txt", "r")
evadingout = open("evadingout.txt", "w")
 
N, E, X, K = map(int, evadingin.readline().split())
 
graph = defaultdict(set)
oddsevens = defaultdict(nodesinit)
 
for i in range(E):
    a, b = map(int, evadingin.readline().split())
    graph[a].add(b)
    graph[b].add(a)
 
starts = graph[X]
neighbours = set()
for a in starts:
    oddsevens[a][1] = 1
    for x in graph[a]:
        neighbours.add(x)
        oddsevens[x][0] = 2
 
while neighbours:
    starts = neighbours
    neighbours = set()
    for a in starts:
        for i in graph[a]:
            if oddsevens[a][0]+1 < oddsevens[i][1]:
                neighbours.add(i)
                oddsevens[i][1] = oddsevens[a][0] + 1
            if oddsevens[a][1]+1 < oddsevens[i][0]:
                neighbours.add(i)
                oddsevens[i][0] = oddsevens[a][1] + 1
 
num = K % 2
ans = 0
 
for i in oddsevens:
    if oddsevens[i][num] <= K:
        ans += 1
 
evadingout.write(str(ans))
