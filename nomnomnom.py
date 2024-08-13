nomin = open("nomin.txt", "r")
nomout = open("nomout.txt", "w")
 
N = int(nomin.readline())
 
last = int(nomin.readline())
satisfied = 1
n = 0
 
for i in range(N-1):
    n += int(nomin.readline())
    if n >= last:
        last = n
        n = 0
        satisfied += 1

nomout.write(str(satisfied))
nomout.close()
