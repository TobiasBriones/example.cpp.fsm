#include <iostream>
#include <string>
#include "DateFSM.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

void runDateAlgorithm(string);

int main(int argc, char** argv) {
	string str;
	
	cout << "Enter a valid date YYYY/MM/DD" << endl;
	cin >> str;
	
	// Date Algorithm
	runDateAlgorithm(str);
	// End of Date Algorithm
	return 0;
}

void runDateAlgorithm(string dateStr)
{
	DateFSM *dateFSM = new DateFSM();
	int i = 0;
	
	if(dateStr.length() == DateFSM::DATE_LENGTH)
	{
		while(i < dateStr.length())
		{
			dateFSM->set(dateStr[i]);
			
			// Early exit if invalid date
			if(dateFSM->getState() == DateFSM::STATE_INVALID)
			{
				break;
			}
			i++;
		}
		if(dateFSM->getState() == DateFSM::STATE_DATE)
		{
			cout << "Correct date" << endl;
		}
		else
		{
			cout << "Invalid date" << endl;
		}
	}
	else
	{
		cout << "Invalid date" << endl;
	}
	delete dateFSM;
}

