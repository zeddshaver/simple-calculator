/*

		CSC122AB Data Structures, Project 2, 2022

		Group Members -
		
		1.

		2.

		3.

*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/*

		Method for splitting a string.

		Returns a vector of strings.

*/
vector<string> split(const string &s, char delimiter) { 
  stringstream ss(s); 
  string item; 
  vector<string> result; 
  while (getline(ss, item, delimiter)) { 
    result.push_back(item); 
  } 
  return result; 
} 

int main() {
	/*
		Example Code for reading input into vector.
  */
	string a;

	getline(cin, a);

	vector<string> b = split(a, ' ');

	for(int i = 0; i < b.size(); i++){
		cout << b[i] << endl;
	}
	
	/*
	 Your Code Here.

	 Feel free to design your own functions 
			or classes to help keep your code tidy. 

	 Please comment your code where necessary.
	*/
	
	// P1. Read infix string from user. Ensure the input entered by the user is a valid numeric Infix expression. (10 Points).

	// P2. Convert infix string to postfix string (20 Points).

	// P3. Evaluate Postfix String (20 Points).

} 