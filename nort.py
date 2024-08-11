nortin = open("nortin.txt", "r")
nortout = open("nortout.txt", "w")
 
nums = nortin.readline().split()
W = int(nums[0])
L = int(nums[1])
 
if W % 2 == 0:
    nortout.write(str(W*L))
elif L % 2 == 0:
    nortout.write(str(W*L))
else:
    nortout.write(str(W*L -1))
 
nortout.close()
