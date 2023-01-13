# BMK-20

![bmk-20](http://)

The BMK-20 (rev 1 is labelled BMK-16 because I somehow can't count) is a 20 switch macropad that is convertible into a 17 key numpad.  It sports an FR4 sandwich case with open sides.  Either SMD or THT diodes may be used.  The BMK-20 requires a pro micro (or compatible) to be soldered as the MCU.  Optionally an SSD1306 may also be mounted on the board, though I haven't figured out why you would yet want this.  Switches are south facing.  Only PCB mount stabilizers are compatible (numpad configuration only).  One of the switches may be replaced with an EC11 rotary encoder.

Keyboard Maintainer: [Brad Arnett](https://github.com/daed)  

Hardware:

- MCU:  Pro Micro (or compatible)
- LCD:  SSD1306
- Diodes:  17-20 (SMD or THT)
- Switches: 17-20 (5-pin 'pcb' mount accepted)
- Stabilizers:  PCB mount (if using as numpad)
- Encoder:  EC11 (optional)

Make example for this keyboard (after setting up your build environment):

    make bmk_20:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
