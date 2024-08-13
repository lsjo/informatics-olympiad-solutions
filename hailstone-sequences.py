hailin = open("hailin.txt", "r")
hailout = open("hailout.txt", "w")
 
while True:
    num = int(hailin.readline())
    if num == 0:
        break
    else:
        counter = 0
        while num != 1:
            counter += 1
            if num % 2 == 0:
                num = num / 2
            else:
                num = 3*num + 1
        hailout.write(str(counter)+"\n")
 
hailout.close()
