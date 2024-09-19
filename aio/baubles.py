baublesin = open("baublesin.txt", "r")
baublesout = open("baublesout.txt", "w")

ro, bo, s, rp, bp = map(int, baublesin.readline().split())

ered = 0
eblue = 0

if rp > ro:
    s-= (rp-ro)
else:
    if rp == 0:
        ered = 1000000000000000000000000 # setting to a large number 
    else:
        ered = ro - rp

if bp > bo:
    s -= (bp-bo)
else:
    if bp == 0:
        eblue = 1000000000000000000000000 # setting to a large number
    else:
        eblue = bo - bp

if 0 > s:
    baublesout.write("0")
else:
    baublesout.write(str(s + 1 + min(ered, eblue)))
