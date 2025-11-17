#include <AbsMouse.h> 

#include <math.h> 

uint8_t pinstate=1, KeyHit=0, seq=0;  


  

void setup() { 

  AbsMouse.init(2560,1440); 

  pinMode(12, INPUT_PULLUP);

  delay(1000); // Let USB settle 

} 

  

void loop() { 

  if (digitalRead(12)==0)
  {
     if (pinstate!=0)
     {
        pinstate=0;
        KeyHit=1;
     }
  }
  else pinstate=1;

  if (KeyHit!=0)
  {
    KeyHit=0;
    /*seq++; if (seq>3) seq=0;
    if (seq==0) AbsMouse.move(10, 10); 
    if (seq==1) AbsMouse.move(1900, 10); 
    if (seq==2) AbsMouse.move(1900, 1000); 
    if (seq==3) AbsMouse.move(10, 1000); */
    AbsMouse.move(1404, 968); 
    AbsMouse.press(MOUSE_LEFT);
    delay(100); 
    AbsMouse.release(MOUSE_LEFT);
    delay(100); 
  }

  /*
  // Calculate position in polar coordinates 

  int dx = int(radius * cos(angle)); 

  int dy = int(radius * sin(angle)); 

  

  // Move the mouse 

  AbsMouse.move(dx, dy); 

  

  // Advance angle 

  angle += angleStep; 

  

  // Adjust radius 

  if (expanding) { 

    radius += radiusStep; 

    if (radius >= maxRadius) expanding = false; 

  } else { 

    radius -= radiusStep; 

    if (radius <= minRadius) expanding = true; 

  } 
  */

  delay(10); 

} 
