buildin = open("buildin.txt", "r")
buildout = open("buildout.txt", "w")
 
N = int(buildin.readline())
nums = list(map(int, buildin.readline().strip().split()))
rugs = []
drugs = []
 
for n in range(1,N):
    rugs.append(nums[n] - nums[n-1])
 
drugs.append(abs(rugs[0]))
 
for n in range(1, N-1):
    a = abs(rugs[n-1]) + abs(rugs[n]) - abs(rugs[n-1] + rugs[n])
    drugs.append(a)
 
drugs.append(abs(rugs[-1]))
 
buildout.write(str(sum(list(map(abs, rugs))) - max(drugs)))
