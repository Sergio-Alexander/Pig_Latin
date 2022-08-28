#include <iostream>
#include <string>
using namespace std;

// Prototype Functions
string cut(string);
string wordFun(string&);
string pigLatinFun(string);

int main()
{
	string buffer;        
	string pigLatin;

	cout << "Enter a sentence and it will get translated to Pig Latin" << endl; // Asking the user for the sentence
	getline(cin, buffer);

	while (buffer.size() > 0)
	{
		string pig = wordFun(buffer);

		pig = pigLatinFun(pig); // Converting the word to PigLatin

		pigLatin = pigLatin + pig + " ";
	}

	cout << endl << endl;

	cout << "The sentence in pigLatin is " << endl; // Outputting the translated sentence
	cout << pigLatin;

	cin.ignore();

	return 0;
}

string cut(string buffer) // Function definition of the function cut
{
	while (buffer[0] == ' ')
	{
		buffer.erase(0, 1); // Deleting the letter at the end of each word
	}
	return buffer;
}


string wordFun(string& buffer)// Function definition of the function wordFun
{
	buffer = cut(buffer); // Cutting 

	int index = 0; // Finding the end of the string
	while (buffer[index] != ' ' && index < buffer.size())
	{
		index++;
	}
		
	string word = buffer.substr(0, index); // Copying the word up until the end of each word

	buffer.erase(0, index); // Deleting the word from the sentence

	return word;
}

string pigLatinFun(string word) // Function Definition of the function pigLatinFun
{
	char first = word[0]; // Getting the first letter of each word

	word.append(1, first); // Add/Append the letter to the end of the word

	word.append("ay"); // Add/Append the word "ay" to the end of the word

	word.erase(0, 1); // Deleting the first letter

	return word;
}