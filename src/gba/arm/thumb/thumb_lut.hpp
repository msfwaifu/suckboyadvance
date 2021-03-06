///////////////////////////////////////////////////////////////////////////////////
//
//  NanoboyAdvance is a modern Game Boy Advance emulator written in C++
//  with performance, platform independency and reasonable accuracy in mind.
//  Copyright (C) 2017 Frederic Meyer
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

#ifdef ARMIGO_INCLUDE

const arm::thumb_instruction arm::thumb_lut[1024] =
{
    /* THUMB.1 Move shifted register */
    &arm::thumb_1<0,0>,  &arm::thumb_1<1,0>,  &arm::thumb_1<2,0>,  &arm::thumb_1<3,0>,
    &arm::thumb_1<4,0>,  &arm::thumb_1<5,0>,  &arm::thumb_1<6,0>,  &arm::thumb_1<7,0>,
    &arm::thumb_1<8,0>,  &arm::thumb_1<9,0>,  &arm::thumb_1<10,0>, &arm::thumb_1<11,0>,
    &arm::thumb_1<12,0>, &arm::thumb_1<13,0>, &arm::thumb_1<14,0>, &arm::thumb_1<15,0>,
    &arm::thumb_1<16,0>, &arm::thumb_1<17,0>, &arm::thumb_1<18,0>, &arm::thumb_1<19,0>,
    &arm::thumb_1<20,0>, &arm::thumb_1<21,0>, &arm::thumb_1<22,0>, &arm::thumb_1<23,0>,
    &arm::thumb_1<24,0>, &arm::thumb_1<25,0>, &arm::thumb_1<26,0>, &arm::thumb_1<27,0>,
    &arm::thumb_1<28,0>, &arm::thumb_1<29,0>, &arm::thumb_1<30,0>, &arm::thumb_1<31,0>,
    &arm::thumb_1<0,1>,  &arm::thumb_1<1,1>,  &arm::thumb_1<2,1>,  &arm::thumb_1<3,1>,
    &arm::thumb_1<4,1>,  &arm::thumb_1<5,1>,  &arm::thumb_1<6,1>,  &arm::thumb_1<7,1>,
    &arm::thumb_1<8,1>,  &arm::thumb_1<9,1>,  &arm::thumb_1<10,1>, &arm::thumb_1<11,1>,
    &arm::thumb_1<12,1>, &arm::thumb_1<13,1>, &arm::thumb_1<14,1>, &arm::thumb_1<15,1>,
    &arm::thumb_1<16,1>, &arm::thumb_1<17,1>, &arm::thumb_1<18,1>, &arm::thumb_1<19,1>,
    &arm::thumb_1<20,1>, &arm::thumb_1<21,1>, &arm::thumb_1<22,1>, &arm::thumb_1<23,1>,
    &arm::thumb_1<24,1>, &arm::thumb_1<25,1>, &arm::thumb_1<26,1>, &arm::thumb_1<27,1>,
    &arm::thumb_1<28,1>, &arm::thumb_1<29,1>, &arm::thumb_1<30,1>, &arm::thumb_1<31,1>,
    &arm::thumb_1<0,2>,  &arm::thumb_1<1,2>,  &arm::thumb_1<2,2>,  &arm::thumb_1<3,2>,
    &arm::thumb_1<4,2>,  &arm::thumb_1<5,2>,  &arm::thumb_1<6,2>,  &arm::thumb_1<7,2>,
    &arm::thumb_1<8,2>,  &arm::thumb_1<9,2>,  &arm::thumb_1<10,2>, &arm::thumb_1<11,2>,
    &arm::thumb_1<12,2>, &arm::thumb_1<13,2>, &arm::thumb_1<14,2>, &arm::thumb_1<15,2>,
    &arm::thumb_1<16,2>, &arm::thumb_1<17,2>, &arm::thumb_1<18,2>, &arm::thumb_1<19,2>,
    &arm::thumb_1<20,2>, &arm::thumb_1<21,2>, &arm::thumb_1<22,2>, &arm::thumb_1<23,2>,
    &arm::thumb_1<24,2>, &arm::thumb_1<25,2>, &arm::thumb_1<26,2>, &arm::thumb_1<27,2>,
    &arm::thumb_1<28,2>, &arm::thumb_1<29,2>, &arm::thumb_1<30,2>, &arm::thumb_1<31,2>,

    /* THUMB.2 Add / subtract */
    &arm::thumb_2<0,0,0>, &arm::thumb_2<0,0,1>, &arm::thumb_2<0,0,2>, &arm::thumb_2<0,0,3>,
    &arm::thumb_2<0,0,4>, &arm::thumb_2<0,0,5>, &arm::thumb_2<0,0,6>, &arm::thumb_2<0,0,7>,
    &arm::thumb_2<0,1,0>, &arm::thumb_2<0,1,1>, &arm::thumb_2<0,1,2>, &arm::thumb_2<0,1,3>,
    &arm::thumb_2<0,1,4>, &arm::thumb_2<0,1,5>, &arm::thumb_2<0,1,6>, &arm::thumb_2<0,1,7>,
    &arm::thumb_2<1,0,0>, &arm::thumb_2<1,0,1>, &arm::thumb_2<1,0,2>, &arm::thumb_2<1,0,3>,
    &arm::thumb_2<1,0,4>, &arm::thumb_2<1,0,5>, &arm::thumb_2<1,0,6>, &arm::thumb_2<1,0,7>,
    &arm::thumb_2<1,1,0>, &arm::thumb_2<1,1,1>, &arm::thumb_2<1,1,2>, &arm::thumb_2<1,1,3>,
    &arm::thumb_2<1,1,4>, &arm::thumb_2<1,1,5>, &arm::thumb_2<1,1,6>, &arm::thumb_2<1,1,7>,

    /* THUMB.3 Move/compare/add/subtract immediate */
    &arm::thumb_3<0,0>, &arm::thumb_3<0,0>, &arm::thumb_3<0,0>, &arm::thumb_3<0,0>,
    &arm::thumb_3<0,1>, &arm::thumb_3<0,1>, &arm::thumb_3<0,1>, &arm::thumb_3<0,1>,
    &arm::thumb_3<0,2>, &arm::thumb_3<0,2>, &arm::thumb_3<0,2>, &arm::thumb_3<0,2>,
    &arm::thumb_3<0,3>, &arm::thumb_3<0,3>, &arm::thumb_3<0,3>, &arm::thumb_3<0,3>,
    &arm::thumb_3<0,4>, &arm::thumb_3<0,4>, &arm::thumb_3<0,4>, &arm::thumb_3<0,4>,
    &arm::thumb_3<0,5>, &arm::thumb_3<0,5>, &arm::thumb_3<0,5>, &arm::thumb_3<0,5>,
    &arm::thumb_3<0,6>, &arm::thumb_3<0,6>, &arm::thumb_3<0,6>, &arm::thumb_3<0,6>,
    &arm::thumb_3<0,7>, &arm::thumb_3<0,7>, &arm::thumb_3<0,7>, &arm::thumb_3<0,7>,
    &arm::thumb_3<1,0>, &arm::thumb_3<1,0>, &arm::thumb_3<1,0>, &arm::thumb_3<1,0>,
    &arm::thumb_3<1,1>, &arm::thumb_3<1,1>, &arm::thumb_3<1,1>, &arm::thumb_3<1,1>,
    &arm::thumb_3<1,2>, &arm::thumb_3<1,2>, &arm::thumb_3<1,2>, &arm::thumb_3<1,2>,
    &arm::thumb_3<1,3>, &arm::thumb_3<1,3>, &arm::thumb_3<1,3>, &arm::thumb_3<1,3>,
    &arm::thumb_3<1,4>, &arm::thumb_3<1,4>, &arm::thumb_3<1,4>, &arm::thumb_3<1,4>,
    &arm::thumb_3<1,5>, &arm::thumb_3<1,5>, &arm::thumb_3<1,5>, &arm::thumb_3<1,5>,
    &arm::thumb_3<1,6>, &arm::thumb_3<1,6>, &arm::thumb_3<1,6>, &arm::thumb_3<1,6>,
    &arm::thumb_3<1,7>, &arm::thumb_3<1,7>, &arm::thumb_3<1,7>, &arm::thumb_3<1,7>,
    &arm::thumb_3<2,0>, &arm::thumb_3<2,0>, &arm::thumb_3<2,0>, &arm::thumb_3<2,0>,
    &arm::thumb_3<2,1>, &arm::thumb_3<2,1>, &arm::thumb_3<2,1>, &arm::thumb_3<2,1>,
    &arm::thumb_3<2,2>, &arm::thumb_3<2,2>, &arm::thumb_3<2,2>, &arm::thumb_3<2,2>,
    &arm::thumb_3<2,3>, &arm::thumb_3<2,3>, &arm::thumb_3<2,3>, &arm::thumb_3<2,3>,
    &arm::thumb_3<2,4>, &arm::thumb_3<2,4>, &arm::thumb_3<2,4>, &arm::thumb_3<2,4>,
    &arm::thumb_3<2,5>, &arm::thumb_3<2,5>, &arm::thumb_3<2,5>, &arm::thumb_3<2,5>,
    &arm::thumb_3<2,6>, &arm::thumb_3<2,6>, &arm::thumb_3<2,6>, &arm::thumb_3<2,6>,
    &arm::thumb_3<2,7>, &arm::thumb_3<2,7>, &arm::thumb_3<2,7>, &arm::thumb_3<2,7>,
    &arm::thumb_3<3,0>, &arm::thumb_3<3,0>, &arm::thumb_3<3,0>, &arm::thumb_3<3,0>,
    &arm::thumb_3<3,1>, &arm::thumb_3<3,1>, &arm::thumb_3<3,1>, &arm::thumb_3<3,1>,
    &arm::thumb_3<3,2>, &arm::thumb_3<3,2>, &arm::thumb_3<3,2>, &arm::thumb_3<3,2>,
    &arm::thumb_3<3,3>, &arm::thumb_3<3,3>, &arm::thumb_3<3,3>, &arm::thumb_3<3,3>,
    &arm::thumb_3<3,4>, &arm::thumb_3<3,4>, &arm::thumb_3<3,4>, &arm::thumb_3<3,4>,
    &arm::thumb_3<3,5>, &arm::thumb_3<3,5>, &arm::thumb_3<3,5>, &arm::thumb_3<3,5>,
    &arm::thumb_3<3,6>, &arm::thumb_3<3,6>, &arm::thumb_3<3,6>, &arm::thumb_3<3,6>,
    &arm::thumb_3<3,7>, &arm::thumb_3<3,7>, &arm::thumb_3<3,7>, &arm::thumb_3<3,7>,

    /* THUMB.4 ALU operations */
    &arm::thumb_4<0>,  &arm::thumb_4<1>,  &arm::thumb_4<2>,  &arm::thumb_4<3>,
    &arm::thumb_4<4>,  &arm::thumb_4<5>,  &arm::thumb_4<6>,  &arm::thumb_4<7>,
    &arm::thumb_4<8>,  &arm::thumb_4<9>,  &arm::thumb_4<10>, &arm::thumb_4<11>,
    &arm::thumb_4<12>, &arm::thumb_4<13>, &arm::thumb_4<14>, &arm::thumb_4<15>,

    /* THUMB.5 High register operations/branch exchange
     * TODO: Eventually move BX into it's own method. */
    &arm::thumb_5<0,0,0>, &arm::thumb_5<0,0,1>, &arm::thumb_5<0,1,0>, &arm::thumb_5<0,1,1>,
    &arm::thumb_5<1,0,0>, &arm::thumb_5<1,0,1>, &arm::thumb_5<1,1,0>, &arm::thumb_5<1,1,1>,
    &arm::thumb_5<2,0,0>, &arm::thumb_5<2,0,1>, &arm::thumb_5<2,1,0>, &arm::thumb_5<2,1,1>,
    &arm::thumb_5<3,0,0>, &arm::thumb_5<3,0,1>, &arm::thumb_5<3,1,0>, &arm::thumb_5<3,1,1>,

    /* THUMB.6 PC-relative load */
    &arm::thumb_6<0>, &arm::thumb_6<0>, &arm::thumb_6<0>, &arm::thumb_6<0>,
    &arm::thumb_6<1>, &arm::thumb_6<1>, &arm::thumb_6<1>, &arm::thumb_6<1>,
    &arm::thumb_6<2>, &arm::thumb_6<2>, &arm::thumb_6<2>, &arm::thumb_6<2>,
    &arm::thumb_6<3>, &arm::thumb_6<3>, &arm::thumb_6<3>, &arm::thumb_6<3>,
    &arm::thumb_6<4>, &arm::thumb_6<4>, &arm::thumb_6<4>, &arm::thumb_6<4>,
    &arm::thumb_6<5>, &arm::thumb_6<5>, &arm::thumb_6<5>, &arm::thumb_6<5>,
    &arm::thumb_6<6>, &arm::thumb_6<6>, &arm::thumb_6<6>, &arm::thumb_6<6>,
    &arm::thumb_6<7>, &arm::thumb_6<7>, &arm::thumb_6<7>, &arm::thumb_6<7>,

    /* THUMB.7 Load/store with register offset,
       THUMB.8 Load/store sign-extended byte/halfword */
    &arm::thumb_7<0,0>, &arm::thumb_7<0,1>, &arm::thumb_7<0,2>, &arm::thumb_7<0,3>,
    &arm::thumb_7<0,4>, &arm::thumb_7<0,5>, &arm::thumb_7<0,6>, &arm::thumb_7<0,7>,
    &arm::thumb_8<0,0>, &arm::thumb_8<0,1>, &arm::thumb_8<0,2>, &arm::thumb_8<0,3>,
    &arm::thumb_8<0,4>, &arm::thumb_8<0,5>, &arm::thumb_8<0,6>, &arm::thumb_8<0,7>,
    &arm::thumb_7<1,0>, &arm::thumb_7<1,1>, &arm::thumb_7<1,2>, &arm::thumb_7<1,3>,
    &arm::thumb_7<1,4>, &arm::thumb_7<1,5>, &arm::thumb_7<1,6>, &arm::thumb_7<1,7>,
    &arm::thumb_8<1,0>, &arm::thumb_8<1,1>, &arm::thumb_8<1,2>, &arm::thumb_8<1,3>,
    &arm::thumb_8<1,4>, &arm::thumb_8<1,5>, &arm::thumb_8<1,6>, &arm::thumb_8<1,7>,
    &arm::thumb_7<2,0>, &arm::thumb_7<2,1>, &arm::thumb_7<2,2>, &arm::thumb_7<2,3>,
    &arm::thumb_7<2,4>, &arm::thumb_7<2,5>, &arm::thumb_7<2,6>, &arm::thumb_7<2,7>,
    &arm::thumb_8<2,0>, &arm::thumb_8<2,1>, &arm::thumb_8<2,2>, &arm::thumb_8<2,3>,
    &arm::thumb_8<2,4>, &arm::thumb_8<2,5>, &arm::thumb_8<2,6>, &arm::thumb_8<2,7>,
    &arm::thumb_7<3,0>, &arm::thumb_7<3,1>, &arm::thumb_7<3,2>, &arm::thumb_7<3,3>,
    &arm::thumb_7<3,4>, &arm::thumb_7<3,5>, &arm::thumb_7<3,6>, &arm::thumb_7<3,7>,
    &arm::thumb_8<3,0>, &arm::thumb_8<3,1>, &arm::thumb_8<3,2>, &arm::thumb_8<3,3>,
    &arm::thumb_8<3,4>, &arm::thumb_8<3,5>, &arm::thumb_8<3,6>, &arm::thumb_8<3,7>,

    /* THUMB.9 Load/store with immediate offset */
    &arm::thumb_9<0,0>,  &arm::thumb_9<0,1>,  &arm::thumb_9<0,2>,  &arm::thumb_9<0,3>,
    &arm::thumb_9<0,4>,  &arm::thumb_9<0,5>,  &arm::thumb_9<0,6>,  &arm::thumb_9<0,7>,
    &arm::thumb_9<0,8>,  &arm::thumb_9<0,9>,  &arm::thumb_9<0,10>, &arm::thumb_9<0,11>,
    &arm::thumb_9<0,12>, &arm::thumb_9<0,13>, &arm::thumb_9<0,14>, &arm::thumb_9<0,15>,
    &arm::thumb_9<0,16>, &arm::thumb_9<0,17>, &arm::thumb_9<0,18>, &arm::thumb_9<0,19>,
    &arm::thumb_9<0,20>, &arm::thumb_9<0,21>, &arm::thumb_9<0,22>, &arm::thumb_9<0,23>,
    &arm::thumb_9<0,24>, &arm::thumb_9<0,25>, &arm::thumb_9<0,26>, &arm::thumb_9<0,27>,
    &arm::thumb_9<0,28>, &arm::thumb_9<0,29>, &arm::thumb_9<0,30>, &arm::thumb_9<0,31>,
    &arm::thumb_9<1,0>,  &arm::thumb_9<1,1>,  &arm::thumb_9<1,2>,  &arm::thumb_9<1,3>,
    &arm::thumb_9<1,4>,  &arm::thumb_9<1,5>,  &arm::thumb_9<1,6>,  &arm::thumb_9<1,7>,
    &arm::thumb_9<1,8>,  &arm::thumb_9<1,9>,  &arm::thumb_9<1,10>, &arm::thumb_9<1,11>,
    &arm::thumb_9<1,12>, &arm::thumb_9<1,13>, &arm::thumb_9<1,14>, &arm::thumb_9<1,15>,
    &arm::thumb_9<1,16>, &arm::thumb_9<1,17>, &arm::thumb_9<1,18>, &arm::thumb_9<1,19>,
    &arm::thumb_9<1,20>, &arm::thumb_9<1,21>, &arm::thumb_9<1,22>, &arm::thumb_9<1,23>,
    &arm::thumb_9<1,24>, &arm::thumb_9<1,25>, &arm::thumb_9<1,26>, &arm::thumb_9<1,27>,
    &arm::thumb_9<1,28>, &arm::thumb_9<1,29>, &arm::thumb_9<1,30>, &arm::thumb_9<1,31>,
    &arm::thumb_9<2,0>,  &arm::thumb_9<2,1>,  &arm::thumb_9<2,2>,  &arm::thumb_9<2,3>,
    &arm::thumb_9<2,4>,  &arm::thumb_9<2,5>,  &arm::thumb_9<2,6>,  &arm::thumb_9<2,7>,
    &arm::thumb_9<2,8>,  &arm::thumb_9<2,9>,  &arm::thumb_9<2,10>, &arm::thumb_9<2,11>,
    &arm::thumb_9<2,12>, &arm::thumb_9<2,13>, &arm::thumb_9<2,14>, &arm::thumb_9<2,15>,
    &arm::thumb_9<2,16>, &arm::thumb_9<2,17>, &arm::thumb_9<2,18>, &arm::thumb_9<2,19>,
    &arm::thumb_9<2,20>, &arm::thumb_9<2,21>, &arm::thumb_9<2,22>, &arm::thumb_9<2,23>,
    &arm::thumb_9<2,24>, &arm::thumb_9<2,25>, &arm::thumb_9<2,26>, &arm::thumb_9<2,27>,
    &arm::thumb_9<2,28>, &arm::thumb_9<2,29>, &arm::thumb_9<2,30>, &arm::thumb_9<2,31>,
    &arm::thumb_9<3,0>,  &arm::thumb_9<3,1>,  &arm::thumb_9<3,2>,  &arm::thumb_9<3,3>,
    &arm::thumb_9<3,4>,  &arm::thumb_9<3,5>,  &arm::thumb_9<3,6>,  &arm::thumb_9<3,7>,
    &arm::thumb_9<3,8>,  &arm::thumb_9<3,9>,  &arm::thumb_9<3,10>, &arm::thumb_9<3,11>,
    &arm::thumb_9<3,12>, &arm::thumb_9<3,13>, &arm::thumb_9<3,14>, &arm::thumb_9<3,15>,
    &arm::thumb_9<3,16>, &arm::thumb_9<3,17>, &arm::thumb_9<3,18>, &arm::thumb_9<3,19>,
    &arm::thumb_9<3,20>, &arm::thumb_9<3,21>, &arm::thumb_9<3,22>, &arm::thumb_9<3,23>,
    &arm::thumb_9<3,24>, &arm::thumb_9<3,25>, &arm::thumb_9<3,26>, &arm::thumb_9<3,27>,
    &arm::thumb_9<3,28>, &arm::thumb_9<3,29>, &arm::thumb_9<3,30>, &arm::thumb_9<3,31>,

    /* THUMB.10 Load/store halfword */
    &arm::thumb_10<0,0>,  &arm::thumb_10<0,1>,  &arm::thumb_10<0,2>,  &arm::thumb_10<0,3>,
    &arm::thumb_10<0,4>,  &arm::thumb_10<0,5>,  &arm::thumb_10<0,6>,  &arm::thumb_10<0,7>,
    &arm::thumb_10<0,8>,  &arm::thumb_10<0,9>,  &arm::thumb_10<0,10>, &arm::thumb_10<0,11>,
    &arm::thumb_10<0,12>, &arm::thumb_10<0,13>, &arm::thumb_10<0,14>, &arm::thumb_10<0,15>,
    &arm::thumb_10<0,16>, &arm::thumb_10<0,17>, &arm::thumb_10<0,18>, &arm::thumb_10<0,19>,
    &arm::thumb_10<0,20>, &arm::thumb_10<0,21>, &arm::thumb_10<0,22>, &arm::thumb_10<0,23>,
    &arm::thumb_10<0,24>, &arm::thumb_10<0,25>, &arm::thumb_10<0,26>, &arm::thumb_10<0,27>,
    &arm::thumb_10<0,28>, &arm::thumb_10<0,29>, &arm::thumb_10<0,30>, &arm::thumb_10<0,31>,
    &arm::thumb_10<1,0>,  &arm::thumb_10<1,1>,  &arm::thumb_10<1,2>,  &arm::thumb_10<1,3>,
    &arm::thumb_10<1,4>,  &arm::thumb_10<1,5>,  &arm::thumb_10<1,6>,  &arm::thumb_10<1,7>,
    &arm::thumb_10<1,8>,  &arm::thumb_10<1,9>,  &arm::thumb_10<1,10>, &arm::thumb_10<1,11>,
    &arm::thumb_10<1,12>, &arm::thumb_10<1,13>, &arm::thumb_10<1,14>, &arm::thumb_10<1,15>,
    &arm::thumb_10<1,16>, &arm::thumb_10<1,17>, &arm::thumb_10<1,18>, &arm::thumb_10<1,19>,
    &arm::thumb_10<1,20>, &arm::thumb_10<1,21>, &arm::thumb_10<1,22>, &arm::thumb_10<1,23>,
    &arm::thumb_10<1,24>, &arm::thumb_10<1,25>, &arm::thumb_10<1,26>, &arm::thumb_10<1,27>,
    &arm::thumb_10<1,28>, &arm::thumb_10<1,29>, &arm::thumb_10<1,30>, &arm::thumb_10<1,31>,

    /* THUMB.11 SP-relative load/store */
    &arm::thumb_11<0,0>, &arm::thumb_11<0,0>, &arm::thumb_11<0,0>, &arm::thumb_11<0,0>,
    &arm::thumb_11<0,1>, &arm::thumb_11<0,1>, &arm::thumb_11<0,1>, &arm::thumb_11<0,1>,
    &arm::thumb_11<0,2>, &arm::thumb_11<0,2>, &arm::thumb_11<0,2>, &arm::thumb_11<0,2>,
    &arm::thumb_11<0,3>, &arm::thumb_11<0,3>, &arm::thumb_11<0,3>, &arm::thumb_11<0,3>,
    &arm::thumb_11<0,4>, &arm::thumb_11<0,4>, &arm::thumb_11<0,4>, &arm::thumb_11<0,4>,
    &arm::thumb_11<0,5>, &arm::thumb_11<0,5>, &arm::thumb_11<0,5>, &arm::thumb_11<0,5>,
    &arm::thumb_11<0,6>, &arm::thumb_11<0,6>, &arm::thumb_11<0,6>, &arm::thumb_11<0,6>,
    &arm::thumb_11<0,7>, &arm::thumb_11<0,7>, &arm::thumb_11<0,7>, &arm::thumb_11<0,7>,
    &arm::thumb_11<1,0>, &arm::thumb_11<1,0>, &arm::thumb_11<1,0>, &arm::thumb_11<1,0>,
    &arm::thumb_11<1,1>, &arm::thumb_11<1,1>, &arm::thumb_11<1,1>, &arm::thumb_11<1,1>,
    &arm::thumb_11<1,2>, &arm::thumb_11<1,2>, &arm::thumb_11<1,2>, &arm::thumb_11<1,2>,
    &arm::thumb_11<1,3>, &arm::thumb_11<1,3>, &arm::thumb_11<1,3>, &arm::thumb_11<1,3>,
    &arm::thumb_11<1,4>, &arm::thumb_11<1,4>, &arm::thumb_11<1,4>, &arm::thumb_11<1,4>,
    &arm::thumb_11<1,5>, &arm::thumb_11<1,5>, &arm::thumb_11<1,5>, &arm::thumb_11<1,5>,
    &arm::thumb_11<1,6>, &arm::thumb_11<1,6>, &arm::thumb_11<1,6>, &arm::thumb_11<1,6>,
    &arm::thumb_11<1,7>, &arm::thumb_11<1,7>, &arm::thumb_11<1,7>, &arm::thumb_11<1,7>,

    /* THUMB.12 Load address */
    &arm::thumb_12<0,0>, &arm::thumb_12<0,0>, &arm::thumb_12<0,0>, &arm::thumb_12<0,0>,
    &arm::thumb_12<0,1>, &arm::thumb_12<0,1>, &arm::thumb_12<0,1>, &arm::thumb_12<0,1>,
    &arm::thumb_12<0,2>, &arm::thumb_12<0,2>, &arm::thumb_12<0,2>, &arm::thumb_12<0,2>,
    &arm::thumb_12<0,3>, &arm::thumb_12<0,3>, &arm::thumb_12<0,3>, &arm::thumb_12<0,3>,
    &arm::thumb_12<0,4>, &arm::thumb_12<0,4>, &arm::thumb_12<0,4>, &arm::thumb_12<0,4>,
    &arm::thumb_12<0,5>, &arm::thumb_12<0,5>, &arm::thumb_12<0,5>, &arm::thumb_12<0,5>,
    &arm::thumb_12<0,6>, &arm::thumb_12<0,6>, &arm::thumb_12<0,6>, &arm::thumb_12<0,6>,
    &arm::thumb_12<0,7>, &arm::thumb_12<0,7>, &arm::thumb_12<0,7>, &arm::thumb_12<0,7>,
    &arm::thumb_12<1,0>, &arm::thumb_12<1,0>, &arm::thumb_12<1,0>, &arm::thumb_12<1,0>,
    &arm::thumb_12<1,1>, &arm::thumb_12<1,1>, &arm::thumb_12<1,1>, &arm::thumb_12<1,1>,
    &arm::thumb_12<1,2>, &arm::thumb_12<1,2>, &arm::thumb_12<1,2>, &arm::thumb_12<1,2>,
    &arm::thumb_12<1,3>, &arm::thumb_12<1,3>, &arm::thumb_12<1,3>, &arm::thumb_12<1,3>,
    &arm::thumb_12<1,4>, &arm::thumb_12<1,4>, &arm::thumb_12<1,4>, &arm::thumb_12<1,4>,
    &arm::thumb_12<1,5>, &arm::thumb_12<1,5>, &arm::thumb_12<1,5>, &arm::thumb_12<1,5>,
    &arm::thumb_12<1,6>, &arm::thumb_12<1,6>, &arm::thumb_12<1,6>, &arm::thumb_12<1,6>,
    &arm::thumb_12<1,7>, &arm::thumb_12<1,7>, &arm::thumb_12<1,7>, &arm::thumb_12<1,7>,

    /* THUMB.13 Add offset to stack pointer,
       THUMB.14 Push/pop registers */
    &arm::thumb_13<0>,   &arm::thumb_13<0>,   &arm::thumb_13<1>,   &arm::thumb_13<1>,
    &arm::thumb_13<0>,   &arm::thumb_13<0>,   &arm::thumb_13<1>,   &arm::thumb_13<1>,
    &arm::thumb_13<0>,   &arm::thumb_13<0>,   &arm::thumb_13<1>,   &arm::thumb_13<1>,
    &arm::thumb_13<0>,   &arm::thumb_13<0>,   &arm::thumb_13<1>,   &arm::thumb_13<1>,
    &arm::thumb_14<0,0>, &arm::thumb_14<0,0>, &arm::thumb_14<0,0>, &arm::thumb_14<0,0>,
    &arm::thumb_14<0,1>, &arm::thumb_14<0,1>, &arm::thumb_14<0,1>, &arm::thumb_14<0,1>,
    &arm::thumb_14<0,0>, &arm::thumb_14<0,0>, &arm::thumb_14<0,0>, &arm::thumb_14<0,0>,
    &arm::thumb_14<0,1>, &arm::thumb_14<0,1>, &arm::thumb_14<0,1>, &arm::thumb_14<0,1>,
    &arm::thumb_13<0>,   &arm::thumb_13<0>,   &arm::thumb_13<1>,   &arm::thumb_13<1>,
    &arm::thumb_13<0>,   &arm::thumb_13<0>,   &arm::thumb_13<1>,   &arm::thumb_13<1>,
    &arm::thumb_13<0>,   &arm::thumb_13<0>,   &arm::thumb_13<1>,   &arm::thumb_13<1>,
    &arm::thumb_13<0>,   &arm::thumb_13<0>,   &arm::thumb_13<1>,   &arm::thumb_13<1>,
    &arm::thumb_14<1,0>, &arm::thumb_14<1,0>, &arm::thumb_14<1,0>, &arm::thumb_14<1,0>,
    &arm::thumb_14<1,1>, &arm::thumb_14<1,1>, &arm::thumb_14<1,1>, &arm::thumb_14<1,1>,
    &arm::thumb_14<1,0>, &arm::thumb_14<1,0>, &arm::thumb_14<1,0>, &arm::thumb_14<1,0>,
    &arm::thumb_14<1,1>, &arm::thumb_14<1,1>, &arm::thumb_14<1,1>, &arm::thumb_14<1,1>,

    /* THUMB.15 Multiple load/store */
    &arm::thumb_15<0,0>, &arm::thumb_15<0,0>, &arm::thumb_15<0,0>, &arm::thumb_15<0,0>,
    &arm::thumb_15<0,1>, &arm::thumb_15<0,1>, &arm::thumb_15<0,1>, &arm::thumb_15<0,1>,
    &arm::thumb_15<0,2>, &arm::thumb_15<0,2>, &arm::thumb_15<0,2>, &arm::thumb_15<0,2>,
    &arm::thumb_15<0,3>, &arm::thumb_15<0,3>, &arm::thumb_15<0,3>, &arm::thumb_15<0,3>,
    &arm::thumb_15<0,4>, &arm::thumb_15<0,4>, &arm::thumb_15<0,4>, &arm::thumb_15<0,4>,
    &arm::thumb_15<0,5>, &arm::thumb_15<0,5>, &arm::thumb_15<0,5>, &arm::thumb_15<0,5>,
    &arm::thumb_15<0,6>, &arm::thumb_15<0,6>, &arm::thumb_15<0,6>, &arm::thumb_15<0,6>,
    &arm::thumb_15<0,7>, &arm::thumb_15<0,7>, &arm::thumb_15<0,7>, &arm::thumb_15<0,7>,
    &arm::thumb_15<1,0>, &arm::thumb_15<1,0>, &arm::thumb_15<1,0>, &arm::thumb_15<1,0>,
    &arm::thumb_15<1,1>, &arm::thumb_15<1,1>, &arm::thumb_15<1,1>, &arm::thumb_15<1,1>,
    &arm::thumb_15<1,2>, &arm::thumb_15<1,2>, &arm::thumb_15<1,2>, &arm::thumb_15<1,2>,
    &arm::thumb_15<1,3>, &arm::thumb_15<1,3>, &arm::thumb_15<1,3>, &arm::thumb_15<1,3>,
    &arm::thumb_15<1,4>, &arm::thumb_15<1,4>, &arm::thumb_15<1,4>, &arm::thumb_15<1,4>,
    &arm::thumb_15<1,5>, &arm::thumb_15<1,5>, &arm::thumb_15<1,5>, &arm::thumb_15<1,5>,
    &arm::thumb_15<1,6>, &arm::thumb_15<1,6>, &arm::thumb_15<1,6>, &arm::thumb_15<1,6>,
    &arm::thumb_15<1,7>, &arm::thumb_15<1,7>, &arm::thumb_15<1,7>, &arm::thumb_15<1,7>,

    /* THUMB.16 Conditional branch */
    &arm::thumb_16<0>,  &arm::thumb_16<0>,  &arm::thumb_16<0>,  &arm::thumb_16<0>,
    &arm::thumb_16<1>,  &arm::thumb_16<1>,  &arm::thumb_16<1>,  &arm::thumb_16<1>,
    &arm::thumb_16<2>,  &arm::thumb_16<2>,  &arm::thumb_16<2>,  &arm::thumb_16<2>,
    &arm::thumb_16<3>,  &arm::thumb_16<3>,  &arm::thumb_16<3>,  &arm::thumb_16<3>,
    &arm::thumb_16<4>,  &arm::thumb_16<4>,  &arm::thumb_16<4>,  &arm::thumb_16<4>,
    &arm::thumb_16<5>,  &arm::thumb_16<5>,  &arm::thumb_16<5>,  &arm::thumb_16<5>,
    &arm::thumb_16<6>,  &arm::thumb_16<6>,  &arm::thumb_16<6>,  &arm::thumb_16<6>,
    &arm::thumb_16<7>,  &arm::thumb_16<7>,  &arm::thumb_16<7>,  &arm::thumb_16<7>,
    &arm::thumb_16<8>,  &arm::thumb_16<8>,  &arm::thumb_16<8>,  &arm::thumb_16<8>,
    &arm::thumb_16<9>,  &arm::thumb_16<9>,  &arm::thumb_16<9>,  &arm::thumb_16<9>,
    &arm::thumb_16<10>, &arm::thumb_16<10>, &arm::thumb_16<10>, &arm::thumb_16<10>,
    &arm::thumb_16<11>, &arm::thumb_16<11>, &arm::thumb_16<11>, &arm::thumb_16<11>,
    &arm::thumb_16<12>, &arm::thumb_16<12>, &arm::thumb_16<12>, &arm::thumb_16<12>,
    &arm::thumb_16<13>, &arm::thumb_16<13>, &arm::thumb_16<13>, &arm::thumb_16<13>,
    &arm::thumb_16<14>, &arm::thumb_16<14>, &arm::thumb_16<14>, &arm::thumb_16<14>,

    /* THUMB.17 Software Interrupt */
    &arm::thumb_17, &arm::thumb_17, &arm::thumb_17, &arm::thumb_17,

    /* THUMB.18 Unconditional branch */
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,
    &arm::thumb_18, &arm::thumb_18, &arm::thumb_18, &arm::thumb_18,

    /* THUMB.19 Long branch with link */
    &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>,
    &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>,
    &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>,
    &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>,
    &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>,
    &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>,
    &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>,
    &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>, &arm::thumb_19<0>,
    &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>,
    &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>,
    &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>,
    &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>,
    &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>,
    &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>,
    &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>,
    &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>, &arm::thumb_19<1>
};

#endif
