// Code adapted from Arduino Experimentation Kit  CIRC-02 .: 8 LED Fun :. (Multiple LEDs) 

// I only had 5 560 Ohm resistors, so I adapted the code to work with 5 LEDS instead of 8
int ledPins[] = {2,3,4,5,6};

void setup()
{
  // Set each pin connected to an LED to output mode (pulling high (on) or low (off)
  for(int i = 0; i < (sizeof(ledPins)/sizeof(int)); i++){
      pinMode(ledPins[i],OUTPUT);
  }
}

void loop()                   
{
  oneAfterAnother();
}
 
void oneAfterAnother(){
  int delayTime = 100;
//Turn Each LED on one after another
  for(int i = 0; i <= (sizeof(ledPins)/sizeof(int)); i++){
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime); 
  }
//Turn Each LED off one after another
  for(int i = (sizeof(ledPins)/sizeof(int)); i >= 0; i--){  
    digitalWrite(ledPins[i], LOW);
    delay(delayTime); 
  }                      
}

/*
 * oneOnAtATime() - Will light one LED then the next turning off all the others
 */
void oneOnAtATime(){
  int delayTime = 100; //the time (in milliseconds) to pause between LEDs
                       //make smaller for quicker switching and larger for slower
  
  for(int i = 0; i < (sizeof(ledPins)/sizeof(int)); i++){
    int offLED = i - 1; 
    if(i == 0) {         
      offLED = (sizeof(ledPins)/sizeof(int)) -1;
    }
    digitalWrite(ledPins[i], HIGH);     //turn on LED #i
    digitalWrite(ledPins[offLED], LOW); //turn off the LED we turned on last time
    delay(delayTime);
  }
}
