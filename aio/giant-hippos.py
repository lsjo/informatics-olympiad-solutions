hippoin = open("hippoin.txt", 'r')
hippoout = open("hippoout.txt", "w")
 
N, H, F = map(int, hippoin.readline().split())
 
pos = []
 
for i in range(H):
    pos.append(int(hippoin.readline()))
 
gaps = []
saved = 0
 
if F % 2 == 0:
    x = N - pos[-1]
    y = pos[0] - 1
    gaps.append(x+y)
else:
    x = N - pos[-1]
    y = pos[0] - 1
    if F != 0:
        F -= 1
        saved += max(x, y)
    gaps.append(min(x, y))
 
for i in range(1, H):
    gaps.append(pos[i]-pos[i-1]-1)

gaps.sort()
 
while F >= 2:
    if not gaps:
        break
    a = gaps.pop()
    saved += a
    F -= 2
 
hippoout.write(str(saved))
