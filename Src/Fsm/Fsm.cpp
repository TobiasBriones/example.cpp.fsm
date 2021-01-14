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

#pragma once

#include "Fsm.h"

Fsm::Fsm()
{
    this->state = 0;
}

void Fsm::setState(int value)
{
    this->state = value;
}

int Fsm::getState() const
{
    return state;
}

bool Fsm::digitFsm(char digit)
{
    return isdigit(digit);
}
