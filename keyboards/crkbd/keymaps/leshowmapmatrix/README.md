# qwerty keymap for CRKBD

To flash the halves use:

```bash
# left side
make crkbd:leshowmapmatrix:dfu-split-left

# right side, with RGB matrix fix
make crkbd:leshowmapmatrix:dfu-split-right RGB_MATRIX_SPLIT_RIGHT=yes
```

or

(show avr)

```bash
./util/docker_build.sh crkbd:leshowmapmatrix:avrdude-split-left

RGB_MATRIX_SPLIT_RIGHT=yes ./util/docker_build.sh crkbd:leshowmapmatrix
```

⚠ Missing or outdated udev rules for 'at32-dfu' boards. Run 'sudo cp /home/leshow/dev/ergo/qmk_latest/util/udev/50-qmk.rules /etc/udev/rules.d/'.
