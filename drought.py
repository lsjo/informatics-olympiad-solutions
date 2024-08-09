IN = open("rainin.txt", "r")
OUT = open("rainout.txt", "w")
 
q = IN.readline().split()
a = int(q[0])
b = int(q[1])
 
total = 0
count = 0
 
while b > total:
    total += int(IN.readline())
    count += 1
 
OUT.write(str(count))
