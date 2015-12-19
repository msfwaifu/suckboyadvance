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

#include <cstring>
#include "common/types.h"
#include "common/log.h"
#include "gba_io.h"

using namespace std;

namespace NanoboyAdvance
{
    class GBAVideo
    {
        enum class GBAVideoState
        {
            Scanline,
            HBlank,
            VBlank
        };
        enum class GBAVideoSpriteShape
        {
            Square = 0,
            Horizontal = 1,
            Vertical = 2,
            Prohibited = 3
        };
        GBAIO* gba_io;
        GBAVideoState state {GBAVideoState::Scanline};
        int ticks {0};
		inline uint DecodeRGB5(ushort color);
		inline uint* DecodeTileLine4BPP(uint block_base, uint palette_base, int number, int line, bool transparent);
		inline uint* DecodeTileLine8PP(uint block_base, int number, int line, bool sprite, bool transparent);
        inline uint* RenderBackgroundMode0(ushort bg_control, int line, int scroll_x, int scroll_y, bool transparent);
        inline uint* RenderSprites(uint tile_base, int line, int priority);
        inline void DrawLineToBuffer(uint* line_buffer, int line);
		void Render(int line);
    public:
        bool render_scanline {false};
        ubyte pal[0x400];
        ubyte vram[0x18000];
        ubyte obj[0x400];
		uint buffer[240 * 160];
        GBAVideo(GBAIO* gba_io);
        void Step();
    };
}
