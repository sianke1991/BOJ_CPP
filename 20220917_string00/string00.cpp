#include <string>
#include <iostream>
using namespace std;

//string in cpp
//source from w3schools.com
int main(){
	/*
		Strings are used for storing text.
		A string variable contains a collection of characters surrounded by double quotes:
	*/
	string greeting = "Hello";
	/*
		To use strings, you must include an additional header file in the source code, the <string> library:
		//Include the string library
		#include <string>
		//Create a string variable
		string greeting = "Hello";
	*/
	
	/*
		The + operator can be used between strings to add them together to make a new string.
		This is called concatenation:
	*/
	string firstName = "John ";
	string lastName  = "Doe"  ;
	string fullName  = firstName + lastName;
	cout << fullName << '\n'; //John Doe
	/*
		In the example above, we added a space after firstName to create a space between John and Doe on output.
		However, you could also add a space with quotes (" " or ' '):
	*/
	firstName = "John";
	lastName  = "Doe" ;
	fullName  = firstName + ' ' + lastName;
	cout << fullName << '\n'; //John Doe
	/*
		A string in C++ is actually an object, which contain functions that can perform certain operations on strings.
		For example, you can also concatenate strings with the append() function:
	*/
	firstName = "John ";
	lastName  = "Doe"  ;
	fullName  = firstName.append(lastName);
	cout << fullName << '\n'; //John Doe
	
	/*
		WARNING!
		C++ uses the + operator for both addition and concatenation.
		Numbers are added. Strings are concatenated.
	*/
	/*
		If you add two numbers, the result will be a number:
	*/
	int liX = 10;
	int liY = 20;
	int liZ = liX + liY; //liZ will be 30 (an integer)
	/*
		If you add two strings, the result will be a string concatenation:
	*/
	string lsX = "10";
	string lsY = "20";
	string lsZ = lsX + lsY; //lsZ will be 1020 (a string)
	/*
	If you try to add a number to a string, an error occurs:
	*/
	lsX = "10";
	liY = 20;
	//lsZ = lsX + liY; //[Error] no match for 'operator+'
	//                 //(operand types are 'std::string' {aka 'std::__cxx11::basic_string<char>'} and 'int')
	
	/*
		To get the length of a string, use the length() function:
	*/
	string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << "The length of the txt string is: " << txt.length() << '\n'; //The length of the txt string is: 26
	/*
		Tip: You might see some C++ programs that use the size() function to get the length of a string. 
		This is just an alias of length(). It is completely up to you if you want to use length() or size():
	*/
	txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << "The length of the txt string is: " << txt.size() << '\n'; //The length of the txt string is: 26
	
	/*
		You can access the characters in a string by referring to its index number inside square brackets []. (just like an array...)
		This example prints the first character in myString:
	*/
	string myString = "Hello";
	cout << myString[0] << '\n'; //Outputs H
	/*
		Note: String indexes start with 0: [0] is the first character.
		[1] is the second character, etc.
	*/
	/*
		This example prints the second character in myString:
	*/
	myString = "Hello";
	cout << myString[1] << '\n'; //Outputs e
	/*
		To change the value of a specific character in a string, refer to the index number, and use single quotes: (just like an array...)
	*/
	myString = "Hello";
	myString[0] = 'J';
	cout << myString << '\n'; //Outputs Jello instread of Hello
	
	/*
		It is possible to use the extraction operator >> on cin to display a string entered by a user:
	*/
	cout << "Type your first name: ";
	cin >> firstName; //get user input from the keyboard
	cout << "Your name is: " << firstName << '\n';
	//Type your first name: John
	//Your name is: John
	/*
		However, cin considers a space (whitespace, tabs, etc) as a terminating character, which means that it can only display a single word (even if you type many words):
	*/
	cout << "Type your full name: ";
	cin >> fullName;
	cout << "Your name is: " << fullName << '\n';
	//Type your full name: John Doe
	//Your name is: John
	/*
		From the example above, you would expect the program to print "John Doe", but it only prints "John".
		
		That's why. when working with strings, we often use the getline() function to read a line of text.
		It takes cin as the first parameter, and the string variable as second:
	*/
	cout << "Type your full name: ";
	getline(cin, fullName);
	cout << "Your name is: " << fullName;
	
	/*
		You might see some C++ programs that runs without the standard namespace library.
		The using namespace std line can be omitted and replaced with the std keyword, followed by the :: operator for string (and cout) objects:
	*/
	//std::string greeting = "Hello";
	//std::cout << greeting;
	/*
		It is up to you if you want to include the standard namespace library or not.
	*/
	
	/*
		substr in cpp
	*/
	string romanAlphabet = "abcdefghijklmnop";
	cout << romanAlphabet.substr(2, 5) << '\n'; //cdefg
	return 0;
}