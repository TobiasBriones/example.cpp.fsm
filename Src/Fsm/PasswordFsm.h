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

#include <cctype>
#include "Fsm.h"

class PasswordFsm : public Fsm
{

private:
    void initValues();

public:
    static const int STATE_INITIAL;
    static const int STATE_S1;
    static const int STATE_S2;
    static const int STATE_S3;
    static const int STATE_INVALID;
    static const int STATE_VALID;

    PasswordFsm();

    void set(char) override;

    void reset() override;

    void setFinished();
};
