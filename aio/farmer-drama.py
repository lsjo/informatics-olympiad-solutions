farmin = open("farmin.txt", "r")
farmout = open('farmout.txt', "w")
 
n = int(farmin.readline())
nums = list(map(int, farmin.readline().split()))
 
l = 0
r = n - 1
 
lsum = nums[l]
rsum = nums[r]
counter = 0
 
while l < r:
    if lsum == rsum:
        l += 1
        r -= 1
        lsum += nums[l]
        rsum += nums[r]
    elif lsum < rsum:
        l += 1
        counter += 1
        lsum += nums[l]
    elif rsum < lsum:
        r -= 1
        counter += 1
        rsum += nums[r]
 
farmout.write(str(counter))
