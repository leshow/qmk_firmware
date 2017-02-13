To flash `r2d2rogers` with my modifications to the visualizer follow these steps:

make sure you're on branch `r2d2rogers`
```bash
# cd to qmk_firmware/keyboards/ergodox/
sudo make clean;
sudo make dfu-util KEYBOARD=ergodox SUBPROJECT=infinity KEYMAP=r2d2rogers VISUALIZER_ENABLE=yes MASTER=left;

sudo make clean;
sudo make dfu-util KEYBOARD=ergodox SUBPROJECT=infinity KEYMAP=r2d2rogers VISUALIZER_ENABLE=yes MASTER=right;

```
