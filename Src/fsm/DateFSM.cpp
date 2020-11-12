/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "DateFsm.h"

const int DateFsm::DATE_LENGTH = 10;
const int DateFsm::STATE_YEAR = 0;
const int DateFsm::STATE_MONTH = 1;
const int DateFsm::STATE_DAY = 2;
const int DateFsm::STATE_SLASH = 3;
const int DateFsm::STATE_DATE = 4;
const int DateFsm::STATE_INVALID = 5;

DateFsm::DateFsm()
{
    reset();
}

void DateFsm::set(char input)
{
    int state = getState();

    // Checking for non-digit states
    if (state == STATE_INVALID)
    {
        return;
    }
    if (state == STATE_DATE)
    {
        setState(STATE_INVALID);
        return;
    }
    if (state == STATE_SLASH)
    {
        if (input != '/')
        {
            setState(STATE_INVALID);
            return;
        }
        switch (i)
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

    if (!digitFsm(input))
    {
        setState(STATE_INVALID);
        return;
    }

    // If it's exiting a state then slahs '/' migth be required
    if (i == 4 || i == 6)
    {
        setState(STATE_SLASH);
        return;
    }

    switch (state)
    {
        case STATE_DAY:
            if (i >= 8)
            {
                setState(STATE_DATE);
            }
            break;

        case STATE_DATE:
            setState(STATE_INVALID);
            break;
    }
}

void DateFsm::reset()
{
    setState(STATE_YEAR);
    i = 0;
}
