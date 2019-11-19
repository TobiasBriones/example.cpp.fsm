/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

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

	void set(char);
	void reset();
	void setFinished();

};
