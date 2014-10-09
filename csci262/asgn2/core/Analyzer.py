from time import sleep
#This function used to analysis the log.txt file and create alert.txt output.
def Analyzer():
	print "Analysis log.txt activity with alert policy,"
	#read log.txt into log[]
	log = []
	with open("log.txt", "r") as fil:
		for line in fil:
			log.append(line.strip().split(','))
	#read alert policy into policy[]
	policy = []
	with open("resources/alertPolicy.txt", "r") as fil:
		for line in fil:
			policy.append(line.strip().split(':'))

	ID = 'ABCDEFGHIJKLMX' #for username
	open("alert.txt", "w").close() #clear everything inside the file
	fil = open("alert.txt", "a") #append mode

	for row in xrange(len(policy)):
		sleep(0.4)
		print "Generating Alert %s ..." %(row+1)
		#Save Alert Number into a string, and then write into file
		toWrite = "Alert %d,\n" %(row+1)
		fil.write(toWrite)
		if policy[row][4] == 'n':
			normal(policy[row], log, ID, fil)
		elif policy[row][4][0] == 'd':
			day(policy[row], log, ID, fil)
		elif policy[row][4][0] == 'p':
			port(policy[row], log, ID, fil)
		else:
			print "Alert %s not working." %(row+1)
			toWrite = "Alert options is not valid."
			fil.write(toWrite)

	fil.close()
	sleep(0.2)
	print "Analyze process finished."
	sleep(0.2)

def normal(policy, log, ID, fil):
	#for each log[], perform below operation
	for row in xrange(len(log)):
		writeFile(policy, log[row], ID, fil)	

def day(policy, log, ID, fil):
	policy[4] = policy[4][1:]
	for row in xrange(len(log)):
		#check if day is same as the log.txt
		if policy[4] == log[row][2]:
			writeFile(policy, log[row], ID, fil)

def port(policy, log, ID, fil):
	policy[4] = policy[4][1:]
	countR, countW, countX = [0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0]
	portR, portW, portX = ['','','','','','','','','',''],['','','','','','','','','',''],['','','','','','','','','','']
	for row in xrange(len(log)):
		if policy[0] == log[row][0]:
			#check by specific day
			for num in xrange(10):
				if int(log[row][2]) == num+1:
					for user in xrange(3, len(log[row])-3):
						if policy[1] in log[row][user]:
							if 'r' in policy[2]:
								if not log[row][1] in portR[num]:
									if policy[3] <= log[row][user+1]:
										countR[num] += 1
										portR[num] = "%s %s" %(portR[num], log[row][1])
							if 'w' in policy[2]:
								if not log[row][1] in portW[num]:
									if policy[3] <= log[row][user+2]:
										countW[num] += 1
										portW[num] = "%s %s" %(portW[num], log[row][1])
							if 'x' in policy[2]:
								if not log[row][1] in portX[num]:
									if policy[3] <= log[row][user+3]:
										countX[num] += 1
										portX[num] = "%s %s" %(portX[num], log[row][1])

	#check whether it have access enough port
	for num in xrange(10):
		if countR[num] >= int(policy[4]):
			toWrite = "User: %s, Action: read in day %s exceed %s port, port: %s\n" %(policy[1], num+1, policy[4], portR[num])
			fil.write(toWrite)
		if countW[num] >= int(policy[4]):
			toWrite = "User: %s, Action: write in day %s exceed %s port, port: %s\n" %(policy[1], num+1, policy[4], portW[num])
			fil.write(toWrite)
		if countX[num] >= int(policy[4]):
			toWrite = "User: %s, Action: execute in day %s exceed %s port, port: %s\n" %(policy[1], num+1, policy[4], portX[num])
			fil.write(toWrite)

def writeFile(policy, log, ID, fil):
	if policy[0] == log[1]: #if the port is same
		#for each user in the log file, check the read, write and execute
		for user in xrange(3, len(log)-3):
			if policy[1] == "any": #if the username fill is any
				if log[user] in ID: #when the name matched with ID
					#if the policy write contain checking in read, write and/or execute, 
					#check the total trigger, if the total trigger higher than the alert, write it into file
					if 'r' in policy[2]:
						if policy[3] <= log[user+1]:
							toWrite = "user:%s, action: read exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)
					if 'w' in policy[2]:
						if policy[3] <= log[user+2]:
							toWrite = "user:%s, action: write exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)
					if 'x' in policy[2]:
						if policy[3] <= log[user+3]:
							toWrite = "user:%s, action: execute exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)

			#if the username is same as one of the user in the log
			elif policy[1] == log[user]:
				if log[user] == 'Z':
					if 'r' in policy[2]:
						if policy[3] <= log[user+1]:
							toWrite = "Inactive read session on port %s exceed %s time in day %s\n" %(log[1], policy[3], log[2])
							fil.write(toWrite)
					if 'w' in policy[2]:
						if policy[3] <= log[user+2]:
							toWrite = "Inactive write session on port %s exceed %s time in day %s\n" %(log[1], policy[3], log[2])
							fil.write(toWrite)
					if 'x' in policy[2]:
						if policy[3] <= log[user+3]:
							toWrite = "Inactive execute session on port %s exceed %s time in day %s\n" %(log[1], policy[3], log[2])
							fil.write(toWrite)
				else:
				#if the policy write contain checking in read, write and/or execute, 
				#check the total trigger, if the total trigger higher than the alert, write it into file
					if 'r' in policy[2]:
						if policy[3] <= log[user+1]:
							toWrite = "user:%s, action: read exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)
					if 'w' in policy[2]:
						if policy[3] <= log[user+2]:
							toWrite = "user:%s, action: write exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)
					if 'x' in policy[2]:
						if policy[3] <= log[user+3]:
							toWrite = "user:%s, action: execute exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)

	elif policy[0] == log[0]: #if the rules is same
		for user in xrange(3, len(log)-3):
			if policy[1] == "any": #if the username fill is any
				if log[user] in ID: #when the name matched with ID
					#if the policy write contain checking in read, write and/or execute, 
					#check the total trigger, if the total trigger higher than the alert, write it into file
					if 'r' in policy[2]:
						if policy[3] <= log[user+1]:
							toWrite = "user:%s, action: read exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)
					if 'w' in policy[2]:
						if policy[3] <= log[user+2]:
							toWrite = "user:%s, action: write exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)
					if 'x' in policy[2]:
						if policy[3] <= log[user+3]:
							toWrite = "user:%s, action: execute exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)

			#if the username is same as one of the user in the log
			elif policy[1] == log[user]:
				if log[user] == 'Z':
					if 'r' in policy[2]:
						if policy[3] <= log[user+1]:
							toWrite = "Inactive read session on port %s exceed %s time in day %s\n" %(log[1], policy[3], log[2])
							fil.write(toWrite)
					if 'w' in policy[2]:
						if policy[3] <= log[user+2]:
							toWrite = "Inactive write session on port %s exceed %s time in day %s\n" %(log[1], policy[3], log[2])
							fil.write(toWrite)
					if 'x' in policy[2]:
						if policy[3] <= log[user+3]:
							toWrite = "Inactive execute session on port %s exceed %s time in day %s\n" %(log[1], policy[3], log[2])
							fil.write(toWrite)
				else:
					#if the policy write contain checking in read, write and/or execute, 
					#check the total trigger, if the total trigger higher than the alert, write it into file
					if 'r' in policy[2]:
						if policy[3] <= log[user+1]:
							toWrite = "user:%s, action: read exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)
					if 'w' in policy[2]:
						if policy[3] <= log[user+2]:
							toWrite = "user:%s, action: write exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)
					if 'x' in policy[2]:
						if policy[3] <= log[user+3]:
							toWrite = "user:%s, action: execute exceed %s on port %s in day %s\n" %(log[user], policy[3], log[1], log[2])
							fil.write(toWrite)

if __name__ == '__main__':
	analyzer();