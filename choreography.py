dancein = open("dancein.txt", "r")
danceout = open("danceout.txt", "w")
 
nums = dancein.readline().split()
throwers = int(nums[0])
throws = int(nums[1])
hoops = [0 for i in range(throwers)]
 
for n in range(throws):
    a = dancein.readline().strip().split()
    i = int(a[0]) - 1
    j = int(a[1]) - 1
    hoops[j] += 1
    if hoops[i] > 0:
        hoops[i] -= 1
 
danceout.write(str(sum(hoops)))
danceout.close()
