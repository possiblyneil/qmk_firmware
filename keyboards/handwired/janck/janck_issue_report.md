# Janck Keyboard Hardware issue
##  Description Of Issue:
Columns of keys do not work after the third column
Rows of keys do work in columns 0,1,2

## Board Description
This keyboard is handwired with diodes present in the rows
The chosen microcontroler is the Arduino Pro Micro
The default layout is that of the Planck following the guide
https://beta.docs.qmk.fm/using-qmk/guides/keyboard-building/hand_wire
Code for the board can be found at 
https://github.com/possiblyneil/qmk_firmware/tree/master/keyboards/handwired/janck

##  Hardware checks:
### Microcontroler
- The defined pins were shorted together for each row and column with a keyboard tester active and it looks like the defined pins produce keypressess on all rows and columns 
![Keyboard tester results](https://i.imgur.com/0oSOgxf.png)
    ```
*** HID console connected: possiblyneil janck (DEAD:BEEF:0001)
KL: col: 0, row: 0, pressed: 1
KL: col: 0, row: 1, pressed: 1
KL: col: 0, row: 2, pressed: 1
KL: col: 0, row: 3, pressed: 1
KL: col: 1, row: 0, pressed: 1
KL: col: 1, row: 1, pressed: 1
KL: col: 1, row: 2, pressed: 1
KL: col: 1, row: 3, pressed: 1
KL: col: 10, row: 0, pressed: 1
KL: col: 10, row: 1, pressed: 1
KL: col: 10, row: 2, pressed: 1
KL: col: 10, row: 3, pressed: 1
KL: col: 11, row: 0, pressed: 1
KL: col: 11, row: 1, pressed: 1
KL: col: 11, row: 2, pressed: 1
KL: col: 11, row: 3, pressed: 1
KL: col: 2, row: 0, pressed: 1
KL: col: 2, row: 1, pressed: 1
KL: col: 2, row: 2, pressed: 1
KL: col: 2, row: 3, pressed: 1
KL: col: 3, row: 0, pressed: 1
KL: col: 3, row: 1, pressed: 1
KL: col: 3, row: 2, pressed: 1
KL: col: 3, row: 3, pressed: 1
KL: col: 4, row: 0, pressed: 1
KL: col: 4, row: 1, pressed: 1
KL: col: 4, row: 2, pressed: 1
KL: col: 4, row: 3, pressed: 1
KL: col: 5, row: 0, pressed: 1
KL: col: 5, row: 1, pressed: 1
KL: col: 5, row: 2, pressed: 1
KL: col: 5, row: 3, pressed: 1
KL: col: 6, row: 0, pressed: 1
KL: col: 6, row: 1, pressed: 1
KL: col: 6, row: 2, pressed: 1
KL: col: 6, row: 3, pressed: 1
KL: col: 7, row: 0, pressed: 1
KL: col: 7, row: 1, pressed: 1
KL: col: 7, row: 2, pressed: 1
KL: col: 7, row: 3, pressed: 1
KL: col: 8, row: 0, pressed: 1
KL: col: 8, row: 1, pressed: 1
KL: col: 8, row: 2, pressed: 1
KL: col: 8, row: 3, pressed: 1
KL: col: 9, row: 0, pressed: 1
KL: col: 9, row: 1, pressed: 1
KL: col: 9, row: 2, pressed: 1
KL: col: 9, row: 3, pressed: 1
keyboard_report: 00 00 00 04 00 00 00 00 
keyboard_report: 00 00 00 07 00 00 00 00 
keyboard_report: 00 00 00 09 00 00 00 00 
keyboard_report: 00 00 00 16 00 00 00 00 
keyboard_report: 00 00 00 29 00 00 00 00 
keyboard_report: 00 00 00 34 00 00 00 00 
keyboard_report: 00 00 04 00 00 00 00 00 
keyboard_report: 00 00 05 00 00 00 00 00 
keyboard_report: 00 00 06 00 00 00 00 00 
keyboard_report: 00 00 07 16 00 00 00 00 
keyboard_report: 00 00 08 00 00 00 00 00 
keyboard_report: 00 00 09 00 00 00 00 00 
keyboard_report: 00 00 0A 00 00 00 00 00 
keyboard_report: 00 00 0B 00 00 00 00 00 
keyboard_report: 00 00 0C 00 00 00 00 00 
keyboard_report: 00 00 0D 00 00 00 00 00 
keyboard_report: 00 00 0E 00 00 00 00 00 
keyboard_report: 00 00 0F 12 00 00 00 00 
keyboard_report: 00 00 10 00 00 00 00 00 
keyboard_report: 00 00 11 00 00 00 00 00 
keyboard_report: 00 00 12 00 00 00 00 00 
keyboard_report: 00 00 13 00 00 00 00 00 
keyboard_report: 00 00 14 00 00 00 00 00 
keyboard_report: 00 00 14 00 00 00 00 00 
keyboard_report: 00 00 14 04 00 00 00 00 
keyboard_report: 00 00 14 04 00 00 00 00 
keyboard_report: 00 00 15 00 00 00 00 00 
keyboard_report: 00 00 15 09 00 00 00 00 
keyboard_report: 00 00 16 00 00 00 00 00 
keyboard_report: 00 00 17 00 00 00 00 00 
keyboard_report: 00 00 18 00 00 00 00 00 
keyboard_report: 00 00 18 00 00 00 00 00 
keyboard_report: 00 00 19 00 00 00 00 00 
keyboard_report: 00 00 1A 00 00 00 00 00 
keyboard_report: 00 00 1A 16 00 00 00 00 
keyboard_report: 00 00 1B 00 00 00 00 00 
keyboard_report: 00 00 1C 00 00 00 00 00 
keyboard_report: 00 00 1D 00 00 00 00 00 
keyboard_report: 00 00 28 00 00 00 00 00 
keyboard_report: 00 00 29 00 00 00 00 00 
keyboard_report: 00 00 2A 00 00 00 00 00 
keyboard_report: 00 00 2A 34 00 00 00 00 
keyboard_report: 00 00 2B 00 00 00 00 00 
keyboard_report: 00 00 2B 29 00 00 00 00 
keyboard_report: 00 00 2C 00 00 00 00 00 
keyboard_report: 00 00 33 00 00 00 00 00 
keyboard_report: 00 00 33 13 00 00 00 00 
keyboard_report: 00 00 36 00 00 00 00 00 
keyboard_report: 00 00 37 00 00 00 00 00 
keyboard_report: 00 00 38 00 00 00 00 00 
keyboard_report: 00 00 4F 00 00 00 00 00 
keyboard_report: 00 00 50 00 00 00 00 00 
keyboard_report: 00 00 51 00 00 00 00 00 
keyboard_report: 00 00 52 00 00 00 00 00 
keyboard_report: 01 00 00 00 00 00 00 00 
keyboard_report: 02 00 00 00 00 00 00 00 
keyboard_report: 04 00 00 00 00 00 00 00 
keyboard_report: 08 00 00 00 00 00 00 00 
    ```
### Diodes
- All of the diodes were checked for functionality using a multimeter with the diode function
### Switches
- All of the switches were tested for functionality with a multimeter by measureing the resistance of the switch open vs closed
### Wiring
- Continuity of the colums was checked using a multimeter with the resistance setting from the following configurations on all columns:
    * From actual column wire to the wire connecting to the microcontroler
    * From the ends of the wire connecting the column to the microcontroler

##  Software checks:
- Details of the pinouts chosen for the Pro Micro
    ```
#define MATRIX_ROW_PINS { D1, D0, D4, C6 }
#define MATRIX_COL_PINS { B5, B4, E6, D7, B6, B2, B3, B1, F7, F6, F5, F4 }
    ```
- Console and debug enabled in firmware, viewed in QMK toolbox
    * There is nada from column 3 (zero indexed) when keys are pressed. For 0,1,2 things look fine:
    ```
*** HID console connected: possiblyneil janck (DEAD:BEEF:0001)
KL: col: 0, row: 0, pressed: 1
KL: col: 0, row: 1, pressed: 1
KL: col: 0, row: 2, pressed: 1
KL: col: 0, row: 3, pressed: 1
KL: col: 1, row: 0, pressed: 1
KL: col: 1, row: 1, pressed: 1
KL: col: 1, row: 2, pressed: 1
KL: col: 1, row: 3, pressed: 1
KL: col: 2, row: 0, pressed: 1
KL: col: 2, row: 1, pressed: 1
KL: col: 2, row: 2, pressed: 1
KL: col: 2, row: 3, pressed: 1
keyboard_report: 00 00 00 00 00 00 00 00 
keyboard_report: 00 00 04 00 00 00 00 00 
keyboard_report: 00 00 14 00 00 00 00 00 
keyboard_report: 00 00 16 00 00 00 00 00 
keyboard_report: 00 00 1A 00 00 00 00 00 
keyboard_report: 00 00 1B 00 00 00 00 00 
keyboard_report: 00 00 1D 00 00 00 00 00 
keyboard_report: 00 00 29 00 00 00 00 00 
keyboard_report: 00 00 2B 00 00 00 00 00 
keyboard_report: 01 00 00 00 00 00 00 00 
keyboard_report: 02 00 00 00 00 00 00 00 
keyboard_report: 04 00 00 00 00 00 00 00 
    ```
