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

