#AUTHOR		:Lim Chee Yeong
#STUDENT ID	: J14016414(INTI) or 4933643(UOW)
#CLASS		:CSCI262
#The program scan the ip address from 0 to 255
#Then generate two files to store the active address and non-active address

import os

cActive = 0
cInactive =0

active = file("active.txt", "w+")
inactive = file("inactive.txt", "w+")

for x in range(0,256):
	ip = "192.168.1.{0}".format(x)
	record = os.system('ping -c 1 -W 1 ' + ip)
	if record:
		print ip + " INACTIVE"
		inactive.write(ip)
		inactive.write('\n')
		cInactive +=1
	else:
		print ip + " ACTIVE"
		active.write(ip)
		active.write('\n')
		cActive +=1

active.close()
inactive.close()
print "Active: " + str(cActive) + "\tInactive: " + str(cInactive)

active = file("active.txt", "r")
inactive = file("inactive.txt", "r")
print "\n\t+++++++Active List+++++++\n"
print active.readlines()
print "\n\n\n"
print "\t+++++++Inactive List+++++++\n"
print inactive.readlines()

active.close()
inactive.close()