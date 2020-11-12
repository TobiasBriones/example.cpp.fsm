/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <cctype>
#include "Fsm.h"

class HexadecimalNumberFsm : public Fsm
{

private:
    void initValues();
    static bool isHexDigit(char);

public:
    static const int STATE_S0;
    static const int STATE_S1;
    static const int STATE_S2;
    static const int STATE_T1;
    static const int STATE_VALID;
    static const int STATE_INVALID;

    HexadecimalNumberFsm();

    void set(char) override;

    void reset() override;

    void setFinished();
};
