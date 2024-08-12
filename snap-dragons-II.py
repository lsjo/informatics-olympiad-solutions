snapin = open("snapin.txt", "r")
snapout = open("snapout.txt", "w")
 
nums = list(map(int, snapin.readline().split()))
 
r = nums[0]
c = nums[1]
 
rr = nums[2]
rc = nums[3]
 
sr = nums[4]
sc = nums[5]
 
if (abs(rr - sr) + abs(rc - sc)) % 2 == 0:
    snapout.write("SCARLET")
else:
    snapout.write("ROSE")
 
snapout.close()
