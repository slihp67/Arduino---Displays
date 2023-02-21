/*

 

 http://www.arduino.cc/en/Tutorial/TFTGraph

 */

#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   8
#define rst  9


TFT TFTscreen = TFT(cs, dc, rst);

// position of the line on screen
int x0 = 0;
int y0 = 0;
int x1 = 0;
int y1 = 0;
char tempPrintout[3];
char airPrintout[3];
char presPrintout[3];
char humPrintout[3];


// read the value of the potentiometer:
int DisplayMode = 2;



void setup() {
  // initialize the serial port
  //Serial.begin(9600);

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  x1 = TFTscreen.width();
  y1 = TFTscreen.height();


  switch(DisplayMode) {
    case 0: 
      SetupSplitScreenSingle();
      break;
    case 1: 
      SetupSplitScreenDouble();
      break;
    default:
      SetupScreenSingle();
      break;
  }

}

void loop() {

  if(DisplayMode <= 1)
    {
      //randomize string values (replacw with sensor values)
      String strTemp = String(random(90));
      String strAir = String(random(90));
      String strPreasure = String(random(90));
      String strHumidity = String(random(90));
      //set sensor text color to yellow
      TFTscreen.stroke(255, 255, 255);
      //
      strTemp.toCharArray(tempPrintout, 3);
      strAir.toCharArray(airPrintout, 3);
      strPreasure.toCharArray(presPrintout, 3);
      strHumidity.toCharArray(humPrintout, 3);

      TFTscreen.text(tempPrintout, 35, 35);
      TFTscreen.text(airPrintout, 110, 35);
      TFTscreen.text(presPrintout, 35, 95);
      TFTscreen.text(humPrintout, 110, 95);

      delay(1000);

      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text(tempPrintout, 35, 35);
      TFTscreen.text(airPrintout, 110, 35);
      TFTscreen.text(presPrintout, 35, 95);
      TFTscreen.text(humPrintout, 110, 95);
      return;
    }
  if(DisplayMode = 2)
    {
      //randomize string values (replacw with sensor values)
      String strPreasure = String(random(90));

      //set sensor text color to yellow
      TFTscreen.stroke(0, 255, 255);
    
      strPreasure.toCharArray(presPrintout, 3);
      TFTscreen.text(presPrintout, x1/2-10, y1/2);

      delay(1000);

      TFTscreen.stroke(0, 0, 0);
      TFTscreen.text(presPrintout, x1/2-10, y1/2);

      return;
    }
  if(DisplayMode = 3)
    {
  
      return;
    }






  // // read the sensor and map it to the screen height
  // int sensor = analogRead(A0);

  // int drawHeight = map(sensorRandom, 0, 1023, 0, TFTscreen.height());

  // // print out the height to the serial monitor
  // //Serial.println(drawHeight);

  // // draw a line in a nice color
  // TFTscreen.stroke(250, 180, 10);
  // TFTscreen.line(x0, TFTscreen.height() - drawHeight, x0, TFTscreen.height());

  // // if the graph has reached the screen edge
  // // erase the screen and start again
  // if (x0 >= 160) {
  //   x0 = 0;
  //   TFTscreen.background(0, 0, 0);
  // } else {
  //   // increment the horizontal position:
  //   x0++;
  // }



}

void SetupSplitScreenDouble() {

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  // set the color to yello
  TFTscreen.stroke(255,0,0);
  //draw outer grid box with 12 fill
  TFTscreen.rect(x0,y0,x1/2,y1/2,12); //a
  TFTscreen.rect((x1/2)-1,x0,(x1/2),y1/2,12); //b
  TFTscreen.rect(x0,(y1/2)-1,x1/2,y1/2,12); //c
  TFTscreen.rect((x1/2)-1,(y1/2)-1,x1/2,y1/2,12);//d
  //color seems to be bgr not rgb
  TFTscreen.stroke(255,0,0);
  //draw inner grid box with fill
  TFTscreen.rect(x0+6,y0+5,(x1/2)-12,(y1/2)-10,12); //a1
  TFTscreen.rect(((x1/2)-1)+6,x0+5,(x1/2)-12,(y1/2)-10,12); //b1
  TFTscreen.rect(x0+6,((y1/2)-1)+5,(x1/2)-12,(y1/2)-10,12); //c1
  TFTscreen.rect(((x1/2)-1)+6,((y1/2)-1)+5,(x1/2)-12,(y1/2)-10,12);//d1
  
  //TFTscreen.stroke(255, 255, 255);
  //set font size for headings
  TFTscreen.setTextSize(1);

  // write heading text
  TFTscreen.text("Air", 30, 20);
  TFTscreen.text("Temp", 105, 20);
  TFTscreen.text("Flo", 30, 80);
  TFTscreen.text("Hum", 105, 80);

  //set font size for values
  TFTscreen.setTextSize(2);
  // write value text  
  TFTscreen.text("0", 35, 30);
  TFTscreen.text("0", 110, 30);
  TFTscreen.text("0", 35, 90);
  TFTscreen.text("0", 110, 90);

  delay(100);
  //erase value text place holders
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text("0", 35, 30);
  TFTscreen.text("0", 110, 30);
  TFTscreen.text("0", 35, 90);
  TFTscreen.text("0", 110, 90);

}

void SetupSplitScreenSingle() {

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  // set the color to yello
  TFTscreen.stroke(255,0,0);
  //draw outer grid box with 12 fill
  TFTscreen.rect(x0,y0,x1/2,y1/2,12); //a
  TFTscreen.rect((x1/2)-1,x0,(x1/2),y1/2,12); //b
  TFTscreen.rect(x0,(y1/2)-1,x1/2,y1/2,12); //c
  TFTscreen.rect((x1/2)-1,(y1/2)-1,x1/2,y1/2,12);//d
  //color seems to be bgr not rgb
  TFTscreen.stroke(255,0,0);
  //draw inner grid box with fill
  //TFTscreen.rect(x0+6,y0+5,(x1/2)-12,(y1/2)-10,12); //a1
  //TFTscreen.rect(((x1/2)-1)+6,x0+5,(x1/2)-12,(y1/2)-10,12); //b1
  //TFTscreen.rect(x0+6,((y1/2)-1)+5,(x1/2)-12,(y1/2)-10,12); //c1
  //TFTscreen.rect(((x1/2)-1)+6,((y1/2)-1)+5,(x1/2)-12,(y1/2)-10,12);//d1
  
  //TFTscreen.stroke(255, 255, 255);
  //set font size for headings
  TFTscreen.setTextSize(1);

  // write heading text
  TFTscreen.text("Air", 30, 20);
  TFTscreen.text("Temp", 105, 20);
  TFTscreen.text("Flo", 30, 80);
  TFTscreen.text("Hum", 105, 80);

  //set font size for values
  TFTscreen.setTextSize(2);
  // write value text  
  TFTscreen.text("0", 35, 30);
  TFTscreen.text("0", 110, 30);
  TFTscreen.text("0", 35, 90);
  TFTscreen.text("0", 110, 90);

  delay(100);
  //erase value text place holders
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text("0", 35, 30);
  TFTscreen.text("0", 110, 30);
  TFTscreen.text("0", 35, 90);
  TFTscreen.text("0", 110, 90);

}

void SetupScreenSingle() {

 // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  // set the color to yello
  TFTscreen.stroke(0,255,255);
  //draw outer grid box with 12 fill
  TFTscreen.rect(x0,y0,x1,y1,12); //a
  //TFTscreen.rect((x1/2)-1,(y1/2)-1,x1/2,y1/2,12);//d
  //color seems to be bgr not rgb
  TFTscreen.stroke(0,255,255);
  
  TFTscreen.stroke(0, 255, 255);
  //set font size for headings
  TFTscreen.setTextSize(3);

  // write heading text
  TFTscreen.text("Psi", 60, 30);

  //set font size for values
  TFTscreen.setTextSize(3);
  // write value text  
  TFTscreen.text("0", 35, 90);

  delay(100);
  //erase value text place holders
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text("0", 35, 90);


}
