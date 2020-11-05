#define X_PIN A0
#define Y_PIN A1
#define SW_PIN 2

#define UP_PIN 3
#define DOWN_PIN 4
#define LEFT_PIN 5
#define RIGHT_PIN 6

#define BAUD_RATE 115200
#define DELAY_PER_CYCLE 50 // ms

// BTPASS 6634
/*
 * AT : Ceck the connection.
 * AT+NAME : See default name
 * AT+ADDR : see default address
 * AT+VERSION : See version
 * AT+UART : See baudrate
 * AT+ROLE: See role of bt module(1=master/0=slave)
 * AT+RESET : Reset and exit AT mode
 * AT+ORGL : Restore factory settings
 * AT+PSWD: see default password
 * 
 * To configure HC-05 you need to put it in AT mode, then:
 * 
 * AT+NAME=joystick-01
 * AT+UART=115200,0,0
 * AT+PSWD=6634
 * AT+ROLE=0
 */
int x_axis = 0, y_axis = 0, sw = 0;
int up_bt=0, down_bt=0, left_bt=0, right_bt=0;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD_RATE);
  
  while (Serial.available() && Serial.read()); // empty buffer

  analogReference(DEFAULT);
  
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  pinMode(UP_PIN, INPUT_PULLUP);
  pinMode(DOWN_PIN, INPUT_PULLUP);
  pinMode(LEFT_PIN, INPUT_PULLUP);
  pinMode(RIGHT_PIN, INPUT_PULLUP);
  pinMode(SW_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long startTime = millis();

  x_axis = analogRead(X_PIN);
  y_axis = analogRead(Y_PIN);
  up_bt = digitalRead(UP_PIN);
  down_bt = digitalRead(DOWN_PIN);
  left_bt = digitalRead(LEFT_PIN);
  right_bt = digitalRead(RIGHT_PIN);
  sw = digitalRead(SW_PIN);
  
  Serial.print(millis()); Serial.print(',');
  Serial.print(x_axis); Serial.print(',');
  Serial.print(y_axis); Serial.print(',');
  Serial.print(sw); Serial.print(',');
  Serial.print(up_bt); Serial.print(',');
  Serial.print(down_bt); Serial.print(',');
  Serial.print(left_bt); Serial.print(',');
  Serial.print(right_bt); Serial.print('\n');
  
  Serial.flush();
  unsigned long elapsedTime = millis() - startTime;
  if ( elapsedTime < DELAY_PER_CYCLE ) {
    delay(DELAY_PER_CYCLE - elapsedTime);
  } // if  
 
}
