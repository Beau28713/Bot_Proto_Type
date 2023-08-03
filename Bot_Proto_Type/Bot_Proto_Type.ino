int motor_one_enable = 2;
int motor_two_enable = 4;
int motor_one_drive_one = 11;
int motor_one_drive_two = 10;
int motor_two_drive_one = 3;
int motor_two_drive_two = 9;

int trig_pin = 5;
int echo_pin = 6;

int left_turn_led = 7;
int rev_led = 8;
int fwd_led = 12;
int right_turn_led = 13;

int setup_array[] = {motor_one_enable, motor_two_enable, motor_one_drive_one,
                     motor_one_drive_two, motor_two_drive_one, motor_two_drive_two, left_turn_led,
                     rev_led, fwd_led, right_turn_led, trig_pin};

int led_test_array[] = {left_turn_led, rev_led, fwd_led, right_turn_led};

void setup()
{
  Serial.begin(9600);
  pinMode(echo_pin, INPUT);
  for (int x = 0; x <= 10; x++)
  {
    pinMode(setup_array[x], OUTPUT);
  }
}

void loop()
{
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  float duration = pulseIn(echo_pin, HIGH);

  float inches = (duration / 148);

  Serial.println(inches);
  delay(100);
}

void test_leds()
{
  // Test LED's
  for (int x = 0; x <= 3; x++)
  {
    digitalWrite(led_test_array[x], HIGH);
    delay(500);
    digitalWrite(led_test_array[x], LOW);
    delay(500);
  }
}

void test_motors()
{
  // Test motors
  digitalWrite(motor_one_enable, HIGH);
  digitalWrite(motor_two_enable, HIGH);

  analogWrite(motor_one_drive_two, 126);
  analogWrite(motor_two_drive_two, 126);
  digitalWrite(fwd_led, HIGH);
  delay(2000);
  digitalWrite(fwd_led, LOW);
  analogWrite(motor_one_drive_two, 0);
  analogWrite(motor_two_drive_two, 0);

  delay(500);

  analogWrite(motor_one_drive_one, 126);
  analogWrite(motor_two_drive_one, 126);
  digitalWrite(rev_led, HIGH);
  delay(2000);
  digitalWrite(rev_led, LOW);
  analogWrite(motor_one_drive_one, 0);
  analogWrite(motor_two_drive_one, 0);
}