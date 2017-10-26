while True:
    hString = input("Enter height of pyramid: ")
    height = int(hString)
    if height > 0 and height <= 23:
        break
space = " "
hash = "#"
for i in range(height):
    print(space*(height-i) + hash*(i+2))
height -= 1

            
    