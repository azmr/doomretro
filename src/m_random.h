/*
========================================================================

                           D O O M  R e t r o
         The classic, refined DOOM source port. For Windows PC.

========================================================================

  Copyright © 1993-2022 by id Software LLC, a ZeniMax Media company.
  Copyright © 2013-2022 by Brad Harding <mailto:brad@doomretro.com>.

  DOOM Retro is a fork of Chocolate DOOM. For a list of credits, see
  <https://github.com/bradharding/doomretro/wiki/CREDITS>.

  This file is a part of DOOM Retro.

  DOOM Retro is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation, either version 3 of the license, or (at your
  option) any later version.

  DOOM Retro is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with DOOM Retro. If not, see <https://www.gnu.org/licenses/>.

  DOOM is a registered trademark of id Software LLC, a ZeniMax Media
  company, in the US and/or other countries, and is used without
  permission. All other trademarks are the property of their respective
  holders. DOOM Retro is in no way affiliated with nor endorsed by
  id Software.

========================================================================
*/

#if !defined(__M_RANDOM_H__)
#define __M_RANDOM_H__

#include "m_fixed.h"

#define BIGSEED 143

#define RAND    rndtable[(seed = (seed + 1) & 255)]
#define BIGRAND ((bigseed = 214013 * bigseed + 2531011) >> 16)

static const unsigned char rndtable[] =
{
      0,   8, 109, 220, 222, 241, 149, 107,  75, 248, 254, 140,  16,  66,  74,  21,
    211,  47,  80, 242, 154,  27, 205, 128, 161,  89,  77,  36,  95, 110,  85,  48,
    212, 140, 211, 249,  22,  79, 200,  50,  28, 188,  52, 140, 202, 120,  68, 145,
     62,  70, 184, 190,  91, 197, 152, 224, 149, 104,  25, 178, 252, 182, 202, 182,
    141, 197,   4,  81, 181, 242, 145,  42,  39, 227, 156, 198, 225, 193, 219,  93,
    122, 175, 249,   0, 175, 143,  70, 239,  46, 246, 163,  53, 163, 109, 168, 135,
      2, 235,  25,  92,  20, 145, 138,  77,  69, 166,  78, 176, 173, 212, 166, 113,
     94, 161,  41,  50, 239,  49, 111, 164,  70,  60,   2,  37, 171,  75, 136, 156,
     11,  56,  42, 146, 138, 229,  73, 146,  77,  61,  98, 196, 135, 106,  63, 197,
    195,  86,  96, 203, 113, 101, 170, 247, 181, 113,  80, 250, 108,   7, 255, 237,
    129, 226,  79, 107, 112, 166, 103, 241,  24, 223, 239, 120, 198,  58,  60,  82,
    128,   3, 184,  66, 143, 224, 145, 224,  81, 206, 163,  45,  63,  90, 168, 114,
     59,  33, 159,  95,  28, 139, 123,  98, 125, 196,  15,  70, 194, 253,  54,  14,
     109, 226, 71,  17, 161,  93, 186,  87, 244, 138,  20,  52, 123, 251,  26,  36,
     17,  46,  52, 231, 232,  76,  31, 221,  84,  37, 216, 165, 212, 106, 197, 242,
     98,  43,  39, 175, 254, 145, 190,  84, 118, 222, 187, 136, 120, 163, 236, 249
};

extern unsigned int seed;
extern unsigned int bigseed;

int P_RandomHitscanAngle(fixed_t spread);
int P_RandomHitscanSlope(fixed_t spread);

static inline int M_Random(void)
{
    return RAND;
}

static inline int M_SubRandom(void)
{
    int r = RAND;

    return (r - RAND);
}

static inline int M_RandomInt(int lower, int upper)
{
    return (RAND % (upper - lower + 1) + lower);
}

static inline int M_RandomIntNoRepeat(int lower, int upper, int previous)
{
    int result;

    while ((result = (RAND % (upper - lower + 1) + lower)) == previous);

    return result;
}

static inline void M_Seed(unsigned int value)
{
    seed = value;
}

static inline int M_BigRandom(void)
{
    return BIGRAND;
}

static inline int M_BigSubRandom(void)
{
    return ((BIGRAND & 510) - 255);
}

static inline int M_BigRandomInt(int lower, int upper)
{
    return (BIGRAND % (upper - lower + 1) + lower);
}

static inline int M_BigRandomIntNoRepeat(int lower, int upper, int previous)
{
    int result;

    while ((result = (BIGRAND % (upper - lower + 1) + lower)) == previous);

    return result;
}

static inline void M_BigSeed(unsigned int value)
{
    bigseed = value;
}

#endif
