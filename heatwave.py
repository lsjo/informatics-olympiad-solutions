heatin = open("heatin.txt", "r")
heatout = open("heatout.txt", "w")
 
days, heat = map(int, heatin.readline().split())
heatwave = 0
c = 0
 
for n in range(days):
    num = int(heatin.readline())
    if num >= heat:
        c += 1
        if c > heatwave:
            heatwave = c
    else:
        c = 0
 
heatout.write(str(heatwave))
