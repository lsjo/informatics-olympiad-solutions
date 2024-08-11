cultin = open("cultin.txt", "r")
cultout = open("cultout.txt", "w")
 
num = int(cultin.readline())
counter = 0
 
while num % 2 == 0:
    counter += 1
    num = num / 2
 
string = str(int(num))+" "+str(counter)
cultout.write(string)
cultout.close()
cultin.close()
