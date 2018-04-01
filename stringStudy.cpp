/*#########################################################
Name: Jesse Goodspeed
Title: Strings
Description: String program uses functions to Reverse a string, check if its a palindrome and output all Substrings of even length
Date: April 24th, 2015
####################################################*/
#include <iostream>
#include <string>
using namespace std;

//function declarations

//Pre-condition: a given string 
//Post-condition: reverses the elements in the given string
string reverse(string s1);

//Pre-condition: a given string
//Post-condition: checks string to see if it is identical to original string after it is reversed
bool isPalindrome(string s1);

//Pre-condition: a given string
//Post-condition: prints all the even-lengthed substrings of the words in the given string
void allEvenSubstr(string s1);


int main(){

	string input;
	char space = ' ';

	cout<<"Enter an input string ( word / sentence )"<<endl;
	getline(cin, input);


	//Call the reverse string function
	cout<<"The reverse of the string is:"<< reverse(input)<<endl;


	//Check if it is a palindrome

	if( isPalindrome(input) )
	{
		cout<<"The input string is a palindrome!\n";
	}


	else
	{
		cout<<"The input string is not a Palindrome!\n";
	}


	//Output even length subtrings of the input string
	cout<<"Even Length Substrings of the input strings are:\n";
	allEvenSubstr(input);

	cout<<endl;



return 0;
}


//function definitions

//reverse-string function
string reverse(string s1)
{
	string temp;

	//for-loop to initialize temp variable with reversed string
	for(int i=0; i<s1.length(); i++)
	{
		temp[i] = s1[s1.length()-1-i];
	}

	//2nd for-loop to assign string with new temp variable (aka reversed string)
	for(int i=0; i<s1.length(); i++)
	{
		s1[i] = temp[i];
	}

	return s1;
}

//palindrome-test function
bool isPalindrome(string s1)
{	
	int h = s1.length();
	char space = ' '; //target
	
	//for-loop to erase all spaces
	for(int i = 0; i<(h-1); i++)
	{
		if(s1[i] == space)
			s1.erase(i, 1);
	}

	//because spaces were removed from the string - the string length has changed
	h = s1.length(); 

	//test for palindrome 
	for(int i=0; i<(h-1); i++)
	{
		if(s1[i] != s1[h-i-1])
			return false;
	}

	return true;
}

//even-substring function
void allEvenSubstr(string s1)
{
	int h = s1.length();
	int gap, anothaGap, start;
	char space = ' ';
	

	for(int i=0; i<h; i++)
	{
		//if-statement prevents substrings that begin with a space
		if(s1[i] != space)
		{
			for(int j=2; j<h-1; j = j+2)
			{
				gap = s1.find(space,i); //searches for spaces and returns their positions in string

				//if-statement prevents including spaces within a substring
				if ((j+i)<=gap)
				{
					string temp = s1.substr(i, j);

					cout<< temp << endl;
				}	

				/*else-if statement prevents the end of a string from being truncated, 
				while printing substrings - STILL BUGGY - will print multiple odd-length substrings
				at tail-end of string*/
				else if (gap <= 0)
				{
					string temp = s1.substr(i, j);

					cout<< temp << endl;
				}


			}
		}
	}
}

