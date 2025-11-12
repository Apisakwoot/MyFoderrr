//หยุดมอเตอร์
void StopMoter(){
  digitalWrite(Moter_L_IN1, LOW);  
  digitalWrite(Moter_L_IN2, LOW);
  digitalWrite(Moter_R_IN1, LOW); 
  digitalWrite(Moter_R_IN2, LOW);
}