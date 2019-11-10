#include "FSM.h"

class PasswordFSM : public FSM
{
	
	public:
		static const int STATE_INITIAL;
		static const int STATE_S1;
		static const int STATE_S2;
		static const int STATE_S3;
		static const int STATE_INVALID;
		static const int STATE_VALID;
		
		PasswordFSM();
		
		void set(char input);
		void reset();
		void setFinished();
		
};

