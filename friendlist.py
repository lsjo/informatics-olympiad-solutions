IN = open("listin.txt", "r")
OUT = open("listout.txt", "w")
 
friends = {}
 
num = int(IN.readline())
 
for n in range(num):
    c = IN.readline().split()
    for a in c:
        if a in friends:
            friends[a] += 1
        else:
            friends[a] = 1
 
max_vals = [0]
max_users = [0]
 
for a in friends:
    if friends[a] > max_vals[0]:
        max_vals = [friends[a]]
        max_users = [int(a)]
    elif friends[a] == max_vals[0]:
        max_vals.append(friends[a])
        max_users.append(int(a))
 
max_users.sort()
 
for n in max_users:
    OUT.write(str(n)+"\n")
 
OUT.close()
