/*
Cameron Tyree
CIS 1202 101
April 12 2024
Part A
*/

#include "personalLibrary.h"

class invalidCharacterExcpeption : public exception {
public:
	const char* what() const throw() {
		return "\n1) Make sure the letter is lower case\n2) Make sure the addition or subtration doesnt make the letter go over A or Z";
	}
};
class invalidRangeException : public exception { 
public:
	const char* what() const throw() {
		return "\n1) Make sure the letter is lower case\n2) Make sure the addition or subtration doesnt make the letter go over A or Z";
	}
};

char character(char start, int offset);

int main() {

	int offset;
	char start;
	cout << "Enter a letter (a - z): ";
	cin >> start;
	offset = validateInt("Enter an offset: ");

	
	try {
		char result = character(start, offset);
		cout << "Result: " << result << endl;
	}
	catch (const invalidCharacterExcpeption& e) {
		cerr << "Exception caught: " << e.what() << endl;
	}
	catch (const invalidRangeException& e) {
		cerr << "Exception caught: " << e.what() << endl;
	}

	endProgram();
}

char character(char start, int offset) {

	if (!isalpha(start) || start < 'a' || start > 'z') {
		throw invalidCharacterExcpeption();
	}
	if ((tolower(start) + offset) > 'z') {
		throw invalidCharacterExcpeption();
	}
	if ((tolower(start) + offset) < 'a') {
		throw invalidCharacterExcpeption();
	}

		int result = (tolower(start) - 'a' + offset) % 26;
		if (result < 0) result += 26;
		return 'a' + result;
}