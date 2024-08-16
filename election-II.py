elecin = open("elecin.txt", "r")
elecout = open("elecout.txt", "w")
 
N = int(elecin.readline().strip())
votes = elecin.readline().strip()
 
nums = [0, 0, 0]
 
for n in votes:
    if n == "A":
        nums[0] += 1
    elif n == "B":
        nums[1] += 1
    elif n == "C":
        nums[2] += 1
 
winner = max(nums)

if nums.count(winner) == 1:
    a = nums.index(winner)
    if a == 0:
        elecout.write("A")
    elif a == 1:
        elecout.write("B")
    elif a == 2:
        elecout.write("C")
else:
    elecout.write("T")
