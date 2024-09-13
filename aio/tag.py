tagin = open("tagin.txt", "r")
tagout = open("tagout.txt", "w")
 
nums = tagin.readline().split()
N, M = int(nums[0]), int(nums[1])
 
red = {1}
blue = {2}
 
for a in range(M):
    nums = tagin.readline().split()
    if int(nums[0]) in red:
        red.add(int(nums[1]))
    else:
        blue.add(int(nums[1]))
 
out = str(len(red))+" "+str(len(blue))
tagout.write(out)
tagout.close()
