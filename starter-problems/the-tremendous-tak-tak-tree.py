IN = open("taktakin.txt", "r")
OUT = open("taktakout.txt", "w")
 
num = int(IN.read())
counter = 0
 
while num % 11 != 1:
    num = num * 2
    counter += 1
 
OUT.write(str(counter)+" "+str(num))
