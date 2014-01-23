void qrFillRect(UTFT myGLCD, int x, int y) {
  myGLCD.fillRect(x, y, x+10, y+10);
}
void qrFillRectColor(UTFT myGLCD, int x, int y, word color) {
  myGLCD.setColor(color);
  myGLCD.fillRect(x, y, x+10, y+10);
}
