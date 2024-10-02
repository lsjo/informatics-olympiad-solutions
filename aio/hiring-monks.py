INPUT = open("hirein.txt", "r")
 
num = int(INPUT.readline())
skill = [int(INPUT.readline()) for a in range(num)]
 
nsjobs = int(INPUT.readline())
ssjobs = [int(INPUT.readline()) for a in range(nsjobs)]
 
nmjobs = int(INPUT.readline())
smjobs = [int(INPUT.readline()) for a in range(nmjobs)]
 
ssjobs.sort(reverse = False)
smjobs.sort(reverse = True)
 
print(ssjobs)
print(smjobs)

skill.sort(reverse = True)
jobs_assigned = 0
 
for a in smjobs:
    if skill and skill[0] >= a:
        skill.pop(0)
        jobs_assigned += 1
 
for a in ssjobs:
    if skill and skill[-1] <= a:
        skill.pop(-1)
        jobs_assigned += 1
 
OUTPUT = open("hireout.txt", "w")
OUTPUT.write(str(jobs_assigned))
OUTPUT.close()
