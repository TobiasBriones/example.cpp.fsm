#include "FSM.h"

class HexadecimalNumberFSM : public FSM
{
	
	private:
		bool isHexDigit(char);
		
	public:
		static const int STATE_S0;
		static const int STATE_S1;
		static const int STATE_S2;
		static const int STATE_T1;
		static const int STATE_VALID;
		static const int STATE_INVALID;
		
		HexadecimalNumberFSM();
		
		void set(char);
		void reset();
		void setFinished();
		
};

