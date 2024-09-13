wetin = open("wetin.txt", "r")
wetout = open("wetout.txt", "w")
 
dam = 0
 
for n in range(8):
    dam += int(wetin.readline())
    if dam > 10:
        dam -= 10
    else:
        dam = 0
 
wetout.write(str(dam))
