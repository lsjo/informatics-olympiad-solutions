telein = open("telein.txt", "r")
teleout = open("teleout.txt", "w")
 
N = int(telein.readline())
nums = telein.readline().strip().split("T")

right = 0
left = 0
for n in nums:
    l = 0
    r = 0
    for a in n:
        if a =="L":
            l += 1
            r -= 1
        else:
            r += 1
            l -= 1
        left = max(left, l)
        right = max(right, r)
 
teleout.write(str(left+right+1))
