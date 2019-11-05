# qwerty keymap for CRKBD

To flash the halves use:

```bash
# left side
make crkbd:leshowmapmatrix:dfu-split-left

# right side, with RGB matrix fix
make crkbd:leshowmapmatrix:dfu-split-right RGB_MATRIX_SPLIT_RIGHT=yes
```
