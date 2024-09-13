IN = open("palin.txt", "r")
OUT = open("palout.txt", "w")

N = int(IN.readline())

line = IN.readline().strip()
line = list(line)
alpha = list("abcdefghijklmnopqrstuvwxyz")
 
num = int(N/2)
 
for a in range(num):
    x = line[a]
    b = line[0 - a - 1]
    if x == b:
        pass
    else:
        minimum = min([alpha.index(x), alpha.index(b)])
        line[a], line[0 - a - 1] = alpha[minimum], alpha[minimum]
 
line = "".join(line)
 
OUT.write(line)
 
IN.close()
OUT.close()
