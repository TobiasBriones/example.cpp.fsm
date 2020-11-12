/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
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
