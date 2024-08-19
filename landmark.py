landin = open("landin.txt", "r")
landout = open("landout.txt", "w")
 
nums = landin.readline().split()
height = int(nums[0])
width = int(nums[1])
 
matrix = []
 
for a in range(height):
    matrix.append(landin.readline().strip())
 
maxlength = 0
maxcoords = ""
 
for n in range(height):
    length = 0
    for a in range(width):
        if matrix[n][a] == ".":
            if length == 0:
                startcoords = str(n+1)+" "+str(a+1)+" "
            length += 1
            if a == width - 1:
                if length > maxlength:
                    maxlength = length
                    endcoords = str(n+1) + " " + str(a+1)
                    maxcoords = startcoords+endcoords
        else:
            if length > maxlength:
                maxlength = length
                endcoords = str(n+1) + " " + str(a)
                maxcoords = startcoords+endcoords
            length = 0
 
for a in range(width):
    length = 0
    for n in range(height):
        if matrix[n][a] == ".":
            if length == 0:
                startcoords = str(n+1)+" "+str(a+1)+" "
            length += 1
            if n == height - 1:
                if length > maxlength:
                    maxlength = length
                    endcoords = str(n+1) + " " + str(a+1)
                    maxcoords = startcoords+endcoords
        else:
            if length > maxlength:
                maxlength = length
                endcoords = str(n) + " " + str(a+1)
                maxcoords = startcoords+endcoords
            length = 0
 
landout.write(maxcoords)
landout.close()
landin.close()
