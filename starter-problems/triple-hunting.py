IN = open("tripin.txt", "r")
OUT = open("tripout.txt", "w")
 
num = int(IN.readline())
locs = []
 
for n in range(num):
    a = int(IN.readline())
    if a % 3 == 0:
        locs.append(str(n+1))
 
if len(locs) != 0:
    OUT.write(str(len(locs))+"\n")
    OUT.write(" ".join(locs))
else:
    OUT.write("Nothing here!")
 
OUT.close()
