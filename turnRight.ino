 //หมุนขวา
void StartturnRight(){
  digitalWrite(Moter_L_IN1, HIGH);//เดิน
  digitalWrite(Moter_L_IN2, LOW);// หยุด
  digitalWrite(Moter_R_IN1, LOW);// หยุด 
  digitalWrite(Moter_R_IN2, LOW);// หยุด
  analogWrite(Moter_L_ENA, 100);
  analogWrite(Moter_R_ENB, 80);
}