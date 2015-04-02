decimal = 4
binary = ""

while decimal > 0:
	bit = decimal % 2
	decimal = decimal / 2
	if bit == 0:
		binary = "0{0}".format(binary)
	else:
		binary = "1{0}".format(binary)

print binary