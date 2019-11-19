/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <ctype.h>
#include "HexadecimalNumberFSM.h"

const int HexadecimalNumberFSM::STATE_S0 = 0;
const int HexadecimalNumberFSM::STATE_S1 = 1;
const int HexadecimalNumberFSM::STATE_S2 = 2;
const int HexadecimalNumberFSM::STATE_T1 = 3;
const int HexadecimalNumberFSM::STATE_VALID = 4;
const int HexadecimalNumberFSM::STATE_INVALID = 5;

HexadecimalNumberFSM::HexadecimalNumberFSM()
{
	reset();
}

/*
	Returns true iff ch represents an hexadecimal digit 0-F, case insensitive.
*/
bool HexadecimalNumberFSM::isHexDigit(char ch)
{
	return isdigit(ch) || ch == 'a' || ch == 'A'
		|| ch == 'b' || ch == 'B'
		|| ch == 'c' || ch == 'C'
		|| ch == 'd' || ch == 'D'
		|| ch == 'e' || ch == 'E'
		|| ch == 'f' || ch == 'F';
}

void HexadecimalNumberFSM::set(char input)
{
	switch (getState())
	{
	case STATE_S0:
		if (isHexDigit(input))
		{
			if (input == '0')
			{
				setState(STATE_S1);
			}
			else
			{
				setState(STATE_S2);
			}
		}
		else
		{
			setState(STATE_INVALID);
		}
		break;

	case STATE_S1:
		if (isHexDigit(input))
		{
			setState(STATE_S2);
		}
		else
		{
			if (input == 'x')
			{
				setState(STATE_T1);
			}
			else
			{
				setState(STATE_INVALID);
			}
		}
		break;

	case STATE_S2:
		if (!isHexDigit(input))
		{
			setState(STATE_INVALID);
		}
		break;

	case STATE_T1:
		if (isHexDigit(input))
		{
			setState(STATE_S2);
		}
		else
		{
			setState(STATE_INVALID);
		}
	}
}

void HexadecimalNumberFSM::reset()
{
	setState(STATE_S0);
}

void HexadecimalNumberFSM::setFinished()
{
	switch (getState())
	{
	case STATE_S0:
		setState(STATE_INVALID);
		break;

	case STATE_S1:
		setState(STATE_VALID);
		break;

	case STATE_S2:
		setState(STATE_VALID);
		break;

	case STATE_T1:
		setState(STATE_INVALID);
		break;
	}
}
