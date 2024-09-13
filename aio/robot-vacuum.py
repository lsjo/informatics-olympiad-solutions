robotin = open("robotin.txt", "r")
robotout = open("robotout.txt", "w")
 
K = robotin.readline()
cmoves = robotin.readline().strip()
 
nums = abs(cmoves.count("W") - cmoves.count("E")) + abs(cmoves.count("S") - cmoves.count("N"))
robotout.write(str(nums))
