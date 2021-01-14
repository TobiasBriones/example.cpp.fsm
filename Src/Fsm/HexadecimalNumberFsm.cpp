/*
 * Copyright (c) 2019 Tobias Briones. All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * This file is part of Example Project: FSM.
 *
 * This source code is licensed under the MIT License found in the
 * LICENSE file in the root directory of this source tree or at
 * https://opensource.org/licenses/MIT.
 */

#include "HexadecimalNumberFsm.h"

const int HexadecimalNumberFsm::STATE_S0 = 0;
const int HexadecimalNumberFsm::STATE_S1 = 1;
const int HexadecimalNumberFsm::STATE_S2 = 2;
const int HexadecimalNumberFsm::STATE_T1 = 3;
const int HexadecimalNumberFsm::STATE_VALID = 4;
const int HexadecimalNumberFsm::STATE_INVALID = 5;

HexadecimalNumberFsm::HexadecimalNumberFsm()
{
    initValues();
}

void HexadecimalNumberFsm::initValues()
{
    setState(STATE_S0);
}

bool HexadecimalNumberFsm::isHexDigit(char ch)
{
    return isdigit(ch) || ch == 'a' || ch == 'A'
           || ch == 'b' || ch == 'B'
           || ch == 'c' || ch == 'C'
           || ch == 'd' || ch == 'D'
           || ch == 'e' || ch == 'E'
           || ch == 'f' || ch == 'F';
}

void HexadecimalNumberFsm::set(char input)
{
    switch (getState())
    {
        case STATE_S0:
            if (isHexDigit(input))
            {
                if (input == '0')
                {
                    setState(STATE_S1);
                }
                else
                {
                    setState(STATE_S2);
                }
            }
            else
            {
                setState(STATE_INVALID);
            }
            break;

        case STATE_S1:
            if (isHexDigit(input))
            {
                setState(STATE_S2);
            }
            else
            {
                if (input == 'x')
                {
                    setState(STATE_T1);
                }
                else
                {
                    setState(STATE_INVALID);
                }
            }
            break;

        case STATE_S2:
            if (!isHexDigit(input))
            {
                setState(STATE_INVALID);
            }
            break;

        case STATE_T1:
            if (isHexDigit(input))
            {
                setState(STATE_S2);
            }
            else
            {
                setState(STATE_INVALID);
            }
    }
}

void HexadecimalNumberFsm::reset()
{
    initValues();
}

void HexadecimalNumberFsm::setFinished()
{
    switch (getState())
    {
        case STATE_S0:
        case STATE_S1:
            setState(STATE_INVALID);
            break;

        case STATE_S2:
            setState(STATE_VALID);
            break;

        case STATE_T1:
            setState(STATE_INVALID);
            break;
    }
}
