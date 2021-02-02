/* Copyright 2021 teakettle.tk
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    q,   w,   f,   p,   b,   j,   l,   u,   y,   a, \
    qq,  ww,  ff,  pp,  bb,  jj,  ll,  uu,  yy,  aa, \
    qqq, www, fff, ppp, bbb, jjj, lll, uuu, yyy, aaa \
) { \
    { q,   w,   f,   p,   b,   j,   l,   u,   y,   a   }, \
    { qq,  ww,  ff,  pp,  bb,  jj,  ll,  uu,  yy,  aa  }, \
    { qqq, www, fff, ppp, bbb, jjj, lll, uuu, yyy, aaa }  \
}
