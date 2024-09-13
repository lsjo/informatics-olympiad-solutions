genin = open("genin.txt", "r")
genout = open("genout.txt", "w")
 
a = genin.readline().split()
N = int(a[0])
P = int(a[1])
nums = [0 for n in range(N)]
counter = 0
num = 0
 
while P > 0:
    num += 1
    if num > P:
        num = P
        P = 0
    else:
        P = P-num
    nums[counter % N] += num
    counter += 1
 
genout.write(str(nums.index(max(nums))+1)+" "+str(max(nums)))
genout.close()
