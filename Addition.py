IN = open("addin.txt", "r")
 
nums = IN.read().split()
a = int(nums[0])
b = int(nums[1])
 
OUT = open("addout.txt", "w")
 
OUT.write(str(a+b))
