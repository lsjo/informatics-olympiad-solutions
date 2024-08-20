laserin = open("laserin.txt", "r")
laserout = open("laserout.txt", "w")
 
N = int(laserin.readline())
bottom = laserin.readline().strip()
top = laserin.readline().strip()
 
length = 0
maxlength = 0
 
for n in range(N*2):
    if bottom[n] == "D" and top[n] == "R":
        length += 1
    elif bottom[n] == "R" and top[n] == "D":
        length -= 1
 
    maxlength = max(length, maxlength)
 
laserout.write(str(maxlength))
laserout.close()
