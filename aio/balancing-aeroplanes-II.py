balancein = open("balancein.txt", "r")
balanceout = open("balanceout.txt", "w")
 
n = int(balancein.readline())
nums = list(map(int, balancein.readline().split()))
 
i = 0
j = n - 1
 
left = nums[i]
right = nums[j]
 
swaps = 0
 
while j > i and nums:
    if right == left:
        i += 1
        j -= 1
        right = nums[j]
        left = nums[i]
    elif right > left:
        swaps += 1
        i += 1
        left += nums[i]
    else:
        swaps += 1
        j -= 1
        right += nums[j]
 
balanceout.write(str(swaps))
