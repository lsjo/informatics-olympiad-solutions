curryin = open("curryin.txt", "r")
curryout = open("curryout.txt", "w")
 
nums = list(map(int, curryin.readline().split()))
spoonfuls = [0, 0, 0]
 
while True:
    if nums[0] >= nums[1] and nums[2] >= nums[1]:
        spoonfuls[1] += 1
        nums[0], nums[2] = nums[0] - 1, nums[2] - 1
    
    elif nums[1] >= nums[0] and nums[2] >= nums[0]:
        spoonfuls[0] += 1
        nums[1], nums[2] = nums[1] - 1, nums[2] - 1
 
    else:
        spoonfuls[2] += 1
        nums[0], nums[1] = nums[0] - 1, nums[1] - 1
 
    if sum(nums) == nums[0] or sum(nums) == nums[1] or sum(nums) == nums[2]:
        break
 
string = str(spoonfuls[0])+" "+str(spoonfuls[1])+" "+str(spoonfuls[2])
curryout.write(string)
curryout.close()
