/*
Copyright 2017 Fred Sundvik
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

#include "simple_visualizer.h"

#define IS_LAYER_ACTIVE(state, layer) (state & (1UL << (layer)))
// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t *state)
{
    uint8_t saturation = 60;
    if (state->status.leds & (1u << USB_LED_CAPS_LOCK))
    {
        saturation = 255;
    }
    if (IS_LAYER_ACTIVE(state->status.layer, 4))
    {
        state->target_lcd_color = LCD_COLOR(192, saturation, 0xFF);
        state->layer_text = "Media";
    }
    else if (IS_LAYER_ACTIVE(state->status.layer, 3))
    {
        state->target_lcd_color = LCD_COLOR(96, saturation, 0xFF);
        state->layer_text = "Arrow";
    }
    else if (IS_LAYER_ACTIVE(state->status.layer, 2))
    {
        state->target_lcd_color = LCD_COLOR(16, saturation, 0xFF);
        state->layer_text = "Num & Mouse";
    }
    else if (IS_LAYER_ACTIVE(state->status.layer, 1))
    {
        state->target_lcd_color = LCD_COLOR(168, saturation, 0xFF);
        state->layer_text = "Symbol";
    }
    else
    {
        state->target_lcd_color = LCD_COLOR(84, saturation, 0xFF);
        state->layer_text = "Default";
    }
}