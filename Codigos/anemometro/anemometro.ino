
float veloc1= 0;// entrada A0
int tiempo=0;
int cnt=0;
float v1=0;
float v2=0;


void setup() {
 analogReference(INTERNAL);// pone como referencia interna 1.1V
 }
void loop() {  
   v1 =(analogRead(0)); // lectura de sensor a0
   veloc1= (v1*0.190); // 0,190 corresponde a la pendiente de la curva aca deben poner el numero que calcularon
   Serial.print(veloc1);  //muestra la velocidad del viento en el LCD
   Serial.print("Km/h");
   Serial.print("Max");


if (veloc1>v2)v2=veloc1,Serial.print (v2,1); // muestra la velocidad maxima que alcanzo 
 delay(1000); 
  
      
}
