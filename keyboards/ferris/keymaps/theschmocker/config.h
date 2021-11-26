/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

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

#define COMBO_ALLOW_ACTION_KEYS 
#define COMBO_VARIABLE_LEN
#undef IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_DELAY          50
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0

// copied from germ/qmk_firmware base gergoplex config
#define TAPPING_TOGGLE  1
#define TAPPING_TERM    200
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
#define COMBO_TERM 40