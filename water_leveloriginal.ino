#define TRIG_PIN D5
#define ECHO_PIN D6
#define RELAY_PIN D4

// ---- Calibrated distances ----
const float FULL_DISTANCE = 3.6;   // cm - closest measured distance (tank full)
const float EMPTY_DISTANCE = 6.3;  // cm - farthest measured distance (tank empty)

long duration;
float distance;
int levelPercent;
bool pumpState = false; // Pump OFF initially

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  
  digitalWrite(RELAY_PIN, HIGH); // Pump OFF initially
  Serial.println("System Started - Smart Water Pump (Offline Mode)");
}

// ---------- Read and average water level ----------
float getAverageDistance(int samples = 3) {
  float sum = 0;
  for (int i = 0; i < samples; i++) {
    // Trigger ultrasonic pulse
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read echo
    long dur = pulseIn(ECHO_PIN, HIGH, 20000); // 20ms timeout
    if (dur == 0) dur = 20000; // treat no echo as max distance

    float d = (dur * 0.0343) / 2.0;
    sum += d;
    delay(50); // small delay between samples
  }
  return sum / samples;
}

void readWaterLevel() {
  distance = getAverageDistance();

  // Map distance to 0–100%
  levelPercent = map(distance, EMPTY_DISTANCE, FULL_DISTANCE, 0, 100);
  levelPercent = constrain(levelPercent, 0, 100);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Water Level: ");
  Serial.print(levelPercent);
  Serial.println(" %");

  // ---- Pump Control via Relay ----
  if (levelPercent <= 5 && !pumpState) {       // Tank empty
    pumpState = true;
    digitalWrite(RELAY_PIN, LOW);              // Relay ON → Pump ON
    Serial.println("💧 Pump ON");
  } 
  else if (levelPercent >= 95 && pumpState) { // Tank full
    pumpState = false;
    digitalWrite(RELAY_PIN, HIGH);             // Relay OFF → Pump OFF
    Serial.println("✅ Pump OFF");
  }
}

void loop() {
  readWaterLevel();
  delay(2000); // Measure every 2 sec
}

