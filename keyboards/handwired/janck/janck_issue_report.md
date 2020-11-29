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
TODO: Recheck
### Microcontroler
- The defined pins were shorted together for each row and column with a keyboard tester active and it looks like the defined pins produce keypressess on all rows and columns 
    TODO: Picture of keyboard tester
    TODO: Log of debug output for shorting all of the rows and columns
TODO: Recheck
### Diodes
- All of the diodes were checked for functionality using a multimeter with the diode function
TODO: Recheck
### Switches
- All of the switches were tested for functionality with a multimeter by measureing the resistance of the switch open vs closed
TODO: Recheck
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
    TODO: Recheck
    * There is nada from column 3 (zero indexed) when keys are pressed. For 0,1,2 things look fine:
    ```
*** HID console connected: possiblyneil janck (DEAD:BEEF:0001)
  > KL: kc: 43, col: 0, row: 0, pressed: 1
    keyboard_report: 00 00 2B 00 00 00 00 00 
  > KL: kc: 43, col: 0, row: 0, pressed: 0
    keyboard_report: 00 00 00 00 00 00 00 00 
  > KL: kc: 43, col: 0, row: 0, pressed: 1
    keyboard_report: 00 00 2B 00 00 00 00 00 
  > KL: kc: 43, col: 0, row: 0, pressed: 0
    keyboard_report: 00 00 00 00 00 00 00 00 
  > KL: kc: 43, col: 0, row: 0, pressed: 1
    keyboard_report: 00 00 2B 00 00 00 00 00 
  > KL: kc: 43, col: 0, row: 0, pressed: 0
    keyboard_report: 00 00 00 00 00 00 00 00 
  > KL: kc: 43, col: 0, row: 0, pressed: 1
    keyboard_report: 00 00 2B 00 00 00 00 00 
  > KL: kc: 43, col: 0, row: 0, pressed: 0
    keyboard_report: 00 00 00 00 00 00 00 00 
  > KL: kc: 20, col: 1, row: 0, pressed: 1
    keyboard_report: 00 00 14 00 00 00 00 00 
  > KL: kc: 20, col: 1, row: 0, pressed: 0
    keyboard_report: 00 00 00 00 00 00 00 00 
  > KL: kc: 20, col: 1, row: 0, pressed: 1
    keyboard_report: 00 00 14 00 00 00 00 00 
  > KL: kc: 20, col: 1, row: 0, pressed: 0
    keyboard_report: 00 00 00 00 00 00 00 00 
  > KL: kc: 26, col: 2, row: 0, pressed: 1
    keyboard_report: 00 00 1A 00 00 00 00 00 
  > KL: kc: 26, col: 2, row: 0, pressed: 0
    keyboard_report: 00 00 00 00 00 00 00 00 
  > KL: kc: 22, col: 2, row: 1, pressed: 1
    keyboard_report: 00 00 16 00 00 00 00 00 
  > KL: kc: 22, col: 2, row: 1, pressed: 0
    keyboard_report: 00 00 00 00 00 00 00 00 
  > KL: kc: 27, col: 2, row: 2, pressed: 1
    keyboard_report: 00 00 1B 00 00 00 00 00 
  > KL: kc: 27, col: 2, row: 2, pressed: 0
    keyboard_report: 00 00 00 00 00 00 00 00 
  > KL: kc: 29, col: 1, row: 2, pressed: 1
    keyboard_report: 00 00 1D 00 00 00 00 00 
  > KL: kc: 29, col: 1, row: 2, pressed: 0
    keyboard_report: 00 00 00 00 00 00 00 00 
    ```
