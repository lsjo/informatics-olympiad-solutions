vasesin = open("vasesin.txt", mode="r")
 
n = int(vasesin.read())
 
def vases(flowers):
    if flowers > 5:
        a = 1
        b = 2
        c = flowers - 3
    else:
        a = 0
        b = 0
        c = 0
    return a, b, c
 
a, b, c = vases(n)
 
vasesout = open("vasesout.txt", mode="w")
 
vasesout.write(str(a)+" "+str(b)+ " "+str(c))
