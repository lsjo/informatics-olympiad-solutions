cloudin = open("cloudin.txt", "r")
cloudout = open("cloudout.txt", "w")
 
N, K = cloudin.readline().split()
N, K = int(N), int(K)
 
nums = [int(cloudin.readline())]
 
for n in range(1, N-1):
    a = int(cloudin.readline())
    nums.append((a+nums[n-1]))
 
max_dist = nums[K-1]
start = 0
stop = K
 
while len(nums) > stop:
    cover = nums[stop] - nums[start]
    max_dist = min(max_dist, cover)
    start += 1
    stop += 1
 
cloudout.write(str(max_dist))
cloudout.close()
