## praxis

a QWERTY-based [qmk](https://qmk.fm) keyboard layout for 3x6_3 split keyboards

### features

* home row mods ([CAGS](git@github.com:kevinstadler/praxis.git), ideal for MacOS)
* togglable single-hand layer (with arrow keys and modifiers geared towards working in 3D editing software, where the right hand is on the mouse)

### how to use

clone this repository into the `keymaps` subdirectory of your 3x6_3 keyboard, then:

```
cd your_qmk_directory/keyboards/your_keyboard/keymaps
git clone git@github.com:kevinstadler/praxis.git

qmk config user.keymap=praxis

# compile for your keyboard
qmk compile -kb crkbd/rev1
qmk compile -kb beekeeb/piantor
...
```

### TODOs

* [ ] sort out modifier + arrow navigation (e.g. GUI+up/down)

