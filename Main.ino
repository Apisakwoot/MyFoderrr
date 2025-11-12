// กำหนดพิน L298N
#define Moter_L_IN1 4
#define Moter_L_IN2 5
#define Moter_L_ENA 10 //A ล้อซ้าย
#define Moter_R_IN1 6
#define Moter_R_IN2 7
#define Moter_R_ENB 11 //B ล้อขวา

// กำหนดพินเซนเซอร์
#define SENSOR_LEFT 2
#define SENSOR_RIGHT 3

// ตัวแปรนับจำนวนครั้งที่เจอเส้นดำในแต่ละครั้ง ในแต่ละกรณีจะมีทางไปต่างกันจึงต้องคำนวณทางไปในที่ละทางไปตามลำดับ
int junctionCount = 0; 

void setup() {
  // พินมอเตอร์
  pinMode(Moter_L_IN1, OUTPUT); pinMode(Moter_L_IN2, OUTPUT); 
  pinMode(Moter_R_IN1, OUTPUT); pinMode(Moter_R_IN2, OUTPUT); 
  pinMode(Moter_L_ENA, OUTPUT);
  pinMode(Moter_R_ENB, OUTPUT);

   // พินเซนเซอร์
  pinMode(SENSOR_LEFT, INPUT);
  pinMode(SENSOR_RIGHT, INPUT);

  // เปิดช่องสื่อสาร Serial
  Serial.begin(9600);
}


