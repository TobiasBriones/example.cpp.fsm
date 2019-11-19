/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once
#include <ctype.h>
#include "FSM.h"

void FSM::setState(int state)
{
	this->state = state;
}

int FSM::getState()
{
	return state;
}

bool FSM::digitFSM(char digit)
{
	return isdigit(digit);
}
