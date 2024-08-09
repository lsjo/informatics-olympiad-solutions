IN = open("dishin.txt", "r")
OUT = open("dishout.txt", "w")
 
n = int(IN.readline())
nums = []
 
for a in range(n):
    nums.append(int(IN.readline()))
 
avg = sum(nums) / n
 
OUT.write(str(min(nums))+" "+str(max(nums))+" "+ str(int(avg)))
