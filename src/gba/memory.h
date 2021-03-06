///////////////////////////////////////////////////////////////////////////////////
//
//  NanoboyAdvance is a modern Game Boy Advance emulator written in C++
//  with performance, platform independency and reasonable accuracy in mind.
//  Copyright (C) 2016 Frederic Meyer
//
//  This file is part of nanoboyadvance.
//
//  nanoboyadvance is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 2 of the License, or
//  (at your option) any later version.
//
//  nanoboyadvance is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with nanoboyadvance. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////////


#ifndef __NBA_MEMORY_H__
#define __NBA_MEMORY_H__


#include <iostream>
#include "util/integer.hpp"
#include "dma.h"
#include "timer.hpp"
#include "interrupt.hpp"
#include "video/video.h"
#include "backup/backup.h"
#include "audio/audio.h"


namespace GBA
{
    enum AccessSize
    {
        ACCESS_BYTE,
        ACCESS_HWORD,
        ACCESS_WORD
    };

    enum HaltState
    {
        HALTSTATE_NONE,
        HALTSTATE_STOP,
        HALTSTATE_HALT
    };

    enum SaveType
    {
        SAVE_NONE,
        SAVE_EEPROM,
        SAVE_SRAM,
        SAVE_FLASH64,
        SAVE_FLASH128
    };

    struct Waitstate
    {
        int sram        {0};
        int first[3]    {0, 0, 0};
        int second[3]   {0, 0, 0};
        bool prefetch   {false};
    };

    class Memory
    {
    private:
        typedef u8   (*ReadFunction) (u32 address);
        typedef void (*WriteFunction)(u32 address, u8 value);

        static u8 ReadBIOS(u32 address);
        static u8 ReadWRAM(u32 address);
        static u8 ReadIRAM(u32 address);
        static u8 ReadIO(u32 address);
        static u8 ReadPAL(u32 address);
        static u8 ReadVRAM(u32 address);
        static u8 ReadOAM(u32 address);
        static u8 ReadROM(u32 address);
        static u8 ReadSave(u32 address);
        static u8 ReadInvalid(u32 address);

        static void WriteWRAM(u32 address, u8 value);
        static void WriteIRAM(u32 address, u8 value);
        static void WriteIO(u32 address, u8 value);
        static void WritePAL(u32 address, u8 value);
        static void WriteVRAM(u32 address, u8 value);
        static void WriteOAM(u32 address, u8 value);
        static void WriteSave(u32 address, u8 value);
        static void WriteInvalid(u32 address, u8 value);

        // Memory Read Byte methods
        static constexpr ReadFunction READ_TABLE[16] = {
            &Memory::ReadBIOS,
            &Memory::ReadInvalid,
            &Memory::ReadWRAM,
            &Memory::ReadIRAM,
            &Memory::ReadIO,
            &Memory::ReadPAL,
            &Memory::ReadVRAM,
            &Memory::ReadOAM,
            &Memory::ReadROM,
            &Memory::ReadROM,
            &Memory::ReadInvalid,
            &Memory::ReadInvalid,
            &Memory::ReadInvalid,
            &Memory::ReadInvalid,
            &Memory::ReadSave,
            &Memory::ReadInvalid
        };

        // Memory Write Byte methods
        static constexpr WriteFunction WRITE_TABLE[16] = {
            &Memory::WriteInvalid,
            &Memory::WriteInvalid,
            &Memory::WriteWRAM,
            &Memory::WriteIRAM,
            &Memory::WriteIO,
            &Memory::WritePAL,
            &Memory::WriteVRAM,
            &Memory::WriteOAM,
            &Memory::WriteInvalid,
            &Memory::WriteInvalid,
            &Memory::WriteInvalid,
            &Memory::WriteInvalid,
            &Memory::WriteInvalid,
            &Memory::WriteInvalid,
            &Memory::WriteSave,
            &Memory::WriteInvalid
        };

        // DMA and Timer constants
        static constexpr int DMA_COUNT_MASK[4]  = { 0x3FFF, 0x3FFF, 0x3FFF, 0xFFFF };
        static constexpr int DMA_DEST_MASK[4]   = { 0x7FFFFFF, 0x7FFFFFF, 0x7FFFFFF, 0xFFFFFFF };
        static constexpr int DMA_SOURCE_MASK[4] = { 0x7FFFFFF, 0xFFFFFFF, 0xFFFFFFF, 0xFFFFFFF };

        // Waitstate constants
        static constexpr int WSN_TABLE[4] = {4, 3, 2, 8};
        static constexpr int WSS0_TABLE[2] = {2, 1};
        static constexpr int WSS1_TABLE[2] = {4, 1};
        static constexpr int WSS2_TABLE[2] = {8, 1};

        // BIOS-stub for HLE-emulation.
        static const u8 HLE_BIOS[0x40];

    public:

        static void Init(std::string rom_file, std::string save_file);
        static void Init(std::string rom_file, std::string save_file, u8* bios, size_t bios_size);
        static void Reset();
        static void Shutdown();

        static void RunDMA();

        static int SequentialAccess(u32 offset, AccessSize size);
        static int NonSequentialAccess(u32 offset, AccessSize size);

        static u8 ReadByte(u32 offset);
        static u16 ReadHWord(u32 offset);
        static u32 ReadWord(u32 offset);
        static void WriteByte(u32 offset, u8 value);
        static void WriteHWord(u32 offset, u16 value);
        static void WriteWord(u32 offset, u32 value);

    private:

        ///////////////////////////////////////////////////////////
        // Class members (Memory)
        //
        ///////////////////////////////////////////////////////////
        static u8* m_regOM;
        static size_t m_regOMSize;
        static u8 m_BIOS[0x4000];
        static u8 m_WRAM[0x40000];
        static u8 m_IRAM[0x8000];
        static Backup* m_Backup;
        static SaveType m_SaveType;

    public:
        ///////////////////////////////////////////////////////////
        // Class members (DMA, Timer, Waitstate, Audio)
        //
        ///////////////////////////////////////////////////////////
        static DMA       m_DMA[4];
        static Timer     m_Timer[4];
        static Waitstate m_Waitstate;

        ///////////////////////////////////////////////////////////
        // Class members (Interrupts)
        //
        ///////////////////////////////////////////////////////////
        static HaltState m_HaltState;
        static bool      m_IntrWait;
        static bool      m_IntrWaitMask;

        ///////////////////////////////////////////////////////////
        // Class members (misc.)
        //
        ///////////////////////////////////////////////////////////
        static Video m_Video;
        static Audio m_Audio;
        static u16 m_KeyInput;
    };
}


#endif  // __NBA_MEMORY_H__
