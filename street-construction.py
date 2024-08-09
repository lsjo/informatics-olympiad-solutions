streetin = open("streetin.txt", "r")
streetout = open("streetout.txt", "w")
 
nums = streetin.readline().split()
K = int(nums[1])
N = int(nums[0]) - K
 
if N == 0:
    ans = 0
elif N == 1:
    ans = 1
else:
    nchunks = K + 1
    pchunk = N // nchunks
    ans = (pchunk+1) if N % nchunks != 0 else pchunk
 
print(ans)
 
streetout.write(str(ans))
