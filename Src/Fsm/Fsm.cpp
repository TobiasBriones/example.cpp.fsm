/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
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
