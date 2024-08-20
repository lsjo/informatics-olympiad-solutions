mousein = open("mousein.txt", "r")
mouseout = open("mouseout.txt", "w")
 
xnums = []
ynums = []
 
for n in range(8):
    a = mousein.readline().split()
    b = int(a[0])
    c = int(a[1])
    xnums.append(b)
    ynums.append(c)
 
pos = 0
coords = 0
 
for a in xnums:
    if xnums.count(a) == 4:
        if a == max(xnums):
            mouseout.write("E")
        else:
            mouseout.write("W")
        break
 
for a in ynums:
    if ynums.count(a) == 4:
        pos = "y"
        coords = a
        if a == max(ynums):
            mouseout.write("N")
        else:
            mouseout.write("S")
        break
 
mouseout.close()
mousein.close()
