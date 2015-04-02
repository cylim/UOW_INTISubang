TASK 1:

For this task, you are required to implement a container class called a Keyed_Bag. A Keyed_Bag is just like an actual bag such as a grocery bag where it keeps a collection of items in no particular order. However, each item added to the bag has a corresponding key.

The collection of the items in this container class should be kept as either an array or a linked list. Provide suitable data members for the class according to your choice. The class should have at least a default constructor to initialize an empty Keyed_Bag. 

Include a function to add an item to the container. The Keyed_Bag container class should allow a data of an arbitrary type to be added by presenting a key (also of an arbitrary type). The type of the key and data may be different. Each item added must have a unique key but may have the same data. Include also a remove function to the container class. To remove a data from the Keyed_Bag, the key of the data must be specified rather than the item itself. The function should return a Boolean value to indicate whether the removal is successful or not. Provide also the isEmpty() function and a destructor for your container class. 

Implement a driver progam to demonstrate three different Keyed_Bag objects. At least one of the Keyed_Bag object should be used to store a user defined type for its data.

TASK 2(USE STL):

For this task, you are required to write a program to simulate the process of assigning customers to an available table in a restaurant. Use the STL Deque to keep track of customers coming to the restaurant. Each customer will be assign to an available table on first come first serve basis. Each customer is given an id. On top of that a customer should also have the number of people coming with them to identify a suitable table to be assigned to them.

Use the STL map to keep a collection of tables in the restaurant. Each item in the map is identified by the table number. Each table keeps the information of the number of seats, customer (if not assigned, this value should be NULL), and a status to indicate if the table is occupied or not.  There should not be any table with the same number.

When the program starts, populate the map with an initial number of tables. All tables should not be occupied upon initialization. You may use a text file with the following format for this initialization where each line contains the table number and number of seats available. 

1	4
2	4
3	2
4	6
5	6
6	10

Declare and implement a simple Customer class with a customer id and total number of people as the data members. Include necessary constructor, accessor, and mutator functions for this class.

Use a menu driven program to simulate the arrival of customers, assignment of tables, adding new tables, and customer leaving the restaurant. When a customer arrives, dynamically create a customer object and push it to the deque containing the customers waiting to be assigned a table. A new customer should always be added to the end of the deque. 

To assign a table, retrieve the first customer from the deque and search for an empty table in the map that has enough seats to assign the customer retrieved. If a table is available, remove the customer from the deque, assign the customer to the map item with the available table number, and set the status of the table to occupied. If no table is available, retrieve another customer record which might have a smaller number of people and search for an available table. Basically, customers are assigned with tables using the first come first serve basis. However, if there is no available table with enough seats, then the next customer with a smaller number can be assigned first. Use the iterator to traverse the deque for this purpose.

The user should allow for new tables to be added to the map. A new table added should always be initialized as an empty table with no customer assigned to it.

When a customer leaves the restaurant, search the map for the table number. If found, reset the customer to NULL and the status to unoccupied.