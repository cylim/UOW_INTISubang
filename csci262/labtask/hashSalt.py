#AUTHOR		:Lim Chee Yeong
#STUDENT ID	: J14016414(INTI) or 4933643(UOW)
#CLASS		:CSCI262
#The program ask user to input password, then hash it
#prompt user to input password again to see whether it is correct

import hashlib
import random

def verifyPass(password):
	verifyPassword = raw_input("Verify password: ")
	split = password.split(":",1)
	salt = split[1];
	hash = hashlib.md5(salt + verifyPassword).hexdigest()
	verifyPassword = hash + ":" + salt
	print verifyPassword
	if(verifyPassword == password):
		print "password correct\n"
	else:
		print "Incorrect password\n"

username = raw_input("Username: ")
password = raw_input("Password: ")

salt = random.randint(10000000, 99999999)
ssalt = str(salt)

hash = hashlib.md5(str(salt) + password).hexdigest()
password = hash + ":" + str(salt)
print password

verifyPass(password)

