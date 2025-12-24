bool isJunction = false;
void loop() {

  //อ่านค่าของเซนเซอร์
  int left = digitalRead(SENSOR_LEFT);
  int right = digitalRead(SENSOR_RIGHT);


  // แสดงค่าที่อ่านได้ของเซนเซอร์
  Serial.print("Left: "); Serial.print(left);
  Serial.print("Right: "); Serial.println(right);




  // เดินตรง (left == 0 && right == 0) <-- คือค่าที่เซนเซอร์ตรวจจับได้ HIGH คือเจอสีขาว
  if (left == 0 && right == 0) {
    StartForward();
    if (isJunction) { // ตรวจสอบว่าเพิ่งออกจากแยกหรือไม่
        isJunction = false; 
        delay(200);
    }
  }
  
  
  // เลี้ยวขวา (left == 1 && right == 0) <-- คือค่าที่เซนเซอร์ตรวจจับได้ 1 คือเจอสีดำทางซ้าย 
  else if (left == 1 && right == 0){

    StartturnLeft();
    isJunction = false; // ยืนยันว่ากลับสู่การติดตามเส้นปกติ
    delay(200);
  }

  // เลี้ยวซ้าย (left == 0 && right == 1) <-- คือค่าที่เซนเซอร์ตรวจจับได้ 1 คือเจอสีดำทางขวา
  else if (left == 0 && right == 1){

    StartturnRight(); 
    isJunction = false; // ยืนยันว่ากลับสู่การติดตามเส้นปกติ
  }

// ทำให้เดินตามลำดับคำสั่งเมื่อมีทางเลี้ยวที่ต่างกัน (left == 1 && right == 1) <-- คือค่าที่เซนเซอร์ตรวจจับได้ 1 คือเจอสีดำ
  else if (left == 1 && right == 1) {
    // เงื่อนไขใหม่: ต้องเจอทางแยก และยังไม่ได้ทำภารกิจที่แยกนี้ (isJunction เป็น false)
  if (!isJunction) {
    isJunction = true;
    junctionCount++;        // เพิ่มจำนวนครั้งที่เจอทางที่ต่างกัน
        
        if (junctionCount == 1) {
      StopMoter(); delay(300);
      StartBackward(); delay(300);
      RotatRight();   delay(400);
      StopMoter(); delay(400);
    }
    else if (junctionCount == 2) {
      StopMoter(); delay(300);
      StartBackward(); delay(300);
      RotatRight();   delay(400);
      StopMoter(); delay(400);
    }
    else if (junctionCount == 3) {
      StopMoter(); delay(300);
      StartBackward(); delay(300);
      RotatRight();   delay(400);
      StopMoter(); delay(400);
    }
    else if (junctionCount == 4) {
      StopMoter(); delay(300);
      StartBackward(); delay(300);
      RotatLeft();   delay(430);
      StopMoter(); delay(400);
    }
  }
}
}
