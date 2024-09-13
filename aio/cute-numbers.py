cutein = open("cutein.txt", "r")
streak = 0
 
for n in range(int(cutein.readline())):
    a = int(cutein.readline())
    if a == 0:
        streak += 1
    else:
        streak = 0
cuteout = open("cuteout.txt", "w")
cuteout.write(str(streak))
cuteout.close()
