TASK 1: 

Write a class Counter which contains a function template CountMe.  This function should take one single object, of arbitrary type, at a time.  Objects of type Counter should keep a record of what types, and how many of those types, have been passed to it through the CountMe function.  You may assume there won’t be more than 10 different types.

You should write a few classes, or copy from other lab exercises, to generate objects of and pass to a Counter object.  You should also write a display function in the Counter class to report on the types and number of objects passed to the Counter object.


TASK 2: 

Create a class template for a class that holds an object and the number of data elements in the object.  For example, if an Employee class has two data elements, an ID number and a salary, then the class template holds the number 2 and an Employee object; if a Student class contains 12 data elements, then the class template holds 12 and a Student object.  Write the code for standard input function for the object that displays a message on the screen – “You will be ask to enter X items” – where X is the number of data elements. Write a main() function that tests your template class with an integer and two programmer-defined classes.