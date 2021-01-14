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

#include <cctype>

class Fsm
{

private:
    int state;

protected:
    void setState(int);

    static bool digitFsm(char);

public:
    Fsm();

    int getState() const;

    virtual void set(char) = 0;

    virtual void reset() = 0;
};
