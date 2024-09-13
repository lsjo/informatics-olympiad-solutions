bendin  = open("bendin.txt", "r")
bendout = open("bendout.txt", "w")

ax1, ay1, ax2, ay2 = list(map(int, bendin.readline().split()))
bx1, by1, bx2, by2 = list(map(int, bendin.readline().split()))
 
a = (int(ax2)-int(ax1)) * (int(ay2) - int(ay1))
b = (int(bx2)-int(bx1)) * (int(by2) - int(by1))
total = a + b
 
x = max(0, min(ax2, bx2) - max(ax1, bx1))
y = max(0, min(ay2, by2) - max(ay1, by1))
deduct = x*y

total = total - deduct

bendout.write(str(int(total)))
bendout.close()
