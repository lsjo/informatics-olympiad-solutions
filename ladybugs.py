ladyin = open("ladyin.txt", "r")
ladyout = open("ladyout.txt", "w")
 
num = int(ladyin.readline())
pos = []
 
for n in range(num):
    pos.append(int(ladyin.readline()))
 
length = str(max(pos) - min(pos) + 1)
ladyout.write(length)
ladyout.close()
