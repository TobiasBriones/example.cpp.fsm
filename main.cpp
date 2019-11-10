#include <iostream>
#include <string>
#include "DateFSM.h"
#include "PasswordFSM.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

void runDateAlgorithm(string);
void runPasswordFSM(string);

int main(int argc, char** argv) {
	string str;
	
//	cout << "Enter a valid date YYYY/MM/DD" << endl;
//	cin >> str;
//	
//	// Date Algorithm
//	runDateAlgorithm(str);
//	// End of Date Algorithm
	
	cout << "Enter a valid password [0-9][A-Z]+\*|#" << endl; // Check the regex
	cin >> str;
	
	// Password FSM
	runPasswordFSM(str);
	// End of Password FSM
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


void runPasswordFSM(string pwd)
{
	PasswordFSM *pwdFSM = new PasswordFSM();
	int i = 0;
	
	while(i < pwd.length())
	{
		pwdFSM->set(pwd[i]);
		
		// Early exit if invalid password
		if(pwdFSM->getState() == PasswordFSM::STATE_INVALID)
		{
			break;
		}
		i++;
	}
	pwdFSM->setFinished();
	if(pwdFSM->getState() == PasswordFSM::STATE_VALID)
	{
		cout << "Valid password" << endl;
	}
	else
	{
		cout << "Invalid password" << endl;
	}
	delete pwdFSM;
}

