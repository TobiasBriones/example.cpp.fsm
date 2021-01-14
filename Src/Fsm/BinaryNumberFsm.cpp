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

#include "BinaryNumberFsm.h"

const int BinaryNumberFsm::STATE_S0 = 0;
const int BinaryNumberFsm::STATE_S1 = 1;
const int BinaryNumberFsm::STATE_DOT = 2;
const int BinaryNumberFsm::STATE_S3 = 3;
const int BinaryNumberFsm::STATE_VALID = 4;
const int BinaryNumberFsm::STATE_INVALID = 5;

BinaryNumberFsm::BinaryNumberFsm()
{
    initValues();
}

void BinaryNumberFsm::initValues()
{
    setState(STATE_S0);
}

bool BinaryNumberFsm::isBinaryDigit(char ch)
{
    return ch == 48 || ch == 49;
}

void BinaryNumberFsm::set(char input)
{
    switch (getState())
    {
        case STATE_S0:
            if (isBinaryDigit(input))
            {
                setState(STATE_S1);
            }
            else
            {
                setState(STATE_INVALID);
            }
            break;

        case STATE_S1:
            if (input == '.')
            {
                setState(STATE_DOT);
            }
            else if (!isBinaryDigit(input))
            {
                setState(STATE_INVALID);
            }
            break;

        case STATE_DOT:
            if (isBinaryDigit(input))
            {
                setState(STATE_S3);
            }
            else
            {
                setState(STATE_INVALID);
            }
            break;

        case STATE_S3:
            if (!isBinaryDigit(input))
            {
                setState(STATE_INVALID);
            }
            break;
    }
}

void BinaryNumberFsm::reset()
{
    initValues();
}

void BinaryNumberFsm::setFinished()
{
    switch (getState())
    {
        case STATE_S0:
            setState(STATE_INVALID);
            break;

        case STATE_S1:
            setState(STATE_VALID);
            break;

        case STATE_DOT:
            setState(STATE_INVALID);
            break;

        case STATE_S3:
            setState(STATE_VALID);
            break;
    }
}
