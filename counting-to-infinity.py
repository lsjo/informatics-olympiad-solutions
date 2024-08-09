IN = open("countin.txt", "r")
OUT = open("countout.txt", "w")
 
num = int(IN.read())
for a in range(num):
    OUT.write(str(a+1)+"\n")
 
OUT.close()
