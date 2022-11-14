/*

		CSC122AB Data Structures, Project 2, 2022

		Group Members -
		
		1. Hieu Nguyen

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

// The method that returns the result of raising a number to a power
int pow(int base, int power){
  if(power == 0 || base == 1)
    return 1;
  return base * pow(base, power - 1);
}

// The method that return the priority order of an operation (1 being lowest and 4 being highest)
int priority(string a) {
  if (a == "^") 
    return 4;
  else if (a == "*" || a == "/")
    return 3;
  else if (a == "+" || a == "-")
    return 2;
  else 
    return 1;
}

// Calculate the result of an expression with two integers based on the expression
int calculate(int a, int b, string c){
  if (c == "^") 
    return pow(a, b);
  else if (c == "*")
    return a * b;
  else if (c == "/")
    return a / b;
  else if (c == "+")
    return a + b;
  else
    return a - b;
}

// Check if the input is a valid numeric Infix expression
bool checkString(string s){
  for(int i = 0; i < s.length(); i++){
    if((s[i] < '0' || s[i] > '9') && (s[i] != '-' && s[i] != '+' && s[i] != '/' && s[i] != '*' && s[i] != '^' && s[i] != '(' && s[i] != ')' && s[i] != ' '))
      return false;
  }
  return true;
}

// Check if the the string (which is only 1 character in this case) is a number or an operation
bool isNumber(string a){
  if (a != "(" && a != ")" && a != "+" && a != "-" && a != "*" && a != "/" && a != "^")
    return true;
  return false;
}

int main() {
	// P1. Read infix string from user. Ensure the input entered by the user is a valid numeric Infix expression. (10 Points).
  string a;
  cout << "Please enter an arithmetic expression: " << endl;
	getline(cin, a);
  while(!checkString(a)){ 
    cout << "Please enter a valid numeric expression: " << endl;
    getline(cin, a);
  }
	vector<string> b = split(a, ' ');
  
	// P2. Convert infix string to postfix string (20 Points).
  vector<string> c;
  stack<string> d;
  for (int i = 0; i < b.size(); i++) {
    if(isNumber(b[i])) {
      c.push_back(b[i]);
    } else if (d.empty()) {
      d.push(b[i]);
    } else if (b[i] == "(") {
      d.push(b[i]);
    } else if (b[i] == ")") {
        while (d.top() != "("){
          c.push_back(d.top());
          d.pop();
        }
        d.pop();
    } else {
        if (priority(d.top()) < priority(b[i])) {
          d.push(b[i]);
        } else {
          while (priority(d.top()) >= priority(b[i])) {
            c.push_back(d.top());
            d.pop();
            if(d.empty()) break;
          }
          d.push(b[i]);
        }
      }
    }
  while (!d.empty()) {
    c.push_back(d.top());
    d.pop();
  }
  
	// P3. Evaluate Postfix String (20 Points).
  stack<int> e;
  for(int i = 0; i < c.size(); i++){
	 	if(isNumber(c[i])) {
      e.push(stoi(c[i]));  
    } else {
      int f = e.top();
      e.pop();
      f = calculate(e.top(), f, c[i]);
      e.pop();
      e.push(f);
    } 
	}
  cout << "The value of that expression is: " << e.top() << endl;
  return 0;
} 