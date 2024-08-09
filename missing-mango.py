manin = open("manin.txt", "r")
manout = open("manout.txt", "w")
 
nums = manin.readline().split()
ax, cx, ad, cd = int(nums[0]), int(nums[1]), int(nums[2]), int(nums[3])
pos = None
 
if ax - ad == cx - cd:
    pos = ax-ad
elif ax + ad == cx + cd:
    pos = ax+ad
elif ax - ad == cx + cd:
    pos = ax-ad
elif ax + ad == cx-cd:
    pos = ax + ad
 
manout.write(str(pos))
print(pos)
manout.close()
