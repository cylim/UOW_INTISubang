#AUTHOR		:Lim Chee Yeong
#STUDENT ID	: J14016414(INTI) or 4933643(UOW)
#CLASS		:CSCI262
#ASSIGNMENT	:2
#Date		:25th September 2014
#This is a simple logging and detection system written in python

from core.FilterControl import fil #import fil() function from ~core/Filter.py
from core.AlertControl import alert #import alert() function from ~core/Alert.py
from core.Filter import Filter #Filter() function to generate log.txt
from core.Analyzer import Analyzer; #Analyzer() function to generate alert.txt
import sys #import standard library for direct contact with command line, passing arguments and terminate program

def main():
	#when there is a system argument, and the argument is -f go to Filter Menu,
	#if the arugment is -a then go to Analyzer menu
	if len(sys.argv) >=2: 
		if sys.argv[1] == '-f':
			Filter(sys.argv[2], sys.argv[3])
		elif sys.argv[1] == '-a':
			Analyzer()
		else:
			print "Invalid arguments, SYSTEM TERMINATED!"
			sys.exit();
	#if no default argument, then show the menu	
	#the menu is conducted in infinite loop, 
	#user can either close it or input valid data to proceed
	while True:
		#show the label of the menu, in this case Main Menu
		print "##########################################"
		print "##\t\tMain Menu\t\t##"
		print "##########################################"
		#show the option of the menu
		print "1. Filter Menu"
		print "2. Analyzer Menu"
		print "0. Exit"
		#require input from user to select option
		option = raw_input("Option: ")
		if option == '1':
			fil() #go to Filter menu if selected 1
		elif option == '2':
			alert() #go to Analyzer menu if selected 2
		elif option == '0':
			sys.exit() #terminated the program when user input 0
		else:
			#any other input consider as wrong input, ask user to re-input
			print "Wrong input, please try again."

# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
	main()