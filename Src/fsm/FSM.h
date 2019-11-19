/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

class FSM
{
	
	private:
		int state;
		
	protected:
		void setState(int);
		bool digitFSM(char);
		
	public:
		int getState();
		virtual void set(char) = 0;
		virtual void reset() = 0;
	
};
