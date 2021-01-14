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

#include "Fsm.h"

class DateFsm : public Fsm
{

private:
    int i{};

    void initValues();

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

    void set(char) override;

    void reset() override;
};
