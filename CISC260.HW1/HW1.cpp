/*
 * HW1.cpp
 *
 *  Created on: Sep 17, 2017
 *      Author: Michael Ly
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <array>
#include <string.h>

using namespace std;

string cnvrtDeci(int x);
string Bin4Digs(int x);
string deciToBinary(int x);
int hexToDeci(string x);
string deciToHex(int x);

int main() {


 	cout << "Problem 1:" << endl;
 	cout << "Converting Decimal to Binary..." << endl;
 	cout << "Test 1: When passing in an integer of 12 to the function..." << endl;
 	cout << "The function outputs: " << deciToBinary(12) << endl;
 	// Expected output of 00000000000000000000000000001100.
 	cout << endl;
 	cout << "Test 2: When passing in an integer of -12 to the function..." << endl;
 	cout << "The function outputs: " << deciToBinary(-12) << endl;
 	// Expected output of 11111111111111111111111111110100.
 	cout << endl;
 	cout << "Test 3: When passing in an integer of 1035 to the function..." << endl;
 	cout << "The function outputs: " << deciToBinary(1035) << endl;
 	// Expected output of 00000000000000000000010000001011.
 	cout << endl;
 	cout << "Test 4: When passing in an integer of -1035 to the function..." << endl;
 	cout << "The function outputs: " << deciToBinary(-1035) << endl;
 	// Expected output of 11111111111111111111101111110101.
 	cout << endl;

 	cout << "Converting Decimal to Hexadecimal..." << endl;
 	cout << "Test 1: When passing in an integer of 12 to the function..." << endl;
 	cout << "The function outputs: " << deciToHex(12) << endl;
 	// Expected output of 0000000C.
 	cout << endl;
 	cout << "Test 2: When passing in an integer of -12 to the function..." << endl;
 	cout << "The function outputs: " << deciToHex(-12) << endl;
 	// Expected output of FFFFFFF4.
 	cout << endl;
 	cout << "Test 3: When passing in an integer of 1035 to the function..." << endl;
 	cout << "The function outputs: " << deciToHex(1035) << endl;
 	// Expected output of 0000040B.
 	cout << endl;
 	cout << "Test 4: When passing in an integer of -1035 to the function..." << endl;
 	cout << "The function outputs: " << deciToHex(-1035) << endl;
 	// Expected output of FFFFFBF5.
 	cout << "****************************************" << endl;

 	cout << "Problem 2: " << "Converting Hexadecimal to Decimal..." << endl;
 	cout << "Test 1: When passing in a string of 5098 to the function..." << endl;
 	cout << "The function outputs: " << hexToDeci("5098") << endl; // Expected output of 20632.
 	cout << endl;
 	cout << "Test 2: When passing in a string of AF94587 to the function..." << endl;
 	cout << "The function outputs: " << hexToDeci("AF94587") << endl; // Expected output of 184108423.
 	cout << endl;
 	cout << "Test 3: When passing in a string of F4AC to the function..." << endl;
 	cout << "The function outputs: " << hexToDeci("F4AC") << endl; // Expected output of 62636.

	return 0;

}

string cnvrtDeci(int x) {
	int val = abs(x);
	string result = "";
	while (val > 0) {
		result = to_string(val%2)+result;
		val = val/2;
	}
	return result;
}

string Bin4Digs(int x) {
	string result;
	result = cnvrtDeci(x);
	while (result.length() < 4) {
		result = to_string(0)+result;
	}
	return result;
}

string deciToBinary(int x) {
	string result;
	if (x >= 0) {
		result = cnvrtDeci(x);
		while (result.length() < 32) {
			result = to_string(0)+result;
		}
	}
	else {
		result = cnvrtDeci(x);
		bool brk = false;
		for (int i=0; i<result.length(); i++) {
			if (result[i] == '0') {
				result[i] = '1';
			}
			else {
				result[i] = '0';
			}
		}
		for (int i=result.length()-1; i>=-1&&brk==false; i--) {
			if (i == -1) {
				result = to_string(1)+result;
				result.replace(1, result.length()-1, to_string(0));
				brk = true;
			}
			else {
				if (result[i] == '0') {
					result[i] = '1';
					brk = true;
				}
				else {
					result[i] = '0';
				}
			}
		}
		while (result.length() < 32) {
			result = to_string(1)+result;
		}
	}
	return result;
}

string deciToHex(int x) {
	string result = "";
	string binary = deciToBinary(x);
	int sumgroup;
	string digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
	string group1 = binary.substr(28, 4);
	string group2 = binary.substr(24, 4);
	string group3 = binary.substr(20, 4);
	string group4 = binary.substr(16, 4);
	string group5 = binary.substr(12, 4);
	string group6 = binary.substr(8, 4);
	string group7 = binary.substr(4, 4);
	string group8 = binary.substr(0, 4);
	string arr[] = {group1, group2, group3, group4, group5, group6, group7, group8};
	for (int i=0; i<8; i++) {
		sumgroup = 0;
		for (int j=0; j<4; j++) {
			if (arr[i][j]=='1') {
				if (j==0) {
					sumgroup += 8;
				}
				if (j==1) {
					sumgroup += 4;
				}
				if (j==2) {
					sumgroup += 2;
				}
				if (j==3) {
					sumgroup += 1;
				}
			}
		}
		result = digits[sumgroup]+result;
	}
	return result;
}

int hexToDeci(string x) {
	int result = 0;
	for (int i=0; i<x.length(); i++) {
		if (x[i] == '1') {
			result += 1*pow(16, x.length()-1-i);
		}
		else if (x[i] == '2') {
			result += 2*pow(16, x.length()-1-i);
		}
		else if (x[i] == '3') {
			result += 3*pow(16, x.length()-1-i);
		}
		else if (x[i] == '4') {
			result += 4*pow(16, x.length()-1-i);
		}
		else if (x[i] == '5') {
			result += 5*pow(16, x.length()-1-i);
		}
		else if (x[i] == '6') {
			result += 6*pow(16, x.length()-1-i);
		}
		else if (x[i] == '7') {
			result += 7*pow(16, x.length()-1-i);
		}
		else if (x[i] == '8') {
			result += 8*pow(16, x.length()-1-i);
		}
		else if (x[i] == '9') {
			result += 9*pow(16, x.length()-1-i);
		}
		else if (x[i] == 'A') {
			result += 10*pow(16, x.length()-1-i);
		}
		else if (x[i] == 'B') {
			result += 11*pow(16, x.length()-1-i);
		}
		else if (x[i] == 'C') {
			result += 12*pow(16, x.length()-1-i);
		}
		else if (x[i] == 'D') {
			result += 13*pow(16, x.length()-1-i);
		}
		else if (x[i] == 'E') {
			result += 14*pow(16, x.length()-1-i);
		}
		else if (x[i] == 'F') {
			result += 15*pow(16, x.length()-1-i);
		}
		else {
			result += 0*pow(0, x.length()-1-i);
		}
	}
	return result;
}


