magicin = open("magicin.txt", "r")
magicout = open("magicout.txt", "w")
 
A, B, C = magicin.readline().strip().split()
 
magicout.write(A+" "+B+" "+" "+C+"\n")
magicout.write(C+" "+A+" "+" "+B+"\n")
magicout.write(B+" "+C+" "+" "+A)
 
magicout.close()
magicin.close()
