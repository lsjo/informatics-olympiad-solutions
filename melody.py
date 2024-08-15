melodyin = open("melodyin.txt", "r")
melodyout = open("melodyout.txt", "w")
 
nums = melodyin.readline().split()
N = int(nums[0])
vals = [{}, {}, {}]
 
for a in range(N):
    x = int(melodyin.readline())
    if x in vals[a%3]:
        vals[a%3][x] += 1
    else:
        vals[a%3][x] = 1

i = max(set(vals[0].values()))
j = max(set(vals[1].values()))
k = max(set(vals[2].values()))
 
change = N - i - j - k
 
melodyout.write(str(change))
melodyout.close()
