IN = open("sitin.txt", "r")
OUT = open("sitout.txt", "w")
 
nums = list(map(int, IN.readline().split()))
ppl = int(IN.readline())
 
seats = nums[0] * nums[1]
 
if seats > ppl:
    a = ppl
else:
    a = seats
 
b = ppl - a
 
OUT.write(str(a)+" "+str(b))
OUT.close()
