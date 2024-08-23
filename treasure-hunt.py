cavein = open("cavein.txt", "r")
caveout = open("caveout.txt", "w")
 
a, b = map(int, cavein.readline().split())
 
caves = []
 
for n in range(a):
    caves.append(cavein.readline().strip())
 
def neighbours(x, y):
    ns = [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]
    if x == 0:
        ns.remove((x-1, y))
    if x == a-1:
        ns.remove((x+1, y))
    if y == 0:
        ns.remove((x, y-1))
    if y == b - 1:
        ns.remove((x, y+1))
 
    return ns
 
counter = 0
o_counted = False
 
for i in range(a):
    for j in range(b):
        if caves[i][j] == ".":
            n = neighbours(i, j)
            dots = []
            for x, y in n:
                dots.append(caves[x][y])
            if dots.count(".") < 2:
                counter += 1
                if i == 0 and j == 0:
                    o_counted = True
                  
if counter > 1 and o_counted:
    counter -= 1
 
caveout.write(str(counter))
