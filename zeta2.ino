int bluetooth=0;
#define echopin  9 // echo pin
#define trigpin 8 // Trigger pin
int maximumRange = 50;
long duration, distance;


void setup() {  
  Serial.begin(9600); //very important line...wont work without this...it setups the serial library and tell its communication speed 
 pinMode(7,OUTPUT);//relay 4
 pinMode(6,OUTPUT);//relay 3
 pinMode(5,OUTPUT);//relay 2
 pinMode(4,OUTPUT);//relay 1
 pinMode(13,OUTPUT); /*For Green LED Indicating Motor Status */
pinMode(12,OUTPUT); /* For Red Power LED */
pinMode(10,OUTPUT); /*For torch*/

// rx @ pin 0 of board is connected to tx of bluetooth and pin 1 to Rx of bluetooth

//lack of vcc leads for sharing of Vcc ports and ground also

// pin 0 and pin 1 is for bluetooth and pin 13 in for ground of sensor

// join the relay 1 to the motor and the bluetooth control of relay one is disconnected cause it will work on the sensor

// the fluctuation in the sensor occurs when the distance creating problem like when box is closed also when battery is less.

// dont share the gnd of sensor and bluetooth. For working of the bluetooth properly just connnected the aduino to power backup not 9volt.

// 2.5 and 4.5 can be taken from the points below the usb port.

/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 9 
 Trig to Arduino pin 8*/

 pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
}

void loop() {
  
digitalWrite(12,HIGH); /* signifying the incoming power*/
  
  if(Serial.available()>0)
  {
 bluetooth=Serial.read();

 switch(bluetooth)
 {
case 'A': digitalWrite(10,HIGH);
 break;

case 'a': digitalWrite(10,LOW);
break;

case 'B': digitalWrite(5,HIGH);
break;

case 'b': digitalWrite(5, LOW);
break;

case 'C': digitalWrite(6,HIGH);
break;

case 'c': digitalWrite(6,LOW);
break;

case 'D': digitalWrite(7,HIGH);
break;

case 'd': digitalWrite(7, LOW);
break;


          case 'E':
               //All Relays ON when inByte equals 1
              digitalWrite(5, HIGH);
              digitalWrite(6, HIGH);
              digitalWrite(7, HIGH);
            break;
          case 'e':               
                //All Relays OFF when inByte equals 2
                digitalWrite(5, LOW);
                digitalWrite(6, LOW);
                digitalWrite(7, LOW);
            break;            
}
  }

digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    
    duration=pulseIn (echopin,HIGH);
    
    distance= duration/58.2;
    delay (50);
    Serial.println(distance);
  
  
 if (distance >= 15 ){
   digitalWrite (4,HIGH);
   digitalWrite(13,HIGH);/*connet an led here....*/
 }
 else if (distance <=10) {
   digitalWrite (4,LOW);
   digitalWrite (13,LOW);
   

}

  }

//App : Arduino Bluetooth Control
