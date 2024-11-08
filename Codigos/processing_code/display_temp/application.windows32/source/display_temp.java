import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class display_temp extends PApplet {

//Program by Jeremy Blum
//www.jeremyblum.com
//Give you the temperature


Serial port;
String temp_c = "";
String temp_f = "";
String data = "";
int index = 0;
PFont font;

public void setup()
{
  size(120,120);
  port = new Serial(this, "COM3", 9600);
  port.bufferUntil('.'); 
  font = loadFont("AgencyFB-Bold-200.vlw");
  textFont(font, 40);
}

public void draw()
{
  background(0,0,0);
  fill(46, 209, 2);
  text(temp_c, 0, 0);
  fill(0, 102, 153);
  text(temp_f, 0, 100);
}
  
public void serialEvent (Serial port)
{
  data = port.readStringUntil('.');
  data = data.substring(0, data.length() - 1);
  
  // look for the comma between Celcius and Farenheit
  index = data.indexOf(",");
  // fetch the C Temp
  temp_c = data.substring(0, index);
  // fetch the F Temp
  temp_f = data.substring(index+1, data.length());
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "display_temp" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
