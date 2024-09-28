chairsin = open("chairsin.txt", 'r')
chairsout = open("chairsout.txt", 'w')
 
C, N, K = map(int, chairsin.readline().split())
chairs = chairsin.readline().strip()
 
dryneeded = N - K
 
start = 0
total_dry = 0
length = 0
stop = 0
broken = False
 
while total_dry < dryneeded or length < N:
    c = chairs[stop]
    if c == "d":
        total_dry += 1
    length += 1
    stop += 1
 
stop -= 1
 
minchairs = length
 
while C - 1 >= stop and broken == False:
    if chairs[start] == "d":
        if length == N:
            broken = True
            minchairs = N
            break
        elif total_dry > dryneeded:
            start += 1
            length -= 1
            total_dry -= 1
        else:
            if stop == C-1:
                broken = True
                break
            else:
                stop += 1
                total_dry += (1 if chairs[stop] == "d" else 0)
                length += 1
    else:
        if length == N:
            broken = True
            minchairs = N
            break
        else:
            start += 1
            length -= 1
    minchairs = min(minchairs, length)
 
chairsout.write(str(minchairs))
