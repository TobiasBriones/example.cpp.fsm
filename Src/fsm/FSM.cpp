/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once
#include <ctype.h>
#include "Fsm.h"

void Fsm::setState(int state)
{
	this->state = state;
}

int Fsm::getState()
{
	return state;
}

bool Fsm::digitFsm(char digit)
{
	return isdigit(digit);
}
