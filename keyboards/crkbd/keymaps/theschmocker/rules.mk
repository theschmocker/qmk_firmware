BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite
TAP_DANCE_ENABLE = no
COMBO_ENABLE = yes

DEBOUNCE_TYPE = sym_defer_pk

#Debug options
VERBOSE                = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX           = no
CONSOLE_ENABLE         = no

#Combos!
VPATH                  +=  keyboards/gboards/

ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif