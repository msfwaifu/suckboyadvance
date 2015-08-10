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

#include "arm7.h"

#define THUMB_1 1
#define THUMB_2 2
#define THUMB_3 3
#define THUMB_4 4
#define THUMB_5 5
#define THUMB_6 6
#define THUMB_7 7
#define THUMB_8 8
#define THUMB_9 9
#define THUMB_10 10
#define THUMB_11 11
#define THUMB_12 12
#define THUMB_13 13
#define THUMB_14 14
#define THUMB_15 15
#define THUMB_16 16
#define THUMB_17 17
#define THUMB_18 18
#define THUMB_19 19

namespace NanoboyAdvance
{
    int ARM7::THUMBDecode(ushort instruction)
    {
        if ((instruction & 0xF800) < 0x1800)
        {
            // THUMB.1 Move shifted register
            return THUMB_1;
        }
        else if ((instruction & 0xF800) == 0x1800)
        {
            // THUMB.2 Add/subtract
            return THUMB_2;
        }
        else if ((instruction & 0xE000) == 0x2000)
        {
            // THUMB.3 Move/compare/add/subtract immediate
            return THUMB_3;
        }
        else if ((instruction & 0xFC00) == 0x4000)
        {
            // THUMB.4 ALU operations
            return THUMB_4;
        }
        else if ((instruction & 0xFC00) == 0x4400)
        {
            // THUMB.5 Hi register operations/branch exchange
            return THUMB_5;
        }
        else if ((instruction & 0xF800) == 0x4800)
        {
            // THUMB.6 PC-relative load
            return THUMB_6;
        }
        else if ((instruction & 0xF200) == 0x5000)
        {
            // THUMB.7 Load/store with register offset
            return THUMB_7;
        }
        else if ((instruction & 0xF200) == 0x5200)
        {
            // THUMB.8 Load/store sign-extended byte/halfword
            return THUMB_8;
        }
        else if ((instruction & 0xE000) == 0x6000)
        {
            // THUMB.9 Load store with immediate offset
            return THUMB_9;
        }
        else if ((instruction & 0xF000) == 0x8000)
        {
            // THUMB.10 Load/store halfword
            return THUMB_10;
        }
        else if ((instruction & 0xF000) == 0x9000)
        {
            // THUMB.11 SP-relative load/store
            return THUMB_11;
        }
        else if ((instruction & 0xF000) == 0xA000)
        {
            // THUMB.12 Load address
            return THUMB_12;
        }
        else if ((instruction & 0xFF00) == 0xB000)
        {
            // THUMB.13 Add offset to stack pointer
            return THUMB_13;
        }
        else if ((instruction & 0xF600) == 0xB400)
        {
            // THUMB.14 push/pop registers
            return THUMB_14;
        }
        else if ((instruction & 0xF000) == 0xC000)
        {
            // THUMB.15 Multiple load/store
            return THUMB_15;
        }
        else if ((instruction & 0xF000) == 0xD000)
        {
            // THUMB.16 Conditional Branch
            return THUMB_16;
        }
        else if ((instruction & 0xFF00) == 0xDF00)
        {
            // THUMB.17 Software Interrupt
            return THUMB_17;
        }
        else if ((instruction & 0xF800) == 0xE000)
        {
            // THUMB.18 Unconditional Branch
            return THUMB_18;
        }
        else if ((instruction & 0xF000) == 0xF000)
        {
            // THUMB.19 Long branch with link
            return THUMB_19;
        }
        return 0;
    }

    void ARM7::THUMBExecute(ushort instruction, int type)
    {
        switch (type)
        {
        case THUMB_1:
        {
            // THUMB.1 Move shifted register
            int reg_dest = instruction & 7;
            int reg_source = (instruction >> 3) & 7;
            uint immediate_value = (instruction >> 6) & 0x1F;
            if (immediate_value != 0)
            {
                switch ((instruction >> 11) & 3)
                {
                case 0b00: // LSL
                    assert_carry((reg(reg_source) << (immediate_value - 1)) & 0x80000000);
                    reg(reg_dest) = reg(reg_source) << immediate_value;
                    break;
                case 0b01: // LSR
                    assert_carry((reg(reg_source) >> (immediate_value - 1)) & 1);
                    reg(reg_dest) = reg(reg_source) >> immediate_value;
                    break;
                case 0b10: // ASR
                {
                    sint result = (sint)reg(reg_source) >> (sint)immediate_value;
                    assert_carry((reg(reg_source) >> (immediate_value - 1)) & 1);
                    reg(reg_dest) = (uint)result;
                    break;
                }
                }
            }
            else
            {
                reg(reg_dest) = reg(reg_source);
            }
            calculate_sign(reg(reg_dest));
            calculate_zero(reg(reg_dest));
            break;
        }
        case THUMB_2:
        {
            // THUMB.2 Add/subtract
            int reg_dest = instruction & 7;
            int reg_source = (instruction >> 3) & 7;
            uint operand;

            // The operand can either be the value of a register or a 3 bit immediate value
            if (instruction & (1 << 10))
            {
                operand = (instruction >> 6) & 7;
            }
            else
            {
                operand = reg((instruction >> 6) & 7);
            }

            // Determine wether to subtract or add
            if (instruction & (1 << 9))
            {
                uint result = reg(reg_source) - operand;
                assert_carry(reg(reg_source) >= operand);
                calculate_overflow_sub(result, reg(reg_source), operand);
                calculate_sign(result);
                calculate_zero(result);
                reg(reg_dest) = result;
            }
            else
            {
                uint result = reg(reg_source) + operand;
                ulong result_long = (ulong)(reg(reg_source)) + (ulong)operand;
                assert_carry(result_long & 0x100000000);
                calculate_overflow_add(result, reg(reg_source), operand);
                calculate_sign(result);
                calculate_zero(result);
                reg(reg_dest) = result;
            }
            break;
        }
        case THUMB_3:
        {
            // THUMB.3 Move/compare/add/subtract immediate
            uint immediate_value = instruction & 0xFF;
            int reg_dest = (instruction >> 8) & 7;
            switch ((instruction >> 11) & 3)
            {
            case 0b00: // MOV
                calculate_sign(0);
                calculate_zero(immediate_value);
                reg(reg_dest) = immediate_value;
                break;
            case 0b01: // CMP
                uint result = reg(reg_dest) - immediate_value;
                assert_carry(reg(reg_dest) >= immediate_value);
                calculate_overflow_sub(result, reg(reg_dest), immediate_value);
                calculate_sign(result);
                calculate_zero(result);
                break;
            case 0b10: // ADD
                uint result = reg(reg_dest) + immediate_value;
                ulong result_long = (ulong)(reg(reg_dest)) + (ulong)immediate_value;
                assert_carry(result_long & 0x100000000);
                calculate_overflow_add(result, reg(reg_dest), immediate_value);
                calculate_sign(result);
                calculate_zero(result);
                reg(reg_dest) = result;
                break;
            case 0b11: // SUB
                uint result = reg(reg_dest) - immediate_value;
                assert_carry(reg(reg_dest) >= immediate_value);
                calculate_overflow_sub(result, reg(reg_dest), immediate_value);
                calculate_sign(result);
                calculate_zero(result);
                reg(reg_dest) = result;
                break;
            }
            break;
        }
        }
    }
}