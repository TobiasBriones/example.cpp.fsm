/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "Fsm.h"

class DateFsm : public Fsm
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

	DateFsm();

	void set(char);
	void reset();

};
