
import processing.serial.*;
Serial port;
String temp_c = "";
String hum_h="";
String data = "";
int index = 0;
PFont font;

void setup()
{
  size(120,120);
  port = new Serial(this, "COM3", 9600);
  port.bufferUntil('.'); 
  font = loadFont("AgencyFB-Bold-200.vlw");
  textFont(font, 40);
}

void draw()
{
  background(0,0,0);
  fill(46, 209, 2);
  text(temp_c, 0, 0);
  fill(0, 102, 153);
  text(hum_h, 0, 100);
}
  
void serialEvent (Serial port)
{
  data = port.readStringUntil('.');
  data = data.substring(0, data.length() - 1);
  
  // look for the comma between Celcius and Farenheit
  index = data.indexOf(",");
  // fetch the C Temp
  temp_c = data.substring(0, index);
  
}
  
