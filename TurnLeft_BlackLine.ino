//หมุนซ้าย(อยู่กับที่)
void RotatLeft() {
  digitalWrite(Moter_L_IN1, LOW);
  digitalWrite(Moter_L_IN2, HIGH);
  digitalWrite(Moter_R_IN1, HIGH);
  digitalWrite(Moter_R_IN2, LOW);
  analogWrite(Moter_L_ENA, 100);
  analogWrite(Moter_R_ENB, 80);
}