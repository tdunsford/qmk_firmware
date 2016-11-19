#include "atomic.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "led.h"
#include "mousekey.h"

enum keyboard_layers {
  LAYER_QWERTY = 0,
  LAYER_UPPER,
  LAYER_LOWER,
  LAYER_FUNCTION,
  LAYER_MOUSE,
  LAYER_ADJUST,
};
enum keyboard_macros {
  MACRO_QWERTY = 0,
  MACRO_UPPER,
  MACRO_LOWER,
  MACRO_FUNCTION,
  MACRO_MOUSE,
  MACRO_BACKLIGHT,
  MACRO_BREATH_TOGGLE,
  MACRO_BREATH_SPEED_INC,
  MACRO_BREATH_SPEED_DEC,
  MACRO_BREATH_DEFAULT,
  MACRO_MOUSE_MOVE_UL,
  MACRO_MOUSE_MOVE_UR,
  MACRO_MOUSE_MOVE_DL,
  MACRO_MOUSE_MOVE_DR,
  MACRO_HELP_1,
  MACRO_HELP_2,
  MACRO_HELP_3,
  MACRO_HELP_4,
  MACRO_HELP_5,
  MACRO_HELP_6,
  MACRO_HELP_7,
  MACRO_HELP_8,
  MACRO_HELP_9,
  HYPER_COPY,
};

#define M_QWRTY             M(MACRO_QWERTY)
#define M_UPPER             M(MACRO_UPPER)
#define M_LOWER             M(MACRO_LOWER)
#define M_FUNCT             M(MACRO_FUNCTION)
#define M_MOUSE             M(MACRO_MOUSE)
#define M_BACKL             M(MACRO_BACKLIGHT)
#define M_BRTOG             M(MACRO_BREATH_TOGGLE)
#define M_BSPDU             M(MACRO_BREATH_SPEED_INC)
#define M_BSPDD             M(MACRO_BREATH_SPEED_DEC)
#define M_BDFLT             M(MACRO_BREATH_DEFAULT)
#define M_MS_UL             M(MACRO_MOUSE_MOVE_UL)
#define M_MS_UR             M(MACRO_MOUSE_MOVE_UR)
#define M_MS_DL             M(MACRO_MOUSE_MOVE_DL)
#define M_MS_DR             M(MACRO_MOUSE_MOVE_DR)
#define M_HELP1             M(MACRO_HELP_1)
#define M_HELP2             M(MACRO_HELP_2)
#define M_HELP3             M(MACRO_HELP_3)
#define M_HELP4             M(MACRO_HELP_4)
#define M_HELP5             M(MACRO_HELP_5)
#define M_HELP6             M(MACRO_HELP_6)
#define M_HELP7             M(MACRO_HELP_7)
#define M_HELP8             M(MACRO_HELP_8)
#define M_HELP9             M(MACRO_HELP_9)

// #define M_HYPR              OSM(MOD_HYPR)
#define M_HYPR              M(HYPER_COPY)

#define SC_UNDO             LCTL(KC_Z)
#define SC_REDO             LCTL(KC_Y)
#define SC_CUT              LCTL(KC_X)
#define SC_COPY             LCTL(KC_C)
#define SC_PSTE             LCTL(KC_V)
#define SC_SELA             LCTL(KC_A)
#define SC_SAVE             LCTL(KC_S)
#define SC_OPEN             LCTL(KC_O)
#define SC_ACLS             LALT(KC_F4)
#define SC_CCLS             LCTL(KC_F4)

#define TG_NKRO             MAGIC_TOGGLE_NKRO
#define OS_SHFT             KC_FN0

#define _______             KC_TRNS
#define XXXXXXX             KC_NO
#define ________________    _______, _______
#define XXXXXXXXXXXXXXXX    XXXXXXX, XXXXXXX

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER = LAYER_QWERTY
  .--------------------------------------------------------------------------------------------------------------------------------------.
  | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | BACKSP . BACKSP |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \      | DEL    |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | CAP LK | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | ENTER  . ENTER  | PG UP  |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | RSHIFT . RSHIFT | UP     | PG DN  |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | LCTRL  | LWIN   | FN     | LALT   | UPPER  | SPACE  . SPACE  | LOWER  | OSHIFT | RALT   | APP    | RCTRL  | LEFT   | DOWN   | RIGHT  |
  '--------------------------------------------------------------------------------------------------------------------------------------'
*/
[LAYER_QWERTY] = {
  { KC_ESC,  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_PAUS, KC_PSCR },
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS },
  { KC_RCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, M_HYPR,  KC_UP,   KC_END  },
  { KC_LCTL, KC_LGUI, KC_NO,   KC_LALT, M_UPPER, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  M_LOWER, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT }
},

/* LAYER = LAYER_UPPER
  .--------------------------------------------------------------------------------------------------------------------------------------.
  | PRINT  | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | NUM LK | KP /   | KP *   | KP -   | XXXXXX | XXXXXX | ______ . ______ |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | PAUSE  | F1     | F2     | F3     | F4     | NUM LK | KP /   | KP 7   | KP 8   | KP 9   | KP -   | ______ | ______ | ______ | INS    |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | ______ | F5     | F6     | F7     | F8     | CAP LK | KP *   | KP 4   | KP 5   | KP 6   | KP +   | ______ | ______ . ______ | HOME   |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | ______ | F9     | F10    | F11    | F12    | SCR LK | KP 0   | KP 1   | KP 2   | KP 3   | KP ENT | ______ . ______ | ______ | END    |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | ______ | ______ | ______ | ______ | UPPER  | KP 0   . KP 0   | ______ | RALT   | KP .   | KP ENT | ______ | ______ | ______ | ______ |
  '--------------------------------------------------------------------------------------------------------------------------------------'
*/
[LAYER_UPPER] = {
  { KC_ESC,  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_PAUS, KC_PSCR },
  { KC_PSCR, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_BSPC, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______ },
  { KC_PAUS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_NLCK, KC_BSPC, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______, _______, _______, KC_INS  },
  { _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_CAPS, KC_ENT,  KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______, _______, _______, KC_HOME },
  { _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_SLCK, KC_ENT,  KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, _______, _______, KC_PGUP, KC_END  },
  { _______, _______, _______, _______, M_UPPER, KC_SPC,  KC_SPC,  KC_SPC, KC_SPC, ______, KC_PENT, _______, KC_HOME, KC_PGDN, KC_END  }
},
/* LAYER = LAYER_LOWER
  .--------------------------------------------------------------------------------------------------------------------------------------.
  | PRINT  | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | ______ . ______ |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | ______ | $      | {      | [      | (      | %      | #      | )      | ]      | }      | @      | ______ | ______ | ______ | INS    |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | ______ | ^      | *      | +      | -      | /      | \      | _      | '      | "      | `      | ______ | ______ . ______ | HOME   |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | ______ | |      | &      | !      | ~      | ;      | :      | =      | <      | >      | ?      | ______ . ______ | ______ | END    |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | ______ | ______ | ______ | ______ | ______ | ______ . ______ | LOWER  | ______ | ______ | ______ | ______ | ______ | ______ | ______ |
  '--------------------------------------------------------------------------------------------------------------------------------------'
*/
[LAYER_LOWER] = {
  { KC_ESC,  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_PAUS, KC_PSCR },
  { KC_PSCR, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_BSPC, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______ },
  { KC_PAUS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_NLCK, KC_BSPC, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______, _______, _______, KC_INS  },
  { _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_CAPS, KC_ENT,  KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______, _______, _______, KC_HOME },
  { _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_SLCK, KC_ENT,  KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, _______, _______, KC_PGUP, KC_END  },
  { _______, _______, _______, _______, M_UPPER, KC_SPC,  KC_SPC,  KC_SPC, KC_SPC, ______, KC_PENT, _______, KC_HOME, KC_PGDN, KC_END  }
},
/* LAYER = LAYER_FUNCTION
  .--------------------------------------------------------------------------------------------------------------------------------------.
  | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX . XXXXXX |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | XXXXXX | F13    | F14    | F15    | F16    | NUM LK | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | XXXXXX | F17    | F18    | F19    | F20    | SCR LK | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX . XXXXXX | XXXXXX |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | ______ | F21    | F22    | F23    | F24    | CAP LK | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | ______ . ______ | VOL UP | MUTE   |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | ______ | ______ | FN     | ______ | ______ | PLAY   . PLAY   | ______ | ______ | ______ | ______ | ______ | PREV   | VOL DN | NEXT   |
  '--------------------------------------------------------------------------------------------------------------------------------------'
*/
[LAYER_FUNCTION] = {
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  { XXXXXXX, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_NLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  { XXXXXXX, KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  { _______, KC_F21 , KC_F22 , KC_F23 , KC_F24 , KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_VOLU, KC_MUTE },
  { _______, _______, M_FUNCT, _______, _______, KC_MPLY, KC_MPLY, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT }
},
/* LAYER = LAYER_MOUSE
  .--------------------------------------------------------------------------------------------------------------------------------------.
  | ESC    | MS AC0 | MS AC1 | MS AC2 | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX . XXXXXX |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | MS UL  | MS U   | MS UR  | XXXXXX | XXXXXX | XXXXXX | MS WHL | MS WHR |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | XXXXXX | MS BT5 | MS BT4 | MS BT3 | MS BT2 | XXXXXX | XXXXXX | MS L   | XXXXXX | MS R   | XXXXXX | XXXXXX | XXXXXX . XXXXXX | MS WHU |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | ______ | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | MS DL  | MS D   | MS DR  | XXXXXX | ______ . ______ | MS U   | MS WHD |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | ______ | ______ | ______ | ______ | ______ | MS BT1 . MS BT1 | ______ | ______ | ______ | ______ | ______ | MS L   | MS D   | MS R   |
  '--------------------------------------------------------------------------------------------------------------------------------------'
*/
[LAYER_MOUSE] = {
  { M_QWRTY, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  { M_QWRTY, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M_MS_UL, KC_MS_U, M_MS_UR, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_R },
  { XXXXXXX, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, KC_MS_L, XXXXXXX, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M_MS_DL, KC_MS_D, M_MS_DR, XXXXXXX, _______, _______, KC_MS_U, KC_WH_D },
  { _______, _______, _______, _______, M_UPPER, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, M_LOWER, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R }
},
/* LAYER = LAYER_ADJUST
  .--------------------------------------------------------------------------------------------------------------------------------------.
  | XXXXXX | HELP 1 | HELP 2 | HELP 3 | HELP 4 | HELP 5 | HELP 6 | HELP 7 | HELP 8 | HELP 9 | XXXXXX | MUSIC  | AUDIO  | XXXXXX . XXXXXX |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | XXXXXX | BRTOG  | BRSPD+ | BRSPD- | BRDFLT | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX . XXXXXX | XXXXXX |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | XXXXXX | QWERTY | XXXXXX | XXXXXX | BACKLT | RESET  | XXXXXX | MOUSE  | XXXXXX | XXXXXX | XXXXXX | XXXXXX . XXXXXX | VOICE+ | XXXXXX |
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  | XXXXXX | XXXXXX | XXXXXX | XXXXXX | UPPER  | XXXXXX . XXXXXX | LOWER  | XXXXXX | XXXXXX | XXXXXX | XXXXXX | TEMPO- | VOICE- | TEMPO+ |
  '--------------------------------------------------------------------------------------------------------------------------------------'
*/
[LAYER_ADJUST] = {
  { XXXXXXX, M_HELP1, M_HELP2, M_HELP3, M_HELP4, M_HELP5, M_HELP6, M_HELP7, M_HELP8, M_HELP9, XXXXXXX, MU_TOG , AU_TOG , XXXXXXX, XXXXXXX },
  { XXXXXXX, M_HELP1, M_HELP2, M_HELP3, M_HELP4, M_HELP5, M_HELP6, M_HELP7, M_HELP8, M_HELP9, XXXXXXX, MU_TOG , AU_TOG , XXXXXXX, XXXXXXX },
  { XXXXXXX, M_BRTOG, M_BSPDU, M_BSPDD, M_BDFLT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  { XXXXXXX, M_QWRTY, XXXXXXX, XXXXXXX, M_BACKL, RESET  , XXXXXXX, XXXXXXX, M_MOUSE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX },
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M_UPPER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M_LOWER,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX }
},
};


void persistant_default_layer_set(uint16_t default_layer)
{
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_ONESHOT(MOD_LSFT),
};

static uint16_t key_timer;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{

    // MACRODOWN only works in this function
    switch(id)
    {

        case HYPER_COPY:
            if (record->event.pressed) {
                key_timer = timer_read(); // if the key is being pressed, we start the timer.
            }
            else { // this means the key was just released, so we can figure out how long it was pressed for (tap or "held down").
                if (timer_elapsed(key_timer) > 150) { // 150 being 150ms, the threshhold we pick for counting something as a tap.
                    return MACRO( D(LCTL), T(C), U(LCTL), END  );
                }
                else {
                    return MACRO( D(LCTL), T(V), U(LCTL), END  );
                }
            }
            break;

        case MACRO_HELP_1:
            if (record->event.pressed)
            {
        uprintf("1");
            }
            break;

        case MACRO_HELP_2:
            if (record->event.pressed)
            {
        uprintf("2");
            }
            break;

        case MACRO_HELP_3:
            if (record->event.pressed)
            {
        uprintf("3");
            }
            break;

        case MACRO_HELP_4:
            if (record->event.pressed)
            {
        uprintf("4");
            }
            break;

        case MACRO_HELP_5:
            if (record->event.pressed)
            {
        uprintf("5");
            }
            break;

        case MACRO_HELP_6:
            if (record->event.pressed)
            {
        uprintf("6");
            }
            break;

        case MACRO_HELP_7:
            if (record->event.pressed)
            {
        uprintf("7");
            }
            break;

        case MACRO_HELP_8:
            if (record->event.pressed)
            {
        uprintf("8");
            }
            break;

        case MACRO_HELP_9:
            if (record->event.pressed)
            {
        uprintf("9");
            }
            break;

        case MACRO_BREATH_TOGGLE:
            if (record->event.pressed)
            {
                breathing_toggle();
            }
            break;

        case MACRO_BREATH_SPEED_INC:
            if (record->event.pressed)
            {
                breathing_speed_inc(1);
            }
            break;

        case MACRO_BREATH_SPEED_DEC:
            if (record->event.pressed)
            {
                breathing_speed_dec(1);
            }
            break;

        case MACRO_BREATH_DEFAULT:
            if (record->event.pressed)
            {
                breathing_defaults();
            }
            break;

        case MACRO_QWERTY:
            if (record->event.pressed)
            {
                persistant_default_layer_set(1UL<<LAYER_QWERTY);
            }
            break;

        case MACRO_UPPER:
            if (record->event.pressed)
            {
                layer_on(LAYER_UPPER);
                breathing_speed_set(2);
                breathing_pulse();
                update_tri_layer(LAYER_LOWER, LAYER_UPPER, LAYER_ADJUST);
            }
            else
            {
                layer_off(LAYER_UPPER);
                update_tri_layer(LAYER_LOWER, LAYER_UPPER, LAYER_ADJUST);
            }
            break;

        case MACRO_LOWER:
            if (record->event.pressed)
            {
                layer_on(LAYER_LOWER);
                breathing_speed_set(2);
                breathing_pulse();
                update_tri_layer(LAYER_LOWER, LAYER_UPPER, LAYER_ADJUST);
            }
            else
            {
                layer_off(LAYER_LOWER);
                update_tri_layer(LAYER_LOWER, LAYER_UPPER, LAYER_ADJUST);
            }
            break;

        case MACRO_FUNCTION:
            if (record->event.pressed)
            {
                breathing_speed_set(3);
                breathing_enable();
                layer_on(LAYER_FUNCTION);
            }
            else
            {
                breathing_speed_set(1);
                breathing_self_disable();
                layer_off(LAYER_FUNCTION);
            }
            break;

#ifdef MOUSEKEY_ENABLE

        case MACRO_MOUSE:
            if (record->event.pressed)
            {
                layer_invert(LAYER_MOUSE);
            }
            break;

#endif /* MOUSEKEY_ENABLE */

#ifdef BACKLIGHT_ENABLE
        case MACRO_BACKLIGHT:
            if (record->event.pressed)
            {
                backlight_step();
            }
#endif

        default:
            break;

    }
    return MACRO_NONE;
};
