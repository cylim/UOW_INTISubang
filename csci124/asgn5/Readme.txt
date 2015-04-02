Problem Specification:

Implement a menu-driven program for a hardware store that keeps the inventory records and also the sale transaction records for all its hardware items. Each hardware item is known with its barcode, description, price per unit, and quantity in hand. Use a suitable struct declaration to represent each item’s record. All the hardware items’ information is stored in a binary search tree to allow fast retrieval of a particular record. Each transaction record, which consists of invoice number, hardware item’s barcode, quantity purchased, and the total price, is stored in a linked list data structure. 

The program starts by reading a filename containing a list of hardware items information. Construct a binary search tree to store all the hardware items read from this file with the barcode as the key. A menu should be displayed to allow a user to perform the following operations:

Update a hardware item’s quantity in hand or price per unit
Add a new hardware item
Display either all items or one item’s record by reading the barcode
Perform a sales transaction – allow several hardware items to be purchased
Remove a sales transaction based on invoice number
Edit a sales transaction by changing the hardware item’s barcode and/or quantity purchased
Display all sales transaction done together with a grand total sales amount

For each transaction performed, the program should prompt the user for a barcode and traverse the binary search tree to identify if the barcode exists. If it exists, prompt for the quantity and check it against the record stored in the binary search tree. No transaction should be done if the quantity in hand is not sufficient for the transaction. If the record doesn’t exists, request if the user would like to add a new record and continue with the transaction, otherwise go back to main menu. If a transaction is done, add a new node containing the transaction details to the end of the linked list. The program should start with an empty linked list. A node should contain only one hardware item’s information. If the transaction involved more than one hardware item, then more than one node should be created and added to the linked list.  

Before the program terminates, update the file containing the hardware items’ information and add to a transaction file all the transaction records in the list.  Use functions to implement each option. Each data structure (linked list and binary search tree) must be implemented as a class and store each classes in separate .cpp files with appropriate headers. Your driver program should be saved in a file named main.cpp.