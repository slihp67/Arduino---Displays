/*

 TFT & SPI 
 
 example drawing 4 boxes on screen with randomized sensor values.

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
char tempPrintout[4];
char airPrintout[4];
char presPrintout[4];
char humPrintout[4];

void setup() {
  // initialize the serial port
  //Serial.begin(9600);

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  DrawBoxes();


  delay(1000);
  //erase value text place holders
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text("0", 35, 30);
  TFTscreen.text("0", 110, 30);
  TFTscreen.text("0", 35, 90);
  TFTscreen.text("0", 110, 90);

}

void loop() {

  
  //randomize string values (replacw with sensor values)
  String strTemp = String(random(110));
  String strAir = String(random(110));
  String strPreasure = String(random(110));
  String strHumidity = String(random(110));
  //set sensor text color to yellow
  TFTscreen.stroke(0, 255, 255);
  //
  strTemp.toCharArray(tempPrintout, 4);
  strAir.toCharArray(airPrintout, 4);
  strPreasure.toCharArray(presPrintout, 4);
  strHumidity.toCharArray(humPrintout, 4);
  //print values
  TFTscreen.text(tempPrintout, 35, 35);
  TFTscreen.text(airPrintout, 110, 35);
  TFTscreen.text(presPrintout, 35, 95);
  TFTscreen.text(humPrintout, 110, 95);



  delay(100);

  //now erase values
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text(tempPrintout, 35, 35);
  TFTscreen.text(airPrintout, 110, 35);
  TFTscreen.text(presPrintout, 35, 95);
  TFTscreen.text(humPrintout, 110, 95);

}

void DrawBoxes() {


  int x1 = TFTscreen.width();
  int y1 = TFTscreen.height();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  // set the color to yello
  TFTscreen.stroke(0,255,255);
  //draw outer grid box with 12 fill
  TFTscreen.rect(x0,y0,x1/2,y1/2,12); //a
  TFTscreen.rect((x1/2)-1,x0,(x1/2),y1/2,12); //b
  TFTscreen.rect(x0,(y1/2)-1,x1/2,y1/2,12); //c
  TFTscreen.rect((x1/2)-1,(y1/2)-1,x1/2,y1/2,12);//d
  //color seems to be bgr not rgb
  TFTscreen.stroke(0,255,255);
  //draw inner grid box with fill
  TFTscreen.rect(x0+6,y0+5,(x1/2)-12,(y1/2)-10,12); //a1
  TFTscreen.rect(((x1/2)-1)+6,x0+5,(x1/2)-12,(y1/2)-10,12); //b1
  TFTscreen.rect(x0+6,((y1/2)-1)+5,(x1/2)-12,(y1/2)-10,12); //c1
  TFTscreen.rect(((x1/2)-1)+6,((y1/2)-1)+5,(x1/2)-12,(y1/2)-10,12);//d1
  
  //TFTscreen.stroke(255, 255, 255);
  //set font size for headings
  TFTscreen.setTextSize(1);

  // write heading text
  TFTscreen.text("Air", 15, 10);
  TFTscreen.line(15, 20, 30, 20);

  TFTscreen.text("Temp", 95, 10);
  TFTscreen.line(95, 20, 120, 20);

  TFTscreen.text("Flo", 15, 73);
  TFTscreen.line(15, 83, 35, 83);

  TFTscreen.text("Hum", 95, 73);
  TFTscreen.line(95, 83, 115, 83);

  //set font size for values
  TFTscreen.setTextSize(1);
  // write value text  
  TFTscreen.text("0", 35, 30);
  TFTscreen.text("0", 110, 30);
  TFTscreen.text("0", 35, 90);
  TFTscreen.text("0", 110, 90);

}