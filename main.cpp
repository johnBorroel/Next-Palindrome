#include <iostream>
#include <string>
using namespace std;


bool allNines(string num)
{
	// using auto iterator as a preference. Can still use "int i" as an index tracker and compare
	// it to the length of the string but I prefer allowing the iterators to check the end point for me
	for (auto it = num.begin(); it != num.end(); ++it)
	{
		// if it finds something that isn't a 9, it should return false immediately
		if (*it != '9')
		{
			return false;
		}
	}
	// if it gets through it all and finds no values besides 9, it can return true
	return true;
}

int nextPalindrome(int num)
{
	// single digit case
	if (num < 10 && num >= 0)
	{
		return num + 1;
	}

	// parsable string instead of an integer
	string numStr = to_string(num);

	// if all digits are 9, with digitCount n >= 2, next palindrome will have digitCount N = n+1, with the two ends being a 1 surrounding N-2 zeros.
	if (allNines(numStr))
	{
		string newString = "1";
		for (int i = 0; i <= numStr.length() - 2; ++i)
		{
			newString += "0";
		}
		newString += "1";
		return stoi(newString);
	}

	// initializing final return value
	int newNum;

	int numLength = numStr.length();

	// middleIndex is calculated the same regardless of digit count parity
	int middleIndex = numLength / 2;

	// case of even digit count. Only dealing with equal sized left and right substrings
	if (numLength % 2 == 0)
	{
		string subLeft = numStr.substr(0, middleIndex);
		string subRight = numStr.substr(middleIndex);

		// creating the reversed leftSub array for easier comparison
		// by reversing the left side, we compare the rightmost digit (now the leftmost digit) to the right side's left most digit.
		string subLeftReversed = string(subLeft.rbegin(), subLeft.rend());

		string newString;

		// comparing the digits in order from closest to the middle to furthest from the middle. Equal pairs will be ignored by nature of comparison
		if(subLeftReversed > subRight)
		{
			// if the left side's digits are larger than the right side's digits, we should simply create a palindrome using the left side
			newString = subLeft + subLeftReversed;
		}
		else
		{
			// if the right side's digits are larger, then we have to increment the left side starting from the middle index and carrying over when necessary
			// instead of having an array handle this and making the code complex, we can simply let regular mathematics handle it by making it into an integer and adding with that
			// this will naturally carry over by standard math rules, eliminating the need for arrays and carry-over handling on our part
			string subLeftIncremented = to_string(stoi(subLeft) + 1);
			newString = subLeftIncremented + string(subLeftIncremented.rbegin(), subLeftIncremented.rend());
		}
		// using stoi to turn the created string into a number that can be returned to the caller
		newNum = stoi(newString);
	}
	// case of odd digit count. Dealing with equal sized left and right substrings AND a middle digit between them.
	else
	{
		string subLeft = numStr.substr(0, middleIndex);

		// incrementing one to the middle index because we wish to compare the two equal sized halves without dealing with the middle index which doesn't need to be compared
		string subRight = numStr.substr(middleIndex + 1);
		string subLeftReversed = string(subLeft.rbegin(), subLeft.rend());

		string newString;
		if (subLeftReversed > subRight)
		{
			// same as before but adding in the middle index before passing it on so it isn't cut out
			newString = subLeft + numStr[middleIndex] + subLeftReversed;
		}
		else
		{
			// accounting for the middle index as part of the increment process, which is why it is added to
			// subLeftIncremented and removed from the string creation after to avoid duplicate middle indexes.
			string subLeftIncremented = to_string(stoi(subLeft + numStr[middleIndex]) + 1);
			newString = subLeftIncremented + string(subLeftIncremented.rbegin() + 1, subLeftIncremented.rend());
		}
		newNum = stoi(newString);
	}

	return newNum;
}

int main(void)
{
	// use this to test the function
	cout << nextPalindrome(1471);
	return 0;
}
