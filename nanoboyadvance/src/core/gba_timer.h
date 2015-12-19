/*
* Copyright (C) 2015 Frederic Meyer
*
* This file is part of nanoboyadvance.
*
* nanoboyadvance is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* nanoboyadvance is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with nanoboyadvance. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "common/types.h"
#include "gba_io.h"

using namespace std;

namespace NanoboyAdvance
{
    class GBATimer
    {
        GBAIO* gba_io;
        static const int timings[4];
        int timer0_ticks {0};
        int timer1_ticks {0};
        int timer2_ticks {0};
        int timer3_ticks {0};
    public:
        ushort timer0_reload {0};
        ushort timer1_reload {0};
        ushort timer2_reload {0};
        ushort timer3_reload {0};
        GBATimer(GBAIO* gba_io);
        void Step();
    };
}
