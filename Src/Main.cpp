/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include <string>
#include "fsm/DateFSM.h"
#include "fsm/PasswordFSM.h"
#include "fsm/BinaryNumberFSM.h"
#include "fsm/HexadecimalNumberFSM.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

void showOutput(bool, string);
void runDateAlgorithm(string);
void runPasswordFSM(string);
void runBinaryNumberFSM(string);
void runHexadecimalNumberFSM(string);

int main(int argc, char** argv) {
	string str;

	cout << "Enter a valid date YYYY/MM/DD" << endl << ">> ";
	cin >> str;

	// Date Algorithm
	runDateAlgorithm(str);
	// End of Date Algorithm


	cout << "Enter a valid password [0-9][A-Z]+(#|\*)" << endl << ">> ";
	cin >> str;

	// Password FSM
	runPasswordFSM(str);
	// End of Password FSM


	cout << "Enter a binary number" << endl << ">> ";
	cin >> str;
	// Binary number FSM
	runBinaryNumberFSM(str);
	// End of Binary number FSM


	cout << "Enter an hexadecimal number" << endl << ">> ";
	cin >> str;
	// Hexadecimal number FSM
	runHexadecimalNumberFSM(str);
	// End of Hexadecimal number FSM

	cout << "End of the program" << endl;
	system("pause");
	return 0;
}

void showOutput(bool value, string concat)
{
	string str = "";

	str += value ? "Valid " : "Invalid ";
	str += concat;
	cout << str << endl << endl;
}

void runDateAlgorithm(string dateStr)
{
	if (dateStr.length() != DateFSM::DATE_LENGTH)
	{
		showOutput(false, "date");
		return;
	}
	DateFSM* dateFSM = new DateFSM();
	int i = 0;

	while (i < dateStr.length())
	{
		dateFSM->set(dateStr[i]);

		// Early exit if invalid date
		if (dateFSM->getState() == DateFSM::STATE_INVALID)
		{
			break;
		}
		i++;
	}
	showOutput(dateFSM->getState() == DateFSM::STATE_DATE, "date");
	delete dateFSM;
}

void runPasswordFSM(string pwd)
{
	PasswordFSM* pwdFSM = new PasswordFSM();
	int i = 0;

	while (i < pwd.length())
	{
		pwdFSM->set(pwd[i]);

		// Early exit if invalid password
		if (pwdFSM->getState() == PasswordFSM::STATE_INVALID)
		{
			break;
		}
		i++;
	}
	pwdFSM->setFinished();
	showOutput(pwdFSM->getState() == PasswordFSM::STATE_VALID, "password");
	delete pwdFSM;
}

void runBinaryNumberFSM(string str)
{
	BinaryNumberFSM* binaryFSM = new BinaryNumberFSM();
	int i = 0;

	while (i < str.length())
	{
		binaryFSM->set(str[i]);

		// Early exit if invalid binary number
		if (binaryFSM->getState() == BinaryNumberFSM::STATE_INVALID)
		{
			break;
		}
		i++;
	}
	binaryFSM->setFinished();
	showOutput(binaryFSM->getState() == BinaryNumberFSM::STATE_VALID, "binary number");
	delete binaryFSM;
}

void runHexadecimalNumberFSM(string str)
{
	HexadecimalNumberFSM* hexFSM = new HexadecimalNumberFSM();
	int i = 0;

	while (i < str.length())
	{
		hexFSM->set(str[i]);

		// Early exit if invalid binary number
		if (hexFSM->getState() == HexadecimalNumberFSM::STATE_INVALID)
		{
			break;
		}
		i++;
	}
	hexFSM->setFinished();
	showOutput(hexFSM->getState() == HexadecimalNumberFSM::STATE_VALID, "hexadecimal number");
	delete hexFSM;
}
