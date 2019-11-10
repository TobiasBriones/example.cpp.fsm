#include "DateFSM.h"

const int DateFSM::DATE_LENGTH = 10;
const int DateFSM::STATE_YEAR = 0;
const int DateFSM::STATE_MONTH = 1;
const int DateFSM::STATE_DAY = 2;
const int DateFSM::STATE_SLASH = 3;
const int DateFSM::STATE_DATE = 4;
const int DateFSM::STATE_INVALID = 5;

DateFSM::DateFSM() 
{
	reset();
}

void DateFSM::set(char input) 
{
	int state = getState();
	
	// Checking for non-digit states
	if(state == STATE_INVALID)
	{
		return;
	}
	if(state == STATE_DATE)
	{
		setState(STATE_INVALID);
		return;
	}
	if(state == STATE_SLASH)
	{
		if(input != '/')
		{
			setState(STATE_INVALID);
			return;
		}
		switch(i)
		{
			case 4:
				setState(STATE_MONTH);
				break;
				
			case 6:
				setState(STATE_DAY);
				break;
		}
		return;
	}
	
	// Checking for all states depending on digits 0-9
	i++;
	
	if(!digitFSM(input))
	{
		setState(STATE_INVALID);
		return;
	}
	
	// If it's exiting a state then slahs '/' migth be required
	if(i == 4 || i == 6)
	{
		setState(STATE_SLASH);
		return;
	}
	
	switch(state)
	{
		case STATE_DAY:
			if(i >= 8)
			{
				setState(STATE_DATE);
			}
			break;
			
		case STATE_DATE:
			setState(STATE_INVALID);
			break;
	}
}

void DateFSM::reset() 
{
	setState(STATE_YEAR);
	i = 0;
}

