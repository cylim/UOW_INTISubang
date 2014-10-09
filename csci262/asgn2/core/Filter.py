import sys #import standard library for direct contact with command line, passing arguments and terminate program
from time import sleep

def Filter(fr = "4000", to = "4020"):
	#if the user input is smaller than 4000 and/or larger than 4020, set it to correct value
	if fr < "4000":
		fr = "4000"
	if to > "4020":
		to = "4020"
	#open the filter policy filter and get the policy as policy
	print "Filter port activity with rules,"
	policy = []
	with open("resources/filterPolicy.txt", "r") as fil:
		for line in fil:
			policy.append(line.strip().split(':'))

	open("log.txt", "w").close() #clear data in log.txt

	#depend on the policy rule port type, call respective function
	for rule in xrange(len(policy)):
		if policy[rule][0] == '1':
			allPort(policy[rule], fr, to, rule)
		elif '-' in policy[rule][0]:
			rangePort(policy[rule], fr, to, rule)
		elif fr <= policy[rule][0] <= to:
			onePort(policy[rule], rule)
		else: #if the port less than 4000 or greater than 4020, rule of the port invalid
			print "Rule", rule+1, ", port not in range." 
	sleep(0.5)
	print "Filter successful, please check the log.txt file."
	sleep(0.2)

#function to handle port in a range
def rangePort(policy, fr, to, rule):
	port= policy[0].split('-') #spilt the word in policy[0]
	#check whether the port is valid
	valid = True
	if port[0] > port[1]: #if the range of the port is greater to lower, swap it
		port[0],port[1] = port[1],port[0]
	if port[0] >= to: #if the lower port greater than greatest port in list, valid False
		valid = False
	if port[1] <= fr: #if the greater port smaller than lowest port in list, valid False
		valid = False

	if valid == True: #set the fr to lower port, to to greater port and pass to allPort()
		allPort(policy, port[0], port[1], rule)
	else: #rules invalid
		print "Rule", rule+1, ", port not in range."

#function to handle all port
def allPort(policy, fr, to, rule):
	#for each port in the port list(fr, to), run the onePort() function
	for port in range(int(fr), int(to)+1):
		policy[0] = str(port) #set policy[0] to the port number instead of 1
		onePort(policy, rule)

def onePort(policy, rule):
	#open specificied port and read all the information into details
	fileName = "resources/port/Port" +policy[0]+ ".txt"
	details = []
	with open(fileName, "r") as read:
		for line in read:
			details.append(line.strip())

	ID = 'ABCDEFGHIJKLMXZ' #for username
			
	for row in xrange(len(details)):
		user = list(ID) #create an array based on ID
		#for each name in array, add Read,Write,Execute counter
		for name in xrange(len(user)):
			user[name] = [user[name], 0, 0, 0]

		#record the Read,Write,Execute in a day of a port
		for col in xrange(len(details[row])):
			for name in xrange(len(user)):
				if details[row][col] == user[name][0]:
					if details[row][col+1] == 'r' and 'r' in policy[2]:
						user[name][1]+=1
					elif details[row][col+1] == 'w' and 'w' in policy[2]:
						user[name][2]+=1
					elif details[row][col+1] == 'x' and 'x' in policy[2]:
						user[name][3]+=1

		#check the total read, write and execute time in a day of a port
		#if the total less than it suppose to be, set it to 0
		for name in xrange(len(user)):
			if user[name][1] < int(policy[3]):
				user[name][1] = 0
			if user[name][2] < int(policy[3]):
				user[name][2] = 0
			if user[name][3] < int(policy[3]):
				user[name][3] = 0

		#open log.txt file to store the logging information
		with open("log.txt", "a") as write:
			#write the rules details into the file
			word = "%s,%s,%s" %(rule+1,policy[0],row+1)
			write.write(word)
			if policy[1] == "any":
				for line in user:
					#write all user information into it
					word = ",%s,%s,%s,%s" %(line[0],line[1],line[2],line[3])
					write.write(word)
				write.write('\n')
			else:
				for name in xrange(len(user)):
					if user[name][0] == policy[1]:
						#write only related user information into it
						word = ",%s,%s,%s,%s" %(user[name][0],user[name][1],user[name][2],user[name][3])
						write.write(word)
				write.write('\n')
					
if __name__ == '__main__':
	Filter();