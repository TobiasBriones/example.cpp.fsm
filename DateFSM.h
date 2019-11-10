#include "FSM.h"

class DateFSM : public FSM
{
	
	private:
		int i;
		
	public:
		
		// A state represents the next expected character
		static const int DATE_LENGTH;
		static const int STATE_YEAR;
		static const int STATE_MONTH;
		static const int STATE_DAY;
		static const int STATE_SLASH;
		static const int STATE_DATE;
		static const int STATE_INVALID;
		
		DateFSM();
		
		void set(char input);
		void reset();
		
};

