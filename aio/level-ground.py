groundin = open("groundin.txt", "r")
groundout = open("groundout.txt", "w")
 
N = int(groundin.readline().strip())
race = groundin.readline().strip().split()
 
maximum = 0
streak = 1
nums = []
 
for a in range(N):
    if a == 0:
        streak = 1
        maximum = streak * int(race[a])
    else:
        if race[a-1] == race[a]:
            streak += 1
        else:
            streak = 1
        if streak * int(race[a]) > maximum:
            maximum = streak * int(race[a])
 
groundout.write(str(maximum))
groundout.close()
