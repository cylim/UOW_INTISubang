TASK 1: 

You are required to create an application that performs the following tasks:
 
Write a function that opens a text file and reads its contents into a stack container. Then extract the characters from the stack and save them in a second text file. The order of the characters saved in the second file should be the reverse of their order in the first file.
 
Write another function that opens a text file and reads its contents into the STL deque container. Then it should convert it to uppercase, and store it in a second file in the same order as the first file.

Lastly, write one more function that opens two text files and reads their contents into two separate STL vector containers. Then it should determine whether the files are identical by comparing the characters in the vectors. When two nonidentical characters are encountered, the program should display a message indicating that the files are not same otherwise it should indicate that the files are identical. 

Create a suitable driver program to test all the functions above. 

TASK 2: 

The Australian Tax Office (ATO) is currently rewriting a piece of software. As part of the process the ATO needs to migrate a text file, which contains an integer as unique identifier (also known as a tax file number), and a string (a person’s full name which can contain white space characters) per line. Each tax file number is 'normally' associated with one name.

The file may look something like this:

654342 Fred E Smith
213233 Joe Blow
212221 Sarah T Brown

Assuming the appropriate headers are included; the file stream ins is opened for input and a map is created using the declaration,

map<int, string> taxrecord;

Assume the following typedefs exist.

typedef map<int, string>::iterator mapit;
typedef map<int, string> maptype;

(a) Write a function with the prototype	

void populatemap(maptype& taxrecords, ifstream& ins);

Where the map taxrecords, is passed by reference and key/ data pairs are read from the stream ins one by one and inserted into the map. You should report any duplicate insertions into the map with an error message.

(b) Write a function with the prototype	

mapit findrecord(maptype& taxrecords, int key);

where the map taxrecords is passed by reference and an integer key, key, is also passed. The function should attempt to find the key value in the map. If such a value is found, the function should return an iterator pointing to the matched pair, otherwise the value of the return value should be taxrecords.end().
Write a main() function to define and populate the taxrecord map and test the two
functions defined in (a) and (b).