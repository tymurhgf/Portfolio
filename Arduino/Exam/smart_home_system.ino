#include <Servo.h>

#define gas_sensor A1 
#define LDR A0
#define temp_sensor A2
int Vidstan = 0; //Відстань
int Ruch = 0; //Рухається чи ні
int limit = 400; //Ліміт забрудненості повітря

long readUltrasonicDistance(int triggerPin, int echoPin)
{ //Робота Ультразвукового датчику. Спрацювання і приймання
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

Servo MyServo;

void setup()
{
  pinMode(temp_sensor, INPUT);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1,INPUT);     
  pinMode(13, OUTPUT);
  MyServo.attach(7, 500, 2500); //7 - пін, 500-2500 межі, щоб не зламав двері

  pinMode(8,OUTPUT);  	
  pinMode(9, INPUT);	
  pinMode(10, OUTPUT);	
  pinMode(4, OUTPUT);	
  pinMode(3, OUTPUT);
 
}

void loop()
{
  
// -- Вмикає лампу відповідно до того світло чи темно в кімнаті --
  
    int val1 = analogRead(LDR); // Яскравість від 0(світло) до 1023(темно)
  if (val1 > 500) //Чи темно?
  	{
    	digitalWrite(13, LOW); //Вимикає струм реле -> вмикає лампу
    Serial.print("Bulb ON = ");
    Serial.print(val1); //Виводить яскравість в Serial Monitor
  	} 
  else 
  	{
    	digitalWrite(13, HIGH);// Реле працює -> лампочка вимкнута
     Serial.print("Bulb OFF = ");
    Serial.print(val1);
  	}

// -- Сигналізація - чи хтось ходить по кімнаті  
  
  Ruch = digitalRead(9); //Якщо в кімнаті тихо — датчик дає 0.
                         //Якщо хтось пройшов — датчик дає 1.
  if (Ruch == 0) 
  	{
    	digitalWrite(10, LOW); //Dc Motor викнений
    	digitalWrite(4, HIGH); // Зелений включений
    	digitalWrite(3, LOW); // Червоний вимкнений
    Serial.print("     || NO Motion Detected    " );
  	}
 
  if (Ruch == 1) 
  	{
    	digitalWrite(10, HIGH);//Dc Motor ввімкнений
    delay(500);
    	digitalWrite(4, LOW); // Червоний включений
    	digitalWrite(3, HIGH);// Зелений вимкнений
     Serial.print(" 	   || Motion Detected!      " );
  	}
  
// -- Датчик вуглекислого газу -- 
  
int val = analogRead(gas_sensor); //Зчитує забруднення від 1 до 1023
  Serial.print("|| Gas Sensor Value = ");
  Serial.print(val);				   
  if (val > limit)
  	{
    	tone(8, 650); //Пахне газом
  	}
 	delay(300);
 	noTone(8);

// -- Швейцар - Бачить що ти підходиш - відкриває двері --
  
  Vidstan = 0.01723 * readUltrasonicDistance(6, 6); //Швидкість звуку * час до об'єкта

  if (Vidstan < 100) 
  	{
    	MyServo.write(90);
    Serial.print(" 	  || Door Open!  ; Distance = ");
    Serial.print(Vidstan);
   Serial.print("\n");
 
  	} 
  else 
  	{
    	MyServo.write(0);
    Serial.print(" 	  || Door Closed! ; Distance =  ");
    Serial.print(Vidstan);
    Serial.print("\n");
  }
  
// -- Вентилятор - вмикається коли жарко --
  
  int reading = analogRead(temp_sensor); // Струм від 0 до 1023
  float voltage = reading * 5.0 / 1024.0;
  float temperatureC = (voltage - 0.5) * 100 ; //0.5В - 1 градус
                                           // 0.01В = 1 градус

  Serial.print("|| Temperature = ");
  Serial.print(temperatureC);
  Serial.println(" C");

  if (temperatureC > 30) {
     digitalWrite(10, HIGH); 
     Serial.println("   !!! TOO HOT !!!");
  }

  delay(1000); 
  delay(10); 
}