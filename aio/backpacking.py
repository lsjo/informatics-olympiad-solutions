backin = open("backin.txt", "r")
backout = open("backout.txt", 'w')
 
n, k = map(int, backin.readline().split())
dists = list(map(int, backin.readline().split()))
costs = list(map(int, backin.readline().split()))
 
cans = 0
dist = 0
totalcost = 0
 
distspre = [0]
cheaps = [-1 for i in range(20)]
mins = [0 for i in range(n)]
 
for i in range(n-1):
    distspre.append(distspre[-1] + dists[i])
 
for i in range(n-1, -1, -1):
    a = costs[i] - 1
    cheaps[a] = i
 
    minam = 200000000
 
    for j in range(a-1, -1, -1):
        if cheaps[j] == -1:
            continue
        minam = min(minam, cheaps[j])
 
    if minam == 200000000:
        mins[i] = i
    else:
        mins[i] = minam
 
for i in range(n-1):
    minj = mins[i]
    if distspre[minj] - distspre[i] > k:
        minj = i
        
    if minj == i:
        num = min(k - cans, distspre[-1]-distspre[i]-cans)
        cans += num
        totalcost += num * costs[i]
    else:
        num = min(distspre[minj] - distspre[i] - cans, distspre[-1]-distspre[i]-cans)
        num = max(0, num)
        cans += num
        totalcost += num * costs[i]
    cans -= distspre[i+1] - distspre[i]
 
backout.write(str(totalcost))
