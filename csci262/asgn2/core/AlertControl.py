import sys #for terminate program usage
from time import sleep #to pause system for awhile
from core.Analyzer import Analyzer; #Analyzer() function to generate alert.txt with log.txt

def alert():
	menu = True #temporart turn on the menu
	while menu:
		#formatting purpose only
		print "##################################"
		print "##\t\tAlert\t\t##"
		print "##################################"
		#show menu option
		print "1. Show Alert Policy"
		print "2. Add Alert Policy"
		print "3. Edit Alert Policy"
		print "4. Delete Alert Policy"
		print "5. Run Analyzer"
		print "9. Back to Main Menu"
		print "0. Exit"
		#get input from user and goto respective function
		option = raw_input("Option: ")
		if option == '1':
			show() #display all alert policy information
		elif option == '2':
			add() #add new alert policy
		elif option == '3':
			edit() #edit current alert policy
		elif option == '4':
			delete() #delete alert policy
		elif option == '5':
			Analyzer() #call analyzer to analysis log.txt file
			menu = False
		elif option == '9':
			menu = False
		elif option == '0':
			sys.exit()
		else:
			print "Wrong input, please try again."

#This function is used to show the alert policy
def show():
	print "\nShow Alert Policy,"
	# open policy file and store the data into policy[]
	read = open("resources/alertPolicy.txt", "r")
	policy = []
	for line in read:
		policy.append(line.strip().split(':'))
	# print out the policy[] info one by one
	for row in xrange(len(policy)):
		sleep(0.3)
		print "Alert", row+1
		sleep(0.1)
		print "Port/Rule:", policy[row][0]
		sleep(0.1)
		print "User:", policy[row][1]
		sleep(0.1)
		print "Action:", policy[row][2]
		sleep(0.1)
		print "Threshold:", policy[row][3]
		sleep(0.1)
		print "Trigger:", policy[row][4], "\n"
		sleep(0.5)
	read.close() #close file

# This function is used to add new alert policy
def add():
	# request user to input required data
	print "Add new Alert Policy,"
	print "Enter rule number to check by rule, e.g. 1\nEnter port number to check by port, e.g. 4013"
	port = raw_input("Port/Rule: ")
	print "Enter specific username or 'any' for all user"
	user = raw_input("User: ")
	print "r:read\nw:write\nx:execute"
	action = raw_input("Action: ")
	print "At least how many time the action occur for specific user"
	threshold = raw_input("Threshold: ")
	print "n: Normal analyze\np: Port Access. e.g. p3 (user appear in 3 or more port)\nd: Specific day. e.g. d4 (day 4)"
	trigger = raw_input("Trigger: ")
	
	#open policy file and write appended data into it 
	with open("resources/alertPolicy.txt", "a") as alert:
		alert.write( '\n' + port + ':' + user + ':' + action + ':' + threshold + ':' + trigger)
	sleep(0.4) #pause system
	print "The policy is successfully added." #print success

#This function is used to edit policy  
def edit():
	#open policy file and save the data into policy[]
	print "Edit Alert Policy,"
	policy = []
	with open("resources/alertPolicy.txt", "r") as fil:
		for line in fil:
			policy.append(line.strip().split(':'))

	#request user to input the rules number for edit
	edit = 0 #set for validate purpose only
	while not edit in xrange(1, len(policy)+1):
		edit = raw_input("Rules: ")
		edit = int(edit) 
	edit-=1 #list start with 0, not 1
	print "Enter rule number to check by rule, e.g. 1\nEnter port number to check by port, e.g. 4013"
	policy[edit][0] = raw_input("Port/Rule: ")
	print "Enter specific username or 'any' for all user"
	policy[edit][1] = raw_input("User: ")
	print "r:read\nw:write\nx:execute"
	policy[edit][2] = raw_input("Action: ")
	print "At least how many time the action occur for specific user"
	policy[edit][3] = raw_input("Threshold: ")
	print "n: Normal analyze\np: Port Access. e.g. p3 (user appear in 3 or more port)\nd: Specific day. e.g. d4 (day 4)"
	policy[edit][4] = raw_input("Trigger: ")

	#open file to rewrite all policy into it, include the edited policy
	with open("resources/alertPolicy.txt", "w") as fil:
		for row in xrange(len(policy)):
			fil.write(policy[row][0] + ':' + policy[row][1] + ':' + policy[row][2] + ':' + policy[row][3] + ':' + policy[row][4])
			if row < len(policy)-1:
				fil.write('\n')
	sleep(0.4) #system pause
	print "The policy is successfully updated." #print success

#Thhis function is used to delete policy based on user input
def delete():
	print "Delete Alert Policy,"
	#read all policy into policy[]
	policy = []
	with open("resources/alertPolicy.txt", "r") as fil:
		for line in fil:
			policy.append(line.strip().split(':'))

	#request user to input the policy number wanted to be delete
	delete = 0
	while not delete in xrange(1, len(policy)+1):
		delete = raw_input("Rules: ")
		delete = int(delete)
	delete-=1 #list start with 0, not 1

	#open file and rewrite all policy into it except the policy which is decided to be delete
	with open("resources/alertPolicy.txt", "w") as fil:
		for row in xrange(len(policy)):
			if row != delete:
				if row != 0:
					fil.write('\n')
				fil.write(policy[row][0] + ':' + policy[row][1] + ':' + policy[row][2] + ':' + policy[row][3] + ':' + policy[row][4])
	sleep(0.4)
	print "The policy is successfully updated."

if __name__ == '__main__':
	alert()