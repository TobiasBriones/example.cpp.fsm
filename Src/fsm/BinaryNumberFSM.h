/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "FSM.h"

class BinaryNumberFSM : public FSM
{
	
	private:
		bool isBinaryDigit(char);
		
	public:
		static const int STATE_S0;
		static const int STATE_S1;
		static const int STATE_DOT;
		static const int STATE_S3;
		static const int STATE_VALID;
		static const int STATE_INVALID;
		
		BinaryNumberFSM();
		
		void set(char);
		void reset();
		void setFinished();
		
};
