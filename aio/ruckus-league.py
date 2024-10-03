from collections import defaultdict
 
ruckusin = open("ruckusin.txt", 'r')
ruckusout = open("ruckusout.txt", "w")
 
N, L, K, M = map(int, ruckusin.readline().split())
links = defaultdict(int)
backlinks = defaultdict(int)
 
 
for i in range(L):
    nums = tuple(map(int, ruckusin.readline().split()))
    links[nums[0]] = nums[1]
    backlinks[nums[1]] = nums[0]
 
visited = set()
 
rings = []
lines = []
solos = 0
 
wow = 0
 
for i in range(1, N+1):
    if not (i in visited):
        wow += 1
        visited.add(i)
        length = 1
        a = i
        new = links[a]
        ending = ""
        while new not in visited and new != 0:
            visited.add(new)
            length += 1
            a = new
            new = links[a]
            if new in visited:
                ending = "ring"
        if ending == "ring":
            rings.append(length)
        else:
            a = i
            new = backlinks[a]
            while new not in visited and new != 0:
                visited.add(new)
                length += 1
                a = new
                new = backlinks[a]
            if length == 1:
                solos += 1
            else:
                lines.append(length)
            
 
groups = 0
rings.sort(reverse=True)
 
if M == 1:
    groups += solos
for a in lines:
    if a >= M:
        groups += 1
for a in rings:
    if a >= M:
        groups += 1
 
for n in range(len(lines)):
    if K == 0:
        break
    while lines[n] // M >= 2 and K > 0:
        groups += 1
        lines[n] -= M
        K -= 1
 
for n in range(len(rings)):
    if K < 2:
        break
    counter = 0
    print(rings[n])
    while rings[n] // M >= 2 and K > 0:
        if counter == 0:
            K -= 1
            counter += 1
        K -= 1
        groups += 1
        rings[n] -= M
 
ruckusout.write(str(groups))
