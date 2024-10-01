janitorin = open("janitorin.txt", "r")
janitorout = open("janitorout.txt", "w")
 
R, C, Q = map(int, janitorin.readline().split())
 
tiles = []
 
for i in range(R):
    nums = list(map(int, janitorin.readline().split()))
    tiles.append(nums)
 
maxtiles = set()
 
watercount = 0
 
for x in range(R):
    for y in range(C):
        nums = []
        if x > 0:
            nums.append(tiles[x-1][y])
        if x < R - 1:
            nums.append(tiles[x+1][y])
        if y > 0:
            nums.append(tiles[x][y-1])
        if y < C - 1:
            nums.append(tiles[x][y+1])
 
        if tiles[x][y] >= max(nums, default = -1):
            maxtiles.add((x, y))
            watercount += 1
 
janitorout.write(str(watercount) + "\n")
 
for i in range(Q):
    a, b, c = map(int, janitorin.readline().split())
    a -= 1
    b -= 1
 
    if (a, b) in maxtiles:
        maxtiles.remove((a, b))
        watercount -= 1
 
    tiles[a][b] = c
 
    nums = []
    if a > 0:
        nums.append(tiles[a-1][b])
    if a < R - 1:
        nums.append(tiles[a+1][b])
    if b > 0:
        nums.append(tiles[a][b-1])
    if b < C - 1:
        nums.append(tiles[a][b+1])
 
    if c >= max(nums, default=-1):
        maxtiles.add((a, b))
        watercount += 1
 
    tileslist = [(a, b+1), (a, b-1), (a-1, b), (a+1, b)]
    for x, y in tileslist:
        if 0 <= x < R and 0 <= y < C:
            if (x, y) in maxtiles:
                maxtiles.remove((x, y))
                watercount -= 1
 
            z = tiles[x][y]
            num = []
            if x > 0:
                num.append(tiles[x-1][y])
            if x < R - 1:
                num.append(tiles[x+1][y])
            if y > 0:
                num.append(tiles[x][y-1])
            if y < C - 1:
                num.append(tiles[x][y+1])
 
            if z >= max(num, default=-1):
                maxtiles.add((x, y))
                watercount += 1
 
    janitorout.write(str(watercount) + "\n")
 
janitorin.close()
janitorout.close()
