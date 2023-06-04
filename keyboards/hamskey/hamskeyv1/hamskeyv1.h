/*
Copyright 2021 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

// clang-format off

#define LAYOUT( \
         LA6, LA5, LA4, LA3, LA2, LA1,           RA1, RA2, RA3, RA4, RA5, RA6, \
    LA7, LB6, LB5, LB4, LB3, LB2, LB1,           RB1, RB2, RB3, RB4, RB5, RB6, RB7, \
    LB7, LC6, LC5, LC4, LC3, LC2, LC1,           RC1, RC2, RC3, RC4, RC5, RC6, RC7, \
    LC7, LD6, LD5, LD4, LD3, LD2, LD1, LE1, RE1, RD1, RD2, RD3, RD4, RD5, RD6, RD7, \
         LD7, LE7, LE6, LE5, LE4, LE3, LE2, RE2, RE3,                RE5, RE6 \
    ) \
    { \
        { LA1, LA2, LA3, LA4, LA5, LA6, LA7 }, \
        { LB1, LB2, LB3, LB4, LB5, LB6, LB7 }, \
        { LC1, LC2, LC3, LC4, LC5, LC6, LC7 }, \
        { LD1, LD2, LD3, LD4, LD5, LD6, LD7 }, \
        { LE1, LE2, LE3, LE4, LE5, LE6, LE7 }, \
        { RA1, RA2, RA3, RA4, RA5, RA6, KC_NO }, \
        { RB1, RB2, RB3, RB4, RB5, RB6, RB7 }, \
        { RC1, RC2, RC3, RC4, RC5, RC6, RC7 }, \
        { RD1, RD2, RD3, RD4, RD5, RD6, RD7 }, \
        { RE1, RE2, RE3, KC_NO, RE5, RE6, KC_NO }  \
    }

// clang-format on

