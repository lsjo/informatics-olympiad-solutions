fashin = open("fashin.txt", "r")
fashout = open("fashout.txt", "w")
 
fare = int(fashin.readline())
nums = [100, 20, 5, 1]
i = 0
counter = 0
 
while fare > 0:
    while fare >= nums[i]:
        fare = fare - nums[i]
        counter += 1
    i += 1
 
print(counter)
 
fashout.write(str(counter))
fashout.close()
