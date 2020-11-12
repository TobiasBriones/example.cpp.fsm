/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <ctype.h>
#include "PasswordFsm.h"

const int PasswordFsm::STATE_INITIAL = 0;
const int PasswordFsm::STATE_S1 = 1;
const int PasswordFsm::STATE_S2 = 2;
const int PasswordFsm::STATE_S3 = 3;
const int PasswordFsm::STATE_INVALID = 4;
const int PasswordFsm::STATE_VALID = 5;

PasswordFsm::PasswordFsm()
{
    reset();
}

void PasswordFsm::set(char input)
{
    switch (getState())
    {
        case STATE_INITIAL:
            if (isdigit(input))
            {
                setState(STATE_S1);
            }
            else
            {
                setState(STATE_INVALID);
            }
            break;

        case STATE_S1:
            if (input == toupper(input))
            {
                setState(STATE_S2);
            }
            else
            {
                setState(STATE_INVALID);
            }
            break;

        case STATE_S2:
            if (input == '#' || input == '*')
            {
                setState(STATE_S3);
            }
            else if (input != toupper(input))
            {
                setState(STATE_INVALID);
            }
            break;

        case STATE_S3:
            setState(STATE_INVALID);
            break;
    }
}

void PasswordFsm::reset()
{
    setState(STATE_INITIAL);
}

void PasswordFsm::setFinished()
{
    if (getState() == STATE_S3)
    {
        setState(STATE_VALID);
    }
    else
    {
        setState(STATE_INVALID);
    }
}
