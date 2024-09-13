cavalryin = open("cavalryin.txt", "r")
cavalryout = open("cavalryout.txt", "w")
 
squadnums = {}
 
N = int(cavalryin.readline())
 
for n in range(N):
    a = int(cavalryin.readline())
    if str(a) in squadnums:
        squadnums[str(a)] += 1
    else:
        squadnums[str(a)] = 1

x = True
for a in squadnums:
    if squadnums[a] % int(a) == 0:
        pass
    else:
        x = False
        break
 
if x == True:
    cavalryout.write("YES")
else:
    cavalryout.write("NO")
 
cavalryout.close()
