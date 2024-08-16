tspin = open("tspin.txt", "r")
tspout = open("tspout.txt", "w")
 
N = int(tspin.readline())
minimum = list(map(int, tspin.readline().split()))
maximum = list(map(int, tspin.readline().split()))
 
possible = True
 
for a in range(N):
    if a == 0:
        b = minimum[a]
    else:
        b = max(b, minimum[a])
        if b > maximum[a]:
            possible = False
            break
 
if possible:
    tspout.write("YES")
else:
    tspout.write("NO")
 
tspout.close()
