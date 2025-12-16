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
        delay(100); // ให้แน่ใจว่าออกจากจุดแยกแล้ว
        isJunction = false; 
    }
  }
  
  
  // เลี้ยวขวา (left == 1 && right == 0) <-- คือค่าที่เซนเซอร์ตรวจจับได้ 1 คือเจอสีดำทางซ้าย 
  else if (left == 1 && right == 0){
    StartturnRight();
    isJunction = false; // ยืนยันว่ากลับสู่การติดตามเส้นปกติ
    delay(100); // ปรับค่าเวลาเลี้ยว
  }

  // เลี้ยวซ้าย (left == 0 && right == 1) <-- คือค่าที่เซนเซอร์ตรวจจับได้ 1 คือเจอสีดำทางขวา
  else if (left == 0 && right == 1){
    StartturnLeft();
    isJunction = false; // ยืนยันว่ากลับสู่การติดตามเส้นปกติ
    delay(100); // ปรับค่าเวลาเลี้ยว
  }

// ทำให้เดินตามลำดับคำสั่งเมื่อมีทางเลี้ยวที่ต่างกัน (left == 1 && right == 1) <-- คือค่าที่เซนเซอร์ตรวจจับได้ 1 คือเจอสีดำ
  else if (left == 1 && right == 1) {
    // เงื่อนไขใหม่: ต้องเจอทางแยก และยังไม่ได้ทำภารกิจที่แยกนี้ (isJunction เป็น false)
  if (!isJunction) { 
        StopMoter();
        isJunction = true;      // ตั้งค่าสถานะว่ากำลังดำเนินการที่ทางแยกนี้
        junctionCount++;        // เพิ่มจำนวนครั้งที่เจอทางที่ต่างกัน
        
        if (junctionCount == 1){
          StartBackward();
          delay(200); 
          RotatRight(); 
          delay(400); 
          StartForward();
        }

        else if (junctionCount == 2){
          StartBackward();
          delay(200); 
          RotatRight(); 
          delay(400); 
          StartForward();
        }

        else if (junctionCount == 3){
          StartBackward();
          delay(200); 
          RotatRight(); 
          delay(400); 
          StartForward();

        }
    }
  }
}
