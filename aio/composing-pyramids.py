from collections import defaultdict

compin = open("compin.txt", "r")
compout = open("compout.txt", "w")

N = int(compin.readline())
nums = list(map(int, compin.readline().split()))

right = [1 for i in range(N)]
rightvals = defaultdict(int)

rightvals[nums[0]] = 1

for i in range(1, N):
    a = rightvals[nums[i] - 1]
    right[i] = a + 1
    rightvals[nums[i]] = a + 1

left = [1 for i in range(N)]
leftvals = defaultdict(int)

leftvals[nums[-1]] = 1

for i in range(N-2, -1, -1):
    a = leftvals[nums[i] - 1]
    left[i] = a + 1
    leftvals[nums[i]] = a + 1

maxlength = 0

for n in range(N):
    pyr = min(right[n], left[n]) * 2 - 1
    maxlength = max(maxlength, pyr)

compout.write(str(N - maxlength))
