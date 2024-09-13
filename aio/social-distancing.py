distin = open("distin.txt", "r")
distout = open("distout.txt", "w")
 
N, K = list(map(int, distin.readline().split()))
 
locs = []
 
for a in range(N):
    locs.append(int(distin.readline()))
 
if N == 2:
    if abs(locs[0] - locs[1]) >= K:
        nums = 2
    else:
        nums = 1
 
elif K == 1:
    locs = set(locs)
    nums = len(locs)
 
else:
    locs.sort()
    nums = 0
    for n in range(N):
        if n == 0:
            dist = 0
            nums += 1
        else:
            dist += locs[n] - locs[n-1]
            if dist >= K:
                nums += 1
                dist = 0

distout.write(str(nums))
