#!/bin/sh
qmk json2c praxis-win.json > praxis.c
qmk compile -kb crkbd -km praxis
# qmk compile -kb beekeeb/piantor -km praxis

