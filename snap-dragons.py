snapin = open("snapin.txt", "r")
snapout = open("snapout.txt", "w")
 
nums = snapin.readline().split()
 
R, S = int(nums[0]), int(nums[1])
rvals = dict()

for n in range(R):
    a = snapin.readline()
    if a in rvals:
        rvals[a] += 1
    else:
        rvals[a] = 1
      
pairs = 0

for n in range(S):
    a = snapin.readline()
    if a in rvals:
        pairs += rvals[a]
      
snapout.write(str(pairs))
