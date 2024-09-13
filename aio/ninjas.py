a = open("ninjain.txt", "r")
out = open("ninjaout.txt", "w")
 
nums = a.readline().split()
N = int(nums[0])
K = int(nums[1])
print(f"N: {N} K: {K}")
 
caught = 0
missed = 0
 
for b in range(1,N+1):
    if K == 0:
        caught = N
        break
    if b % (K+1) == 1:
        print("caught")
        pass
    else:
        print("missed")
        missed += 1

out.write(str(missed))
out.close()
a.close()
