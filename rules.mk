# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
CAPS_WORD_ENABLE = yes
SPACE_CADET_ENABLE = yes

KEY_OVERRIDE_ENABLE = yes
MOUSEKEY_ENABLE = yes
WPM_ENABLE = yes

# DYNAMIC_TAPPING_TERM_ENABLE = yes
# COMBO_ENABLE = yes
# TAP_DANCE_ENABLE = yes

## for RP2040 only
# OS_DETECTION_ENABLE = yes
# VIA_ENABLE = yes
# CONSOLE_ENABLE = yes

## for keyboards with LEDs+OLED, e.g. the crkbd
# RGB_MATRIX_ENABLE = yes
# OLED_ENABLE     = yes
OLED_DRIVER     = ssd1306
# BOOTLOADER = caterina
RGBLIGHT_ENABLE = no # FIXME does this break something?

# squeeze firmware size: https://github.com/qmk/qmk_firmware/blob/master/docs/squeezing_avr.md
LTO_ENABLE = yes
COMMAND_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
# BOOTMAGIC_ENABLE = no

