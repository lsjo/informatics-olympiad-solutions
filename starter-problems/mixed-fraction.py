IN = open("mixin.txt", "r")
OUT = open("mixout.txt", "w")
 
nums = list(map(int, IN.readline().split()))
 
a = nums[0] // nums[1]
b = nums[0] % nums[1]
 
if b == 0:
    OUT.write(str(a))
else:
    OUT.write(str(a)+" "+str(b)+"/"+str(nums[1]))
 
OUT.close()
