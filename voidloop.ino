void loop() {

  //อ่านค่าของเซนเซอร์
  int left = digitalRead(SENSOR_LEFT);
  int right = digitalRead(SENSOR_RIGHT);

  // แสดงค่าที่อ่านได้ของเซนเซอร์
  Serial.print("Left: "); Serial.print(left);
  Serial.print("  Right: "); Serial.println(right);

  // เดินตรง (left == HIGH && right == HIGH) <-- คือค่าที่เซนเซอร์ตรวจจับได้ HIGH คือเจอสีขาว
  if (left == HIGH && right == HIGH) {
    StartForward();
  }
  
  // เลี้ยวขวา (left == LOW && right == HIGH) <-- คือค่าที่เซนเซอร์ตรวจจับได้ LOW คือเจอสีดำทางซ้าย 
  else if (left == LOW && right == HIGH){
    StartturnRight();
    delay(50); // ปรับค่าเวลาเลี้ยว
  }

  // เลี้ยวซ้าย (left == HIGH && right == LOW) <-- คือค่าที่เซนเซอร์ตรวจจับได้ HIGH คือเจอสีดำทางขวา
  else if (left == HIGH && right == LOW){
    StartturnLeft();
    delay(50); // ปรับค่าเวลาเลี้ยว
  }

// ทำให้เดินตามลำดับคำสั่งเมื่อมีทางเลี้ยวที่ต่างกัน (left == LOW && right == LOW) <-- คือค่าที่เซนเซอร์ตรวจจับได้ LOW คือเจอสีดำ
  else if (left == LOW && right == LOW) {
    StopMoter();
    delay(100);

    junctionCount++; // เพิ่มจำนวนครั้งที่เจอทางที่ต่างกัน


    if (junctionCount == 1) {
      // เจอเส้นดำครั้งแรก → ถอยหลัง → หมุนขวา → เดินต่อ
      StartBackward(); //ถอย
      delay(200);
      RotatRight(); //หมุนขวา
      delay(400);
      StartForward(); //เดิน
    }

    else if (junctionCount == 2) {
      // เจอเส้นดำครั้งสอง → ถอยหลัง → หมุนขวา → เดินต่อ
      StartBackward(); //ถอย
      delay(200);
      RotatRight(); //หมุนขวา
      delay(400);
      StartForward(); //เดิน
    }

    else if (junctionCount == 3) {
      // เจอเส้นดำครั้งสาม → ถอยหลัง → หมุนขวา → เดินต่อ
      StartBackward(); //ถอย
      delay(200);
      RotatRight(); //หมุนขวา
      delay(400);
      StartForward(); //เดิน
    }

    else if (junctionCount == 4) {
      // เจอเส้นดำครั้งสี่ → ถอยหลัง → หมุนซ้าย → เดินต่อ
      StartBackward(); //ถอย
      delay(200);
      RotatLeft(); //หมุนซ้าย
      delay(400);
      StartForward(); //เดิน
    }

    else if (junctionCount == 5) {
      // เจอเส้นดำครั้งห้า → ถอยหลัง → หมุนซ้าย → เดินต่อ → หมุนขวา → เดิน → หมุนขวา → เดิน
      StartBackward(); //ถอย
      delay(600);
      RotatLeft(); //หมุนซ้าย
      delay(400);
      StartForward(); //เดิน
      delay(1000);
      RotatRight(); //หมุนขวา
      delay(400);
      StartForward(); //เดิน
      delay(200);
      RotatRight(); //หมุนขวา
      delay(400);
      StartForward(); //เดิน
    }

    else if (junctionCount == 6) {
      // เจอเส้นดำครั้งหก → ถอยหลัง → หมุนขวา → เดินต่อ
      StartBackward(); //ถอย
      delay(3000);
      RotatRight(); //หมุนขวา
      delay(400);
      StartForward(); //เดิน
    }

    else if (junctionCount == 7) {
      // เจอเส้นดำครั้งเจ็ด → ถอยหลัง → หมุนซ้าย → เดินต่อ
      StartBackward(); //ถอย
      delay(200);
      RotatLeft(); //หมุนซ้าย
      delay(400);
      StartForward(); //เดิน
    }

    else if (junctionCount == 8) {
      // เจอเส้นดำครั้งแปด → ถอยหลัง → หมุนซ้าย → เดินต่อ
      StartBackward(); //ถอย
      delay(1000);
      RotatLeft(); //หมุนซ้าย
      delay(400);
      StartForward(); //เดิน
      delay(400);
      RotatLeft(); //หมุนซ้าย
      delay(400);
      StartForward(); //เดิน
      delay(400);
      RotatRight(); //หมุนขวา
      delay(400);
      StartForward(); //เดิน
      delay(400);
      StartBackward(); //ถอย
      delay(500);
      RotatRight(); //หมุนขวา
      delay(400);
      StartForward(); //เดิน
      delay(400);
      StartBackward(); //ถอย
      delay(500);
      RotatRight(); //หมุนขวา
      delay(400);
      StartForward(); //เดิน
      delay(400);
      RotatLeft(); //หมุนซ้าย
      delay(400);
      StartForward(); //เดิน
      delay(400);

    }
  }
}