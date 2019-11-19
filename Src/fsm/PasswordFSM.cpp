/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <ctype.h>
#include "PasswordFSM.h"

const int PasswordFSM::STATE_INITIAL = 0;
const int PasswordFSM::STATE_S1 = 1;
const int PasswordFSM::STATE_S2 = 2;
const int PasswordFSM::STATE_S3 = 3;
const int PasswordFSM::STATE_INVALID = 4;
const int PasswordFSM::STATE_VALID = 5;

PasswordFSM::PasswordFSM()
{
	reset();
}

void PasswordFSM::set(char input)
{
	switch (getState())
	{
	case STATE_INITIAL:
		if (isdigit(input))
		{
			setState(STATE_S1);
		}
		else
		{
			setState(STATE_INVALID);
		}
		break;

	case STATE_S1:
		if (input == toupper(input))
		{
			setState(STATE_S2);
		}
		else
		{
			setState(STATE_INVALID);
		}
		break;

	case STATE_S2:
		if (input == '#' || input == '*')
		{
			setState(STATE_S3);
		}
		else if (input != toupper(input))
		{
			setState(STATE_INVALID);
		}
		break;

	case STATE_S3:
		setState(STATE_INVALID);
		break;
	}
}

void PasswordFSM::reset()
{
	setState(STATE_INITIAL);
}

void PasswordFSM::setFinished()
{
	if (getState() == STATE_S3)
	{
		setState(STATE_VALID);
	}
	else
	{
		setState(STATE_INVALID);
	}
}
