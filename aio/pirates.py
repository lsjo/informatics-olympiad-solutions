piratesin = open("piratein.txt", "r")
piratesout = open("pirateout.txt", "w")
 
L = int(piratesin.readline())
X = int(piratesin.readline())
Y = int(piratesin.readline())
 
dist = min((X+Y), (2*L - X - Y))
 
piratesout.write(str(dist))
