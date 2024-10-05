probein = open("probein.txt", "r")
probeout = open("probeout.txt", "w")
 
r, c, rp, cp, rf, cf = map(int, probein.readline().split())
 
if abs(cp - cf) == abs(rp - rf):
    if rp > rf:
        rp += 100000000
        rf -= 100000000
    elif rf > rp:
        rp -= 100000000
        rf += 100000000
 
    if cp > cf:
        cp += 100000000
        cf -= 100000000
    elif cf > cp:
        cp -= 100000000
        cf += 100000000
 
q = int(probein.readline())
 
for _ in range(q):
    y, x = map(int, probein.readline().split())
    fdist = abs(rf-y) + abs(cf-x)
    pdist = abs(rp-y) + abs(cp-x)
    if fdist == pdist:
        probeout.write("MOUNTAINS\n")
    elif fdist > pdist:
        probeout.write("WATER\n")
    else:
        probeout.write("LAVA\n")
 
probeout.close()
