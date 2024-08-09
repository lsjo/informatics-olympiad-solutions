IN = open("encyin.txt", "r")
OUT = open("encyout.txt", "w")
 
nums = list(map(int, IN.readline().split()))
 
wc = [int(IN.readline()) for a in range(nums[0])]
qs = [int(IN.readline()) for a in range(nums[1])]
 
for n in qs:
    OUT.write(str(wc[n-1])+"\n")
 
OUT.close()
