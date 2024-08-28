rafflein = open('rafflein.txt', "r")
raffleout = open('raffleout.txt', "w")
 
N, K = map(int, rafflein.readline().split())
nums = list(map(int, rafflein.readline().split()))
 
newnums = set()
notnums = set()
 
for n in nums:
    if n not in newnums and n not in notnums:
        newnums.add(n)
    else:
        if n in newnums:
            newnums.remove(n)
        notnums.add(n)
 
if not newnums:
    a = -1
else:
    a = min(newnums)
    
raffleout.write(str(a))
