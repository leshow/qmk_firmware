
# If you want to change the display of OLED, you need to change here
SRC += ./logo_reader.c

# enable OLED displays
OLED_DRIVER_ENABLE = yes

# enable media keys
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes        # Mouse keys(+4700)
NKRO_ENABLE      = yes # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# enable LEDs
RGB_MATRIX_ENABLE = WS2812

# using elite-c controllers
BOOTLOADER = qmk-dfu
