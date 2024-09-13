artin = open("artin.txt", "r")
artout = open("artout.txt", "w")
 
N = int(artin.readline())
holex = set()
holey = set()
 
for a in range(N):
    nums = artin.readline().split()
    holex.add(int(nums[0]))
    holey.add(int(nums[1]))
 
area = (max(holex) - min(holex)) * (max(holey) - min(holey))
artout.write(str(area))
artout.close()
