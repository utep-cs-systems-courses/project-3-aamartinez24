# Project 3 LCDTOY
## Introduction

Using the knowledge of the previous lab, this project uses the MSP430 and the
LCD attachment to make a fun simple toy.

## Run the program

 First use:
 "make" on the main directory to install all necessary files and libraries.

 Next got to the project dircetory where all the LCD toy files are located.

 Finally use:
 "make load" to load and run the program in the MSP430 (should be connected}

 Extra:
 Type "make clean" to clean are unnecessary files.
 Type "mspdebug rf2500 "erase"" to erase any program currently installed in
 the MSP430.

## Functionality

   Before pressing the button you will be greeted with a black text reading
   "Hello Human"

   SW1:
	pressing the first button will display a yellow illuminati triangle
	with its eye blinking.

   SW2:
	Will display a black and blue illuminati symbol with the red led
	turning on and off.

   SW3:
	Will display a black and white illuminati symbol with the red led
	dimming.

   SW4:
	Finally, the last button will display a black illuminait symbol with a
	designed red background.
