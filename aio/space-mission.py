spacein = open("spacein.txt", 'r')
spaceout = open("spaceout.txt", "w")
 
N, F = map(int, spacein.readline().split())
 
days = [int(spacein.readline()) for i in range(N)]
starts = []
stops = []
 
for i in range(N):
    if i == 0:
        starts.append((days[0], 0))
    else:
        if days[i] < starts[-1][0]:
            starts.append((days[i], i))
 
for i in range(N-1, -1, -1):
    if i == N-1:
        stops.append((days[i], i))
    else:
        if days[i] < stops[-1][0]:
            stops.append((days[i], i))
 
stops = stops[::-1]
 
i = 0
j = 0
 
startsend = len(starts)
stopsend = len(stops)
 
maxlength = -1
 
while True:
    if (starts[i][0] + stops[j][0]) <= F:
        maxlength = max(maxlength, stops[j][1]-starts[i][1]+1)
        j += 1
        if j == stopsend:
            break
    else:
        i += 1
        if i == startsend:
            break
 
if maxlength < 2:
    spaceout.write("-1")
else:
    spaceout.write(str(maxlength))
