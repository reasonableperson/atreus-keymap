#include QMK_KEYBOARD_H

// Macros to simplify the layout of this file; allows for keys on the left and
// right hands to be defined separately rather than interleaved.
#define ___ _______
#define LR_LAYOUT( \
    k01, k02, k03, k04, k05,   k06, k07, k08, k09, k10,         \
    k11, k12, k13, k14, k15,   k16, k17, k18, k19, k20, k21,    \
    k22, k23, k24, k25, k26,        k27, k28, k29, k30, k31,    \
    k32, k33, k34, k35, k36,   k37, k38, k39, k40, k41, k42) {  \
  { k01, k02, k03, k04, k05, KC_NO, k22, k23, k24, k25, k26  }, \
  { k06, k07, k08, k09, k10, KC_NO, k27, k28, k29, k30, k31  }, \
  { k11, k12, k13, k14, k15, k21,   k32, k33, k34, k35, k36, }, \
  { k16, k17, k18, k19, k20, k37,   k38, k39, k40, k41, k42  }}

// Layer names.
#define _BASE  0
#define _HOLD  1
#define _LEFT  2
#define _RIGHT 3

// Sticky thumb keys.
 #define L   OSL(_LEFT)    //  left thumb inner
#define R   OSL(_RIGHT)   // right thumb inner
#define CTL OSM(MOD_LCTL) //  left thumb outer
#define SFT OSM(MOD_LSFT) // right thumb outer

// Multi-purpose (layer tap and mod tap) keys.
#define SPC LT(_HOLD, KC_SPC)     //  left thumb
#define SHZ MT(MOD_LSFT, KC_Z)    //  left pinky
#define ESC MT(MOD_LALT, KC_ESC)  //  left pinky
#define SHS MT(MOD_LSFT, KC_SLSH) // right pinky
#define RET MT(MOD_LGUI, KC_ENT)  // right pinky

// Special keys for entering Unicode characters on Windows and Linux
#define CMP KC_RGUI              // Compose on Linux, Windows on Windows
#define ALT LM(_RIGHT, MOD_LALT) // For entering Alt codes on Windows

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ,---+---+---+---+---. */ [_BASE] = LR_LAYOUT(
/* | q | w | f | p | g | */     KC_Q,  KC_W, KC_F, KC_P, KC_G,
/* +---+---+---+---+---+ */    
/* | a | r | s | t | d | */     KC_A,  KC_R, KC_S, KC_T, KC_D,
/* +---+---+---+---+---+ */    
/* |+z+| x | c | v | b | */     SHZ,   KC_X, KC_C, KC_V, KC_B,
/* +---+---+---+---+---+---. */
/* |Esc|Tab|Cmp|Ctl|Spc| L | */ ESC, KC_TAB,  CMP,  CTL,  SPC,  L,
/* `---+---+---+---+---+---' */
                                                  /* ,-------------------. */
     KC_J,   KC_L, KC_U,    KC_Y,    KC_BSPC,     /* | j | l | u | y | ⌫ | */
                                                  /* +---+---+---+---+---+ */
     KC_H,   KC_N, KC_E,    KC_I,    KC_O,        /* | h | n | e | i | o | */
                                                  /* +---+---+---+---+---+ */
     KC_K,   KC_M, KC_COMM, KC_DOT,  SHS,         /* | k | m | , | . |+/+| */
                                              /* ,---+---+---+---+---+---+ */
 R,  KC_SPC, SFT,  KC_MINS, KC_QUOT, RET),    /* | R |Spc|Shf| - | ' |Ent| */
                                              /* `---+---+---+---+---+---+ */

/* ,-------------------.  */ [_HOLD] = LR_LAYOUT(
/* | ` |Hom| ↑ |End|Win|  */   KC_GRV, KC_HOME, KC_UP,   KC_END,  KC_WWW_HOME,
/* |---+---+---+---+---+  */
/* |Ctl| ← | ↓ | → |Vo↑|  */      CTL, KC_LEFT, KC_DOWN, KC_RGHT,     KC_VOLU,
/* |---+---+---+---+---+  */
/* |Shf|Del|Uni| ` |Pst|  */      SFT,  KC_DEL, ALT,     KC_GRV, LSFT(KC_INS),
/* |---+---+---+---+---+---. */
/* |   |   |   |   | ◆ |   | */   ___,     ___, ___,     ___,    ___,     ___,
/* `---+---+---+---+---+---' */
                                                  /* ,-------------------. */
     KC_INS,  KC_7, KC_8, KC_9,   KC_MINS,        /* |Ins| 7 | 8 | 9 | - | */
                                                  /* +---+---+---+---+---+ */
     KC_PGUP, KC_4, KC_5, KC_6,   KC_PLUS,        /* |PgU| 4 | 5 | 6 | + | */
                                                  /* +---+---+---+---+---+ */
     KC_PGDN, KC_1, KC_2, KC_3,   KC_BSLS,        /* |PgD| 1 | 2 | 3 | \ | */
                                              /* ,---+---+---+---+---+---+ */
___, SFT,  KC_COMM, KC_0, KC_DOT, KC_EQL),    /* |   |Shf| , | 0 | . | = | */
                                              /* `---+---+---+---+---+---+ */

/* ,-------------------. */ 
/* | q | ⬁ | ⇧ | ⬀ |Spl| */ 
/* |---+---+---+---+---+ */ 
/* |Ctl| ⇦ | ⇩ | ⇨ |Con| */ 
/* |---+---+---+---+---+ */ 
/* |Shf|Kil| c |Flt|Max| */ 
/* |---+---+---+---+---+---. */ 
/* |Esc|Tab| f |Ctl|TTY| ◆ | */ 
/* `-----------------------' */ 

    /* ,-------------------. */
    /* | j | l | u | y | ⌫ | */
    /* +---+---+---+---+---| */
    /* | h | ⌫ | e | i | o | */
    /* +---+---+---+---+---| */
    /* | k | m | , | . | / | */
/* ,---+---+---+---+---+---+ */
/* |Rof|TTY|Shf| - | ' |Nau| */
/* `-----------------------' */


[_LEFT] = LAYOUT(
  G(KC_Q), C(S(KC_TAB)), G(KC_UP), C(KC_TAB), G(KC_G),
    G(KC_J), G(KC_L), G(KC_U), G(KC_Y), KC_BSPC,

  CTL, G(KC_LEFT), G(KC_DOWN), G(KC_RIGHT), G(KC_D),
    G(KC_H), KC_BSPC, G(KC_E), G(KC_I), G(KC_O),

  SFT, G(KC_X), G(KC_C), G(KC_V), G(KC_B),
    G(KC_K), G(KC_M), G(KC_COMM), G(KC_DOT), G(KC_SLSH),

  G(KC_ESC), G(KC_TAB), G(KC_F), ___, G(KC_SPC), ___, G(KC_ESC),
    G(KC_SPC), ___, G(KC_MINUS), G(KC_QUOT), G(KC_ENT)),

/* ,-------------------. */      
/* |F1 |F2 |F3 |F4 |PSc| */      
/* |---+---+---+---+---+ */      
/* |F5 |F6 |F7 |F8 |BSp| */      
/* |---+---+---+---+---+ */      
/* |F9 |F10|F11|F12|   | */      
/* |---+---+---+---+---+---. */  
/* |   |   |   |   |   |   | */  
/* `-----------------------' */  

    /* ,-------------------. */
    /* | ⇡ | { | } | ; |Rst| */
    /* +---+---+---+---+---| */
    /* | ⇣ | ( | ) | : | | | */
    /* +---+---+---+---+---| */
    /* |Mut| [ | ] | + | \ | */
/* ,---+---+---+---+---+---+ */
/* |   |   |   |   |   |   | */
/* `-----------------------' */

 [_RIGHT] = LAYOUT(
  KC_F1, KC_F2,  KC_F3, KC_F4, KC_PSCR,
    KC_VOLU, S(KC_LBRC), S(KC_RBRC), KC_SCLN, RESET,

  KC_F5, KC_F6,  KC_F7, KC_F8, KC_BSPC,
    KC_VOLD, S(KC_9), S(KC_0), S(KC_SCLN), S(KC_BSLS),

  KC_F9, KC_F10, KC_F11, KC_F12, ___,
    KC_MUTE, KC_LBRC, KC_RBRC, S(KC_EQL), KC_BSLS,

  ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___)

};
