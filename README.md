Dice2
=====

Small Arduino project for yet another electronic dice, this one using a 
capacitive input.

This project was created to support a kids project and was aimed to
build an electronic die which is both easy to build, as well as cheap.

To build the project, the following components are needed:

```
    1x ATTiny44A  
    7x LED (not white or blue due to voltage requirements)  
    7x Resistor approx 160 Ohm  
    1x Resistor 1M Ohm  
    1x 2 AAA battery holder  
    1x touch pad (foil, unetched PCB, nail, push-pin, whatever conducts ;-) )  
```

Dependencies
------------
To build this project, you will need the following libraries/extensions:
- Capacitive sensing library: 
     http://playground.arduino.cc//Main/CapacitiveSensor?from=Main.CapSense
- If you want to target the ATTiny, the ATTiny cores from 
     http://code.google.com/p/arduino-tiny/

Follow the installation instructions that come with these to add the libraries
and cores to your Arduino development environment. If you are using a stock Arduino 
board, pick your pins for the CapacitiveSensor and LEDs, change the assignments in
the code and build your project

Pinout on ATTiny44
------------------
The ATTiny cores use the following pin assignments:
```
                           +-\/-+  
                     VCC  1|    |14  GND  
             (D  0)  PB0  2|    |13  AREF (D 10)  
             (D  1)  PB1  3|    |12  PA1  (D  9)   
                     PB3  4|    |11  PA2  (D  8)   
  PWM  INT0  (D  2)  PB2  5|    |10  PA3  (D  7)   
  PWM        (D  3)  PA7  6|    |9   PA4  (D  6)   
  PWM        (D  4)  PA6  7|    |8   PA5  (D  5)        PWM  
                           +----+
```

Connect the 1M Ohm resistor between pin5 (D2) and pin6 (D3). The touch pad 
connects to pin6 (D3). When running on batteries, you need a second pad 
connected to GND due to the lack of proper grounding.

The 4 die 'segments' connect to pins 8 (D5), 9 (D6), 10 (D7) and 11 (D8).

The segments form the eyes on the die as following:

     D6 .. D7  
     D8 D5 D8  
     D7 .. D6  


Plans
-----
- [ ] Add the eagle schematic file
- [ ] Add pictures of projects finished by kids
- [ ] Design a nice casing which can be lasercut (incl. a PCB to fit inside)
