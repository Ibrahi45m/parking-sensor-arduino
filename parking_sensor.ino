#define trigPin 9
#define echoPin 10
#define buzzer 8

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // إرسال موجة
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // استقبال الموجة
  duration = pulseIn(echoPin, HIGH);

  // حساب المسافة
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // التحكم فالبازر
  if (distance < 10) {
    tone(buzzer, 1000); // قريب بزاف
  }
  else if (distance < 20) {
    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);
    delay(200);
  }
  else if (distance < 30) {
    tone(buzzer, 1000);
    delay(500);
    noTone(buzzer);
    delay(500);
  }
  else {
    noTone(buzzer); // بعيد
  }
}
