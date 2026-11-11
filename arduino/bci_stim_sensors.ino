// BCI 가상 왼팔 · 신체 소유감 자극 센서 (선택 사항)
// 9600bps로 한 줄에 하나씩 "이름:값"을 보냅니다.
// 크롬북 화면의 [아두이노 센서 연결] 버튼을 눌러 이 보드를 고르면, 실제 자극이 자동으로 VR에 반영됩니다.
//
//   TEMP:섭씨온도      LM35 온도 센서(A0)를 팔 피부에 붙여 두면, 차가운 물체가 닿아 22℃ 아래로 내려갈 때 VR에서도 닿음
//   WIND:0.00~1.00     선풍기 바람 세기 (A1: 가변저항으로 세기를 맞추거나, 풍속 센서 출력을 연결)
//   TOUCH:0 또는 1     종이·물체가 닿았는지 (D2: 터치 센서 모듈 또는 접촉 스위치, 닿으면 LOW)
//   POS:0.00~1.00      닿는 위치 (선택: 팔을 따라 붙인 가변저항 등, 어깨 0 → 손목 1)

const int TEMP_PIN = A0;
const int WIND_PIN = A1;
const int TOUCH_PIN = 2;

void setup() {
  Serial.begin(9600);
  pinMode(TOUCH_PIN, INPUT_PULLUP);
}

void loop() {
  float tempC = analogRead(TEMP_PIN) * (5.0 / 1023.0) * 100.0;  // LM35: 10 mV/℃
  float wind = analogRead(WIND_PIN) / 1023.0;
  int touch = digitalRead(TOUCH_PIN) == LOW ? 1 : 0;

  Serial.print("TEMP:");  Serial.println(tempC, 1);
  Serial.print("WIND:");  Serial.println(wind, 2);
  Serial.print("TOUCH:"); Serial.println(touch);
  delay(50);  // 초당 20번
}
