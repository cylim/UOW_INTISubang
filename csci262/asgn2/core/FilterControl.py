import sys #for terminate program usage
from time import sleep #to pause system for awhile
from core.Filter import Filter #Filter() function to generate log.txt

def fil():
	menu = True #temporary turn on the menu
	while menu:
		#for formating purpose only
		print "##################################"
		print "##\t\tFilter\t\t##"
		print "##################################"
		#show menu option
		print "1. Show Filter Policy"
		print "2. Add Filter Policy"
		print "3. Edit Filter Policy"
		print "4. Delete Filter Policy"
		print "5. Run Filter"
		print "9. Back to Main Menu"
		print "0. Exit"
	
		option = raw_input("Option: ") #get input to choose option
		if option == '1':
			show()	#display all Filter policy information
		elif option == '2':
			add()	#add new Filter policy
		elif option == '3':
			edit()	#edit current Filter policy
		elif option == '4':
			delete()	#delete Filter policy
		elif option == '5':
			fr = raw_input("From port: ")
			to = raw_input("To port: ")
			Filter(fr, to) #call Filter to filter the normal data of port file
			menu = False
		elif option == '9':
			menu = False #set Menu to False, so it will back to Main()
		elif option == '0':
			sys.exit() #terminated program
		else:
			print "Wrong input, please try again."

#This function is used to show the policy
def show():
	print "\nShow Filter Policy,"
	#open policy file as read, and store it into policy[]
	read = open("resources/filterPolicy.txt", "r")
	policy = []
	for line in read:
		policy.append(line.strip().split(':'))
	#print out the policy[] one by one
	for row in xrange(len(policy)):
		sleep(0.3)
		print "Rule", row+1
		sleep(0.1)
		print "Port:", policy[row][0]
		sleep(0.1)
		print "User:", policy[row][1]
		sleep(0.1)
		print "Action:", policy[row][2]
		sleep(0.1)
		print "Threshold:", policy[row][3], '\n'
		sleep(0.5)
	read.close() #close file

#This function is used to add new policy
def add():
	#request user to input required data one by one
	print "Add new Filter Policy,"
	print "input '1' for all port\nPort Number for specific port, e.g. 4013\nRange port use '-', e.g. 4010-4012"
	port = raw_input("Port: ")
	print "Enter specific username or 'any' for all user"
	user = raw_input("User: ")
	print "r:read\nw:write\nx:execute"
	action = raw_input("Action: ")
	print "At least how many time the action occur for specific user"
	threshold = raw_input("Threshold: ")

	#open policy file and save append the data into it
	with open("resources/filterPolicy.txt", "a") as fil:
		fil.write( '\n' + port + ':' + user + ':' + action + ':' + threshold)
	sleep(0.4) #system pause
	print "The policy is successfully added." #print success

#this function is used to edit policy which is already set
def edit():
	#open policy file and save the data into policy[]
	print "Edit Filter Policy,"
	policy = []
	with open("resources/filterPolicy.txt", "r") as fil:
		for line in fil:
			policy.append(line.strip().split(':'))

	#request user to input the rules number for edit
	edit = 0 #set for validate purpose only
	while not edit in xrange(1, len(policy)+1):
		edit = raw_input("Rules: ")
		edit = int(edit)
	edit -=1 #list start with 0, not 1
	print "input '1' for all port\nPort Number for specific port, e.g. 4013\nRange port use '-', e.g. 4010-4012"
	policy[edit][0] = raw_input("Port: ")
	print "Enter specific username or 'any' for all user"
	policy[edit][1] = raw_input("User: ")
	print "r:read\nw:write\nx:execute"
	policy[edit][2] = raw_input("Action: ")
	print "At least how many time the action occur for specific user"
	policy[edit][3] = raw_input("Threshold: ")

	#open file to rewrite all policy into it, include the edited policy
	with open("resources/filterPolicy.txt", "w") as fil:
		for row in xrange(len(policy)):
			fil.write(policy[row][0] + ':' + policy[row][1] + ':' + policy[row][2] + ':' + policy[row][3])
			if row < len(policy)-1:
				fil.write('\n')
	sleep(0.4) #system pause
	print "The policy is successfully updated." #print success

#this function is used to delete unwanted policy
def delete():
	print "Delete Filter Policy,"
	#read all policy into policy[]
	policy = []
	with open("resources/filterPolicy.txt", "r") as fil:
		for line in fil:
			policy.append(line.strip().split(':'))

	#request user to input the policy number wanted to be delete
	delete = 0
	while not delete in xrange(1, len(policy)+1):
		delete = raw_input("Rules: ")
		delete = int(delete)
	delete-=1 #list start with 0, not 1

	#open file and rewrite all policy into it except the policy which is decided to be delete
	with open("resources/filterPolicy.txt", "w") as fil:
		for row in xrange(len(policy)):
			if row != delete:
				if row != 0:
					fil.write('\n')
				fil.write(policy[row][0] + ':' + policy[row][1] + ':' + policy[row][2] + ':' + policy[row][3])
	sleep(0.4)
	print "The policy is successfully updated."

if __name__ == '__main__':
	fil()