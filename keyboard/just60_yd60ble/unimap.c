/*
Copyright 2016 Jun Wako <wakojun@gmail.com>

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
#include <avr/pgmspace.h>
#include "unimap_trans.h"
#include "bootloader.h"
#include "wait.h"
#include "keycode.h"
#include "action.h"
#include "action_util.h"
#include "keymap.h"
#include "rgblight.h"

enum function_id {
    NICOLA_Q,
    NICOLA_W,
    NICOLA_E,
    NICOLA_R,
    NICOLA_T,
    NICOLA_Y,
    NICOLA_U,
    NICOLA_I,
    NICOLA_O,
    NICOLA_P,
    NICOLA_LBRC,
    NICOLA_RBRC,
    NICOLA_A,
    NICOLA_S,
    NICOLA_D,
    NICOLA_F,
    NICOLA_G,
    NICOLA_H,
    NICOLA_J,
    NICOLA_K,
    NICOLA_L,
    NICOLA_SCLN,
    NICOLA_QUOT,
    NICOLA_Z,
    NICOLA_X,
    NICOLA_C,
    NICOLA_V,
    NICOLA_B,
    NICOLA_N,
    NICOLA_M,
    NICOLA_COMM,
    NICOLA_DOT,
    NICOLA_SLSH,
    NICOLA_LTHUMB,
    NICOLA_RTHUMB,
    NICOLA_ON,
    NICOLA_OFF,
};

#define AC_MO2       ACTION_LAYER_MOMENTARY(2)

#define AC_NGQ       ACTION_FUNCTION(NICOLA_Q)
#define AC_NGW       ACTION_FUNCTION(NICOLA_W)
#define AC_NGE       ACTION_FUNCTION(NICOLA_E)
#define AC_NGR       ACTION_FUNCTION(NICOLA_R)
#define AC_NGT       ACTION_FUNCTION(NICOLA_T)
#define AC_NGY       ACTION_FUNCTION(NICOLA_Y)
#define AC_NGU       ACTION_FUNCTION(NICOLA_U)
#define AC_NGI       ACTION_FUNCTION(NICOLA_I)
#define AC_NGO       ACTION_FUNCTION(NICOLA_O)
#define AC_NGP       ACTION_FUNCTION(NICOLA_P)
#define AC_NGLB      ACTION_FUNCTION(NICOLA_LBRC)
#define AC_NGRB      ACTION_FUNCTION(NICOLA_RBRC)
#define AC_NGA       ACTION_FUNCTION(NICOLA_A)
#define AC_NGS       ACTION_FUNCTION(NICOLA_S)
#define AC_NGD       ACTION_FUNCTION(NICOLA_D)
#define AC_NGF       ACTION_FUNCTION(NICOLA_F)
#define AC_NGG       ACTION_FUNCTION(NICOLA_G)
#define AC_NGH       ACTION_FUNCTION(NICOLA_H)
#define AC_NGJ       ACTION_FUNCTION(NICOLA_J)
#define AC_NGK       ACTION_FUNCTION(NICOLA_K)
#define AC_NGL       ACTION_FUNCTION(NICOLA_L)
#define AC_NGSC      ACTION_FUNCTION(NICOLA_SCLN)
#define AC_NGQT      ACTION_FUNCTION(NICOLA_QUOT)
#define AC_NGZ       ACTION_FUNCTION(NICOLA_Z)
#define AC_NGX       ACTION_FUNCTION(NICOLA_X)
#define AC_NGC       ACTION_FUNCTION(NICOLA_C)
#define AC_NGV       ACTION_FUNCTION(NICOLA_V)
#define AC_NGB       ACTION_FUNCTION(NICOLA_B)
#define AC_NGN       ACTION_FUNCTION(NICOLA_N)
#define AC_NGM       ACTION_FUNCTION(NICOLA_M)
#define AC_NGCM      ACTION_FUNCTION(NICOLA_COMM)
#define AC_NGDT      ACTION_FUNCTION(NICOLA_DOT)
#define AC_NGSL      ACTION_FUNCTION(NICOLA_SLSH)
#define AC_NGLT      ACTION_FUNCTION(NICOLA_LTHUMB)
#define AC_NGRT      ACTION_FUNCTION(NICOLA_RTHUMB)

#define AC_NCON      ACTION_FUNCTION(NICOLA_ON)
#define AC_NCOF      ACTION_FUNCTION(NICOLA_OFF)


#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    UNIMAP(
        BTN1,BTN2,BTN3,BTN4,BTN5,WH_U,WH_D, F20, F21, F22, F23, F24,
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,PAUS,         VOLD,VOLU,MUTE,
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, JYEN,BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,     BSLS,     DEL, END, PGDN,    P7,  P8,  P9,  PPLS,
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     SPC, ENT,                         P4,  P5,  P6,  PCMM,
        LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RO,  RSFT,          UP,           P1,  P2,  P3,  PENT,
        MO2, LGUI,LALT,MHEN,          SPC,           HENK,KANA,RALT,RGUI,APP, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PEQL
        ),
    UNIMAP(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
        TRNS,NGQ, NGW, NGE, NGR, NGT, NGY, NGU, NGI, NGO, NGP, NGLB,NGRB,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
        TRNS,NGA, NGS, NGD, NGF, NGG, NGH, NGJ, NGK, NGL, NGSC,NGQT,     NGLT,TRNS,                        TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,NGZ, NGX, NGC, NGV, NGB, NGN, NGM, NGCM,NGDT,NGSL,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,          NGRT,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
        ),
    UNIMAP(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        GRV,      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,HOME,PGDN,PGUP,END, PSCR,TRNS,  PAUS,   TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN,UP,  RGHT,INS, DEL,      NCOF,TRNS,                        TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,    TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,          NCON,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
        ),
};

static uint8_t is_nicola = 0;
static uint8_t n_modifier = 0;
extern uint32_t layer_state; 
typedef enum {
  NICOLA_STATE_S1_INIT,
  NICOLA_STATE_S2_M,
  NICOLA_STATE_S3_O,
  NICOLA_STATE_S4_MO,
  NICOLA_STATE_S5_OM
} nicola_state_t;
static nicola_state_t nicola_int_state = NICOLA_STATE_S1_INIT;
static uint8_t nicola_m_key;
static uint8_t nicola_o_key;
static uint16_t nicola_m_time;
static uint16_t nicola_o_time;

#define TIMEOUT_THRESHOLD (150)
#define OVERLAP_THRESHOLD (20)

void nicola_m_type(void) {
    switch(nicola_m_key) {
        case NICOLA_Q   : action_macro_play(MACRO(T(DOT), END)); break;
        case NICOLA_W   : action_macro_play(MACRO(T(K), T(A), END)); break;
        case NICOLA_E   : action_macro_play(MACRO(T(T), T(A), END)); break;
        case NICOLA_R   : action_macro_play(MACRO(T(K), T(O), END)); break;
        case NICOLA_T   : action_macro_play(MACRO(T(S), T(A), END)); break;
        case NICOLA_Y   : action_macro_play(MACRO(T(R), T(A), END)); break;
        case NICOLA_U   : action_macro_play(MACRO(T(T), T(I), END)); break;
        case NICOLA_I   : action_macro_play(MACRO(T(K), T(U), END)); break;
        case NICOLA_O   : action_macro_play(MACRO(T(T), T(U), END)); break;
        case NICOLA_P   : action_macro_play(MACRO(T(COMM), END)); break;
        case NICOLA_LBRC: action_macro_play(MACRO(T(COMM), END)); break;
        case NICOLA_RBRC: action_macro_play(MACRO(T(SCLN), END)); break;

        case NICOLA_A   : action_macro_play(MACRO(T(U), END)); break;
        case NICOLA_S   : action_macro_play(MACRO(T(S), T(I), END)); break;
        case NICOLA_D   : action_macro_play(MACRO(T(T), T(E), END)); break;
        case NICOLA_F   : action_macro_play(MACRO(T(K), T(E), END)); break;
        case NICOLA_G   : action_macro_play(MACRO(T(S), T(E), END)); break;
        case NICOLA_H   : action_macro_play(MACRO(T(H), T(A), END)); break;
        case NICOLA_J   : action_macro_play(MACRO(T(T), T(O), END)); break;
        case NICOLA_K   : action_macro_play(MACRO(T(K), T(I), END)); break;
        case NICOLA_L   : action_macro_play(MACRO(T(I), END)); break;
        case NICOLA_SCLN: action_macro_play(MACRO(T(N), T(N), END)); break;
        case NICOLA_QUOT: action_macro_play(MACRO(T(BSPC), END)); break;

        case NICOLA_Z   : action_macro_play(MACRO(T(DOT), END)); break;
        case NICOLA_X   : action_macro_play(MACRO(T(H), T(I), END)); break;
        case NICOLA_C   : action_macro_play(MACRO(T(S), T(U), END)); break;
        case NICOLA_V   : action_macro_play(MACRO(T(H), T(U), END)); break;
        case NICOLA_B   : action_macro_play(MACRO(T(H), T(E), END)); break;
        case NICOLA_N   : action_macro_play(MACRO(T(M), T(E), END)); break;
        case NICOLA_M   : action_macro_play(MACRO(T(S), T(O), END)); break;
        case NICOLA_COMM: action_macro_play(MACRO(T(N), T(E), END)); break;
        case NICOLA_DOT : action_macro_play(MACRO(T(H), T(O), END)); break;
        case NICOLA_SLSH: action_macro_play(MACRO(T(SLSH), END)); break;
    }
}

void nicola_o_type(void) {
    if(nicola_o_key != 0) {
        action_macro_play(MACRO(T(SPC), END));
    }
}

void nicola_om_type(void) {
    if(nicola_o_key == NICOLA_LTHUMB) {
        switch(nicola_m_key) {
            case NICOLA_Q   : action_macro_play(MACRO(T(X), T(A), END)); break;
            case NICOLA_W   : action_macro_play(MACRO(T(E), END)); break;
            case NICOLA_E   : action_macro_play(MACRO(T(R), T(I), END)); break;
            case NICOLA_R   : action_macro_play(MACRO(T(X), T(Y), T(A), END)); break;
            case NICOLA_T   : action_macro_play(MACRO(T(R), T(E), END)); break;
            case NICOLA_Y   : action_macro_play(MACRO(T(P), T(A), END)); break;
            case NICOLA_U   : action_macro_play(MACRO(T(D), T(I), END)); break;
            case NICOLA_I   : action_macro_play(MACRO(T(G), T(U), END)); break;
            case NICOLA_O   : action_macro_play(MACRO(T(D), T(U), END)); break;
            case NICOLA_P   : action_macro_play(MACRO(T(P), T(I), END)); break;
            case NICOLA_LBRC: action_macro_play(MACRO(T(LBRC), END)); break;
            case NICOLA_RBRC: action_macro_play(MACRO(T(RBRC), END)); break;

            case NICOLA_A   : action_macro_play(MACRO(T(W), T(O), END)); break;
            case NICOLA_S   : action_macro_play(MACRO(T(A), END)); break;
            case NICOLA_D   : action_macro_play(MACRO(T(N), T(A), END)); break;
            case NICOLA_F   : action_macro_play(MACRO(T(X), T(Y), T(U), END)); break;
            case NICOLA_G   : action_macro_play(MACRO(T(M), T(O), END)); break;
            case NICOLA_H   : action_macro_play(MACRO(T(B), T(A), END)); break;
            case NICOLA_J   : action_macro_play(MACRO(T(D), T(O), END)); break;
            case NICOLA_K   : action_macro_play(MACRO(T(G), T(I), END)); break;
            case NICOLA_L   : action_macro_play(MACRO(T(P), T(O), END)); break;
            case NICOLA_SCLN: break;
            case NICOLA_QUOT: action_macro_play(MACRO(T(BSPC), END)); break;

            case NICOLA_Z   : action_macro_play(MACRO(T(X), T(U), END)); break;
            case NICOLA_X   : action_macro_play(MACRO(T(MINS), END)); break;
            case NICOLA_C   : action_macro_play(MACRO(T(R), T(O), END)); break;
            case NICOLA_V   : action_macro_play(MACRO(T(Y), T(A), END)); break;
            case NICOLA_B   : action_macro_play(MACRO(T(X), T(O), END)); break;
            case NICOLA_N   : action_macro_play(MACRO(T(P), T(U), END)); break;
            case NICOLA_M   : action_macro_play(MACRO(T(Z), T(O), END)); break;
            case NICOLA_COMM: action_macro_play(MACRO(T(P), T(E), END)); break;
            case NICOLA_DOT : action_macro_play(MACRO(T(B), T(O), END)); break;
            case NICOLA_SLSH: action_macro_play(MACRO(D(LSHIFT), T(SLSH), U(LSHIFT), END)); break;
        }
    } else if(nicola_o_key == NICOLA_RTHUMB) {
        switch(nicola_m_key) {
            case NICOLA_Q   : break;
            case NICOLA_W   : action_macro_play(MACRO(T(G), T(A), END)); break;
            case NICOLA_E   : action_macro_play(MACRO(T(D), T(A), END)); break;
            case NICOLA_R   : action_macro_play(MACRO(T(G), T(O), END)); break;
            case NICOLA_T   : action_macro_play(MACRO(T(Z), T(A), END)); break;
            case NICOLA_Y   : action_macro_play(MACRO(T(Y), T(O), END)); break;
            case NICOLA_U   : action_macro_play(MACRO(T(N), T(I), END)); break;
            case NICOLA_I   : action_macro_play(MACRO(T(R), T(U), END)); break;
            case NICOLA_O   : action_macro_play(MACRO(T(M), T(A), END)); break;
            case NICOLA_P   : action_macro_play(MACRO(T(X), T(E), END)); break;
            case NICOLA_LBRC: action_macro_play(MACRO(T(LBRC), END)); break;
            case NICOLA_RBRC: action_macro_play(MACRO(T(RBRC), END)); break;

            case NICOLA_A   : action_macro_play(MACRO(T(V), T(U), END)); break;
            case NICOLA_S   : action_macro_play(MACRO(T(Z), T(I), END)); break;
            case NICOLA_D   : action_macro_play(MACRO(T(D), T(E), END)); break;
            case NICOLA_F   : action_macro_play(MACRO(T(G), T(E), END)); break;
            case NICOLA_G   : action_macro_play(MACRO(T(Z), T(E), END)); break;
            case NICOLA_H   : action_macro_play(MACRO(T(M), T(I), END)); break;
            case NICOLA_J   : action_macro_play(MACRO(T(O), END)); break;
            case NICOLA_K   : action_macro_play(MACRO(T(N), T(O), END)); break;
            case NICOLA_L   : action_macro_play(MACRO(T(X), T(Y), T(O), END)); break;
            case NICOLA_SCLN: action_macro_play(MACRO(T(X), T(T), T(U), END)); break;
            case NICOLA_QUOT: action_macro_play(MACRO(T(QUOT), END)); break;

            case NICOLA_Z   : break;
            case NICOLA_X   : action_macro_play(MACRO(T(B), T(I), END)); break;
            case NICOLA_C   : action_macro_play(MACRO(T(Z), T(U), END)); break;
            case NICOLA_V   : action_macro_play(MACRO(T(B), T(U), END)); break;
            case NICOLA_B   : action_macro_play(MACRO(T(B), T(E), END)); break;
            case NICOLA_N   : action_macro_play(MACRO(T(N), T(U), END)); break;
            case NICOLA_M   : action_macro_play(MACRO(T(Y), T(U), END)); break;
            case NICOLA_COMM: action_macro_play(MACRO(T(M), T(U), END)); break;
            case NICOLA_DOT : action_macro_play(MACRO(T(W), T(A), END)); break;
            case NICOLA_SLSH: action_macro_play(MACRO(T(X), T(O), END)); break;
        }
    }
}

void action_hook_key(keyrecord_t *record, action_t action) {
    if(is_nicola == 0) return;

    if (record->event.pressed) {
        switch(nicola_int_state) {
            case NICOLA_STATE_S1_INIT:
                break;
            case NICOLA_STATE_S2_M:
                nicola_m_type();
                break;
            case NICOLA_STATE_S3_O:
                nicola_o_type();
                break;
            case NICOLA_STATE_S4_MO:
                nicola_om_type();
                break;
            case NICOLA_STATE_S5_OM:
                nicola_om_type();
                break;
        }
        nicola_int_state = NICOLA_STATE_S1_INIT;

        switch (action.key.code) {
            case KC_LCTL:
            case KC_LSFT:
            case KC_LALT:
            case KC_LGUI:
            case KC_RCTL:
            case KC_RSFT:
            case KC_RALT:
            case KC_RGUI:
                if(n_modifier == 0) {
                    layer_state &= ~(1<<1);
                }
                n_modifier++;
                break;
            default:
                break;
        }
    } else {
        switch (action.key.code) {
            case KC_LCTL:
            case KC_LSFT:
            case KC_LALT:
            case KC_LGUI:
            case KC_RCTL:
            case KC_RSFT:
            case KC_RALT:
            case KC_RGUI:
                n_modifier--;
                if (n_modifier == 0) {
                    layer_state |= (1<<1);
                }
                break;
            default:
                break;
        }
    }
}

#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    static uint8_t mod_keys_registered;
    uint16_t curr_time = timer_read();
    if (record->event.pressed) {
        if(id == NICOLA_ON) {
            action_macro_play(MACRO(T(LANG1), END));
            is_nicola = 1;
            nicola_int_state = NICOLA_STATE_S1_INIT;
            layer_state |= (1<<1);
        } else if(id == NICOLA_OFF) {
            action_macro_play(MACRO(T(LANG2), END));
            is_nicola = 0;
            nicola_int_state = NICOLA_STATE_S1_INIT;
            layer_state &= ~(1<<1);
        } else if(NICOLA_Q <= id && id <= NICOLA_SLSH) {
            // M key
            switch(nicola_int_state) {
                case NICOLA_STATE_S1_INIT:
                    // no timeout check
                    nicola_int_state = NICOLA_STATE_S2_M;
                    break;
                case NICOLA_STATE_S2_M:
                    // same behavior for time out and sequential stroke
                    nicola_m_type();
                    break;
                case NICOLA_STATE_S3_O:
                    // timeout check
                    if(curr_time - nicola_o_time > TIMEOUT_THRESHOLD) {
                        // timeout => (output O) => S2
                        nicola_o_type();
                        nicola_int_state = NICOLA_STATE_S2_M;
                    } else {
                        // combo => S5
                        nicola_int_state = NICOLA_STATE_S5_OM;
                    }
                    break;
                case NICOLA_STATE_S4_MO:
                    // timeout check
                    if(curr_time - nicola_o_time > TIMEOUT_THRESHOLD) {
                        // timeout => (output MO) => S2
                        nicola_om_type();
                        nicola_int_state = NICOLA_STATE_S2_M;
                    } else {
                        // combo => three key judge
                        uint16_t t1 = nicola_o_time - nicola_m_time;
                        uint16_t t2 = curr_time - nicola_o_time;
                        if(t1 < t2) {
                            // the O key in between is combo with the leading M key
                            nicola_om_type();
                            nicola_int_state = NICOLA_STATE_S2_M;
                        } else {
                            // the leading M key is single, the O key in between is combo with current key
                            nicola_m_type();
                            nicola_int_state = NICOLA_STATE_S5_OM;
                        }
                    }
                    break;
                case NICOLA_STATE_S5_OM:
                    // same behavior for time out and sequential stroke
                    nicola_om_type();
                    nicola_int_state = NICOLA_STATE_S2_M;
                    break;
            }
            nicola_m_key = id;
            nicola_m_time = curr_time;
        } else if(id == NICOLA_LTHUMB || id == NICOLA_RTHUMB ) {
            // O key
            switch(nicola_int_state) {
                case NICOLA_STATE_S1_INIT:
                    // no timeout check
                    nicola_int_state = NICOLA_STATE_S3_O;
                    break;
                case NICOLA_STATE_S2_M:
                    // timeout check
                    if(curr_time - nicola_m_time > TIMEOUT_THRESHOLD) {
                        // timeout => (output M) => S3
                        nicola_m_type();
                        nicola_int_state = NICOLA_STATE_S3_O;
                    } else {
                        // combo => S4
                        nicola_int_state = NICOLA_STATE_S4_MO;
                    }
                    break;
                case NICOLA_STATE_S3_O:
                    // same behavior for time out and sequential stroke
                    nicola_o_type();
                    break;
                case NICOLA_STATE_S4_MO:
                    // same behavior for time out and sequential stroke
                    nicola_om_type();
                    nicola_int_state = NICOLA_STATE_S3_O;
                    break;
                case NICOLA_STATE_S5_OM:
                    // timeout check
                    if(curr_time - nicola_m_time > TIMEOUT_THRESHOLD) {
                        // timeout => (output MO) => S3
                        nicola_om_type();
                        nicola_int_state = NICOLA_STATE_S3_O;
                    } else {
                        // combo => three key judge
                        uint16_t t1 = nicola_m_time - nicola_o_time;
                        uint16_t t2 = curr_time - nicola_m_time;
                        if(t1 < t2) {
                            // the M key in between is combo with the leading O key
                            nicola_om_type();
                            nicola_int_state = NICOLA_STATE_S3_O;
                        } else {
                            // the leading O key is single, the M key in between is combo with current key
                            nicola_o_type();
                            nicola_int_state = NICOLA_STATE_S4_MO;
                        }
                    }
                    break;
            }
            nicola_o_key = id;
            nicola_o_time = curr_time;
        }
    } else {
        if(NICOLA_Q <= id && id <= NICOLA_RTHUMB) {
            switch(nicola_int_state) {
                case NICOLA_STATE_S1_INIT:
                    break;
                case NICOLA_STATE_S2_M:
                    if(nicola_m_key == id) {
                        nicola_m_type();
                        nicola_int_state = NICOLA_STATE_S1_INIT;
                    }
                    break;
                case NICOLA_STATE_S3_O:
                    if(nicola_o_key == id) {
                        nicola_o_type();
                        nicola_int_state = NICOLA_STATE_S1_INIT;
                    }
                    break;
                case NICOLA_STATE_S4_MO:
                    if(nicola_m_key == id) {
                        // M ON --> O ON --> M OFF
                        uint16_t t1 = nicola_o_time - nicola_m_time;
                        uint16_t t2 = curr_time - nicola_o_time;
                        if(t1>=t2 && t2 < OVERLAP_THRESHOLD) {
                            // M ON --> O ON --> M OFF (M is output, but O is still open to combo)
                            nicola_m_type();
                            nicola_int_state = NICOLA_STATE_S3_O;
                        } else {
                            // M ON --> O ON --> M OFF (both M and O are output)
                            nicola_om_type();
                            nicola_int_state = NICOLA_STATE_S1_INIT;
                        }
                    } else if(nicola_o_key == id) {
                        // M ON --> O ON --> O OFF (both M and O are output)
                        nicola_om_type();
                        nicola_int_state = NICOLA_STATE_S1_INIT;
                    }
                    break;
                case NICOLA_STATE_S5_OM:
                    if(nicola_o_key == id) {
                        // O ON --> M ON --> O OFF
                        uint16_t t1 = nicola_m_time - nicola_o_time;
                        uint16_t t2 = curr_time - nicola_m_time;
                        if(t1>=t2 && t2 < OVERLAP_THRESHOLD) {
                            // O ON --> M ON --> O OFF (O is output, but M is still open to combo)
                            nicola_o_type();
                            nicola_int_state = NICOLA_STATE_S2_M;
                        } else {
                            // O ON --> M ON --> O OFF (both M and O are output)
                            nicola_om_type();
                            nicola_int_state = NICOLA_STATE_S1_INIT;
                        }
                    } else if(nicola_m_key == id) {
                        // O ON --> M ON --> M OFF (both O and M are output)
                        nicola_om_type();
                        nicola_int_state = NICOLA_STATE_S1_INIT;
                    }
                    break;
            }
        }
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    static uint16_t key_timer;
    switch(id) {
    }
    return MACRO_NONE;
};
