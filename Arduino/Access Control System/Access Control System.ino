#define trigPin 9
#define echoPin 10
#define gasPin A0

long duration;
int distance;
int gasValue;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  gasValue = analogRead(gasPin);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Gas Value: ");
  Serial.println(gasValue);

  delay(1000);
}
