phonein = open("phonein.txt", 'r')
phoneout = open("phoneout.txt", "w")
 
n = int(phonein.readline())
times = []
 
for i in range(n):
    nums = tuple(map(int, phonein.readline().split()))
    if len(nums) == 1:
        times.append((10000, nums[0], 10000))
    else:
        times.append(nums)
 
dists = [[10000, 10000] for i in range(n)]
dists[0] = [0, times[0][1]]
 
for i in range(1, n):
    ptimes = {
        dists[i-1][0]+times[i-1][0],
        dists[i-1][1]+times[i-1][2]+times[i][1]
        }
    dists[i][1] = min(ptimes)
 
    ptimes = {
        dists[i-1][1]+times[i-1][2],
        dists[i-1][0]+times[i-1][0]+times[i][1]
        }
    dists[i][0] = min(ptimes)
 
phoneout.write(str(dists[n-1][1]))
