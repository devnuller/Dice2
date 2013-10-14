/*
 * Dice2 - Simple dice game
 *
 * Roll a single die with a capacitive touch sensor as input
 */

#include <CapacitiveSensor.h>

// enable capacitive sensing, use a button to ground (on SENSOR pin) otherwise
#define CAPACITIVE
 
#define SENSOR           1
#define SENSOR_THRESHOLD 100
#define DICE_SECTIONS    4

/*
 * Dice eyes (LED's) must be connected to the following pins to get
 * the correct patterns displayed:
 *
 *    6 . 7 
 *    8 5 8
 *    7   6
 */
byte dice_pins[DICE_SECTIONS] = { 5,6,7,8 };

boolean dice_map[7][DICE_SECTIONS] = {
  { true,  false, false, false }, // ONE
  { false, true,  false, false }, // TWO
  { true,  true,  false, false }, // THREE
  { false, true,  true,  false }, // FOUR
  { true,  true,  true,  false }, // FIVE
  { false, true,  true,  true  }, // SIX
  { false, false, false, false }  // OFF
};

#define DISPLAY_OFF  6

boolean randomized = false;

#ifdef CAPACITIVE
CapacitiveSensor touch(2,3);
#endif


void display_pattern ( byte pattern )
{
  byte index;
  
  for ( index=0; index < DICE_SECTIONS; index++ ) {
    digitalWrite(dice_pins[index], ( dice_map[pattern][index] ? HIGH : LOW ) );
  }
}


void setup()
{
  byte index;
  
  for (index=0;index<DICE_SECTIONS;index++) {
    pinMode(dice_pins[index],OUTPUT);
    digitalWrite(dice_pins[index],LOW);
  }
  
#ifndef CAPACITIVE
  digitalWrite(SENSOR,HIGH); // enable internal pull-up
#endif
}


void loop()
{
#ifdef CAPACITIVE
  // only trigger if we have 3 consecutive readings
  while ( touch.capacitiveSensor(30) < SENSOR_THRESHOLD );
#else
  // wait for button to be pushed
  while(digitalRead(SENSOR) == HIGH);
  delay(10); // simpel debounce
  while(digitalRead(SENSOR) == HIGH); // simple debounce
 #endif
 
  // First touch initializes the randon generator, since the
  // moment the user first touches the button is quite random
  if ( ! randomized ) {
    randomSeed(micros());
    randomized=true;
  }
  
  display_pattern(DISPLAY_OFF);
  delay(200);  // minimum off time
  
#ifdef CAPACITIVE
  while(touch.capacitiveSensor(30) > SENSOR_THRESHOLD );
#else
  while (digitalRead(SENSOR)==LOW);
#endif

  display_pattern(random(6));
  
  delay(500);  // cheat prevention 
}
