# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
CAPS_WORD_ENABLE = yes

KEY_OVERRIDE_ENABLE = yes
MOUSEKEY_ENABLE = yes
WPM_ENABLE = yes

# DYNAMIC_TAPPING_TERM_ENABLE = yes
# COMBO_ENABLE = yes
# TAP_DANCE_ENABLE = yes


## for keyboards with LEDs+OLED, e.g. the crkbd
RGB_MATRIX_ENABLE = yes
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes
# BOOTLOADER = caterina


# squeeze firmware size: https://github.com/qmk/qmk_firmware/blob/master/docs/squeezing_avr.md
# CONSOLE_ENABLE = no
# COMMAND_ENABLE = no
# EXTRAKEY_ENABLE = no
# AVR_USE_MINIMAL_PRINTF = yes

