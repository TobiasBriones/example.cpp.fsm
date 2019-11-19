/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "BinaryNumberFSM.h"

const int BinaryNumberFSM::STATE_S0 = 0;
const int BinaryNumberFSM::STATE_S1 = 1;
const int BinaryNumberFSM::STATE_DOT = 2;
const int BinaryNumberFSM::STATE_S3 = 3;
const int BinaryNumberFSM::STATE_VALID = 4;
const int BinaryNumberFSM::STATE_INVALID = 5;

BinaryNumberFSM::BinaryNumberFSM()
{
	reset();
}

/*
	Returns true iff ch represents either the number 0 or 1.
*/
bool BinaryNumberFSM::isBinaryDigit(char ch)
{
	return ch == 48 || ch == 49;
}

void BinaryNumberFSM::set(char input)
{
	switch (getState())
	{
	case STATE_S0:
		if (isBinaryDigit(input))
		{
			setState(STATE_S1);
		}
		else
		{
			setState(STATE_INVALID);
		}
		break;

	case STATE_S1:
		if (input == '.')
		{
			setState(STATE_DOT);
		}
		else if (!isBinaryDigit(input))
		{
			setState(STATE_INVALID);
		}
		break;

	case STATE_DOT:
		if (isBinaryDigit(input))
		{
			setState(STATE_S3);
		}
		else
		{
			setState(STATE_INVALID);
		}
		break;

	case STATE_S3:
		if (!isBinaryDigit(input))
		{
			setState(STATE_INVALID);
		}
		break;
	}
}

void BinaryNumberFSM::reset()
{
	setState(STATE_S0);
}

void BinaryNumberFSM::setFinished()
{
	switch (getState())
	{
	case STATE_S0:
		setState(STATE_INVALID);
		break;

	case STATE_S1:
		setState(STATE_VALID);
		break;

	case STATE_DOT:
		setState(STATE_INVALID);
		break;

	case STATE_S3:
		setState(STATE_VALID);
		break;
	}
}
