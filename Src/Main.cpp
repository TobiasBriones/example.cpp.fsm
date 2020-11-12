/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include <string>
#include "Fsm/DateFsm.h"
#include "Fsm/PasswordFsm.h"
#include "Fsm/BinaryNumberFsm.h"
#include "Fsm/HexadecimalNumberFsm.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

void showOutput(bool, const string&);

void runDateAlgorithm(string);
void runPasswordFsm(string);
void runBinaryNumberFsm(string);
void runHexadecimalNumberFsm(string);

int main(int argc, char** argv)
{
    string str;

    cout << "Example Project - Finite State Machines" << endl;
    cout << "Several FSMs are presented next" << endl << endl;

    cout << "Date Fsm" << endl;
    cout << "Enter a valid date YYYY/MM/DD" << endl << ">> ";
    cin >> str;

    // Date Algorithm
    runDateAlgorithm(str);
    // End of Date Algorithm

    cout << "Password Fsm" << endl;
    cout << "Enter a valid password [0-9][A-Z]+(#|\*)" << endl << ">> ";
    cin >> str;

    // Password Fsm
    runPasswordFsm(str);
    // End of Password Fsm

    cout << "Binary Number Fsm" << endl;
    cout << "Enter a binary number" << endl << ">> ";
    cin >> str;
    // Binary number Fsm
    runBinaryNumberFsm(str);
    // End of Binary number Fsm

    cout << "Hexadecimal Number Fsm" << endl;
    cout << "Enter an hexadecimal number" << endl << ">> ";
    cin >> str;
    // Hexadecimal number Fsm
    runHexadecimalNumberFsm(str);
    // End of Hexadecimal number Fsm

    cout << "End of Fsm demonstrations";
    cout << endl << endl << endl;
    cout << "Great job by studying the Example Projects!" << endl;
    cout << "Learn more by accessing the Example Projects at https://tobiasbriones.engineer/ or https://github"
            ".com/TobiasBriones/";
    cout << endl << endl << endl;
    system("pause");
    return 0;
}

void showOutput(bool value, const string& concat)
{
    string str;

    str += value ? "Valid " : "Invalid ";
    str += concat;
    cout << str << endl << endl;
}

void runDateAlgorithm(string dateStr)
{
    if (dateStr.length() != DateFsm::DATE_LENGTH)
    {
        showOutput(false, "date");
        return;
    }
    auto* dateFsm = new DateFsm();
    int i = 0;

    while (i < dateStr.length())
    {
        dateFsm->set(dateStr[i]);

        // Early exit if invalid date
        if (dateFsm->getState() == DateFsm::STATE_INVALID)
        {
            break;
        }
        i++;
    }
    showOutput(dateFsm->getState() == DateFsm::STATE_DATE, "date");
    delete dateFsm;
}

void runPasswordFsm(string pwd)
{
    auto* pwdFsm = new PasswordFsm();
    int i = 0;

    while (i < pwd.length())
    {
        pwdFsm->set(pwd[i]);

        // Early exit if invalid password
        if (pwdFsm->getState() == PasswordFsm::STATE_INVALID)
        {
            break;
        }
        i++;
    }
    pwdFsm->setFinished();
    showOutput(pwdFsm->getState() == PasswordFsm::STATE_VALID, "password");
    delete pwdFsm;
}

void runBinaryNumberFsm(string str)
{
    auto* binaryFsm = new BinaryNumberFsm();
    int i = 0;

    while (i < str.length())
    {
        binaryFsm->set(str[i]);

        // Early exit if invalid binary number
        if (binaryFsm->getState() == BinaryNumberFsm::STATE_INVALID)
        {
            break;
        }
        i++;
    }
    binaryFsm->setFinished();
    showOutput(binaryFsm->getState() == BinaryNumberFsm::STATE_VALID, "binary number");
    delete binaryFsm;
}

void runHexadecimalNumberFsm(string str)
{
    auto* hexFsm = new HexadecimalNumberFsm();
    int i = 0;

    while (i < str.length())
    {
        hexFsm->set(str[i]);

        // Early exit if invalid binary number
        if (hexFsm->getState() == HexadecimalNumberFsm::STATE_INVALID)
        {
            break;
        }
        i++;
    }
    hexFsm->setFinished();
    showOutput(hexFsm->getState() == HexadecimalNumberFsm::STATE_VALID, "hexadecimal number");
    delete hexFsm;
}
