// 
// Program to find all anagrams of a given word, using a dictionary read from a file
// 
// CSCI204 SP05 - Assignment 3
// Task1 - Algorithm2
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

typedef multimap<string, string> WordMap;
typedef WordMap::value_type value_type;
ostream& operator<<(ostream& os, const value_type& wp) {
	os<<wp.second;
	return os;
}

int main() 
{
  	cout << "Anagram finding program:\n"<< "finds all words in a dictionary that can\n"
    		<< "be formed with the letters of a given word.\n" << endl;
  	cout << "First, enter the name of the file containing\n"<< "the dictionary: " << flush;
  	string dictionary_name; 
  	cin >> dictionary_name;

  	ifstream ifs(dictionary_name.c_str());
  	if (!ifs.is_open()) {
    		cout << "Eh? Could not open file named "<< dictionary_name << endl;
    		exit(1);
  	}
  	cout << "\nReading the dictionary ..." << flush;
  
	typedef istream_iterator<string> string_input;
  	vector<string> dictionary;
  	copy(string_input(ifs), string_input(), back_inserter(dictionary));
  	cout << "\nThe dictionary contains "<< dictionary.size() << " words.\n\n";

  	// create a multimap from the vector container
  	WordMap dicmap;

  	vector<string>::const_iterator l;
  	for(l=dictionary.begin(); l<dictionary.end();++l) {
		string key = *l;
        	string value = *l;
		sort(key.begin(), key.end());
		dicmap.insert(value_type(key,value));
  	}

  	cout << "Now type a word (or any string of letters),\n"
		<< "and I'll see if it has any anagrams: " << flush;
  	for (string_input j(cin); j != string_input(); ++j) {
    		string sword = *j;
    		sort(sword.begin(), sword.end());
    		bool found_one = false;
    		pair<WordMap::iterator, WordMap::iterator> range = dicmap.equal_range(sword);
		// output anagrams of the input word
		/*
    		WordMap::iterator l = range.first;
    		while (l != range.second) {
        		cout<<((*(l)).second)<<endl;
			++l;
			found_one = true;
    		}
		*/
    		if (range.first != range.second) {
			found_one = true;
        		copy(range.first, range.second, ostream_iterator<value_type>(cout, "\n"));
		}
    		if (!found_one) 
        		cout << "  Sorry, none found.\n";
        	cout << "\nType another word " << "(or the end-of-file char to stop): " << flush; 
  	}
  	return 0;
}

