/* Copyright 2020 yushakobo
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

bool is_mac_mode(void);
void set_mac_mode(bool macmode);

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34, L35, L36, R36, R30, R31, R32, R33, R34, R35, \
  L40, L41, L42, L43, L44, L45, L46, R46, R40, R41, R42, R43, R44, R45  \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05, KC_NO }, \
    { L10, L11, L12, L13, L14, L15, KC_NO }, \
    { L20, L21, L22, L23, L24, L25, KC_NO }, \
    { L30, L31, L32, L33, L34, L35, L36 }, \
    { L40, L41, L42, L43, L44, L45, L46 }, \
    { R05, R04, R03, R02, R01, R00, KC_NO }, \
    { R15, R14, R13, R12, R11, R10, KC_NO }, \
    { R25, R24, R23, R22, R21, R20, KC_NO }, \
    { R35, R34, R33, R32, R31, R30, R36 }, \
    { R45, R44, R43, R42, R41, R40, R46 } \
 }

#define LAYOUT_SW( \
  L00R, L00C, L01R, L01C, L02R, L02C, L03R, L03C, L04R, L04C, L05R, L05C,                         R00R, R00C, R01R, R01C, R02R, R02C, R03R, R03C, R04R, R04C, R05R, R05C, \
  L10R, L10C, L11R, L11C, L12R, L12C, L13R, L13C, L14R, L14C, L15R, L15C,                         R10R, R10C, R11R, R11C, R12R, R12C, R13R, R13C, R14R, R14C, R15R, R15C, \
  L20R, L20C, L21R, L21C, L22R, L22C, L23R, L23C, L24R, L24C, L25R, L25C,                         R20R, R20C, R21R, R21C, R22R, R22C, R23R, R23C, R24R, R24C, R25R, R25C, \
  L30R, L30C, L31R, L31C, L32R, L32C, L33R, L33C, L34R, L34C, L35R, L35C, L36R, L36C, R36R, R36C, R30R, R30C, R31R, R31C, R32R, R32C, R33R, R33C, R34R, R34C, R35R, R35C, \
  L40R, L40C, L41R, L41C, L42R, L42C, L43R, L43C, L44R, L44C, L45R, L45C, L46R, L46C, R46R, R46C, R40R, R40C, R41R, R41C, R42R, R42C, R43R, R43C, R44R, R44C, R45R, R45C  \
  ) \
  { \
    { { L00R, L00C }, { L01R, L01C }, { L02R, L02C }, { L03R, L03C }, { L04R, L04C }, { L05R, L05C }, {0, 0} }, \
    { { L10R, L10C }, { L11R, L11C }, { L12R, L12C }, { L13R, L13C }, { L14R, L14C }, { L15R, L15C }, {0, 0} }, \
    { { L20R, L20C }, { L21R, L21C }, { L22R, L22C }, { L23R, L23C }, { L24R, L24C }, { L25R, L25C }, {0, 0} }, \
    { { L30R, L30C }, { L31R, L31C }, { L32R, L32C }, { L33R, L33C }, { L34R, L34C }, { L35R, L35C }, { L36R, L36C } }, \
    { { L40R, L40C }, { L41R, L41C }, { L42R, L42C }, { L43R, L43C }, { L44R, L44C }, { L45R, L45C }, { L46R, L46C } }, \
    { { R05R, R05C }, { R04R, R04C }, { R03R, R03C }, { R02R, R02C }, { R01R, R01C }, { R00R, R00C }, {0, 0} }, \
    { { R15R, R15C }, { R14R, R14C }, { R13R, R13C }, { R12R, R12C }, { R11R, R11C }, { R10R, R10C }, {0, 0} }, \
    { { R25R, R25C }, { R24R, R24C }, { R23R, R23C }, { R22R, R22C }, { R21R, R21C }, { R20R, R20C }, {0, 0} }, \
    { { R35R, R35C }, { R34R, R34C }, { R33R, R33C }, { R32R, R32C }, { R31R, R31C }, { R30R, R30C }, { R36R, R36C } }, \
    { { R45R, R45C }, { R44R, R44C }, { R43R, R43C }, { R42R, R42C }, { R41R, R41C }, { R40R, R40C }, { R46R, R46C } } \
 }
