void drawTemplate(UTFT myGLCD)
{
   myGLCD.setColor(VGA_BLACK);
   qrFillRect(myGLCD, 10, 250);
    qrFillRect(myGLCD, 10,250);
    qrFillRect(myGLCD, 10,240);
    qrFillRect(myGLCD, 10,230);
    qrFillRect(myGLCD, 10,220);
    qrFillRect(myGLCD, 10,210);
    qrFillRect(myGLCD, 10,200);
    qrFillRect(myGLCD, 10,190);
  
    
    qrFillRect(myGLCD, 20,250);
    qrFillRect(myGLCD, 30,250);
    qrFillRect(myGLCD, 40,250);
    qrFillRect(myGLCD, 50,250);
    qrFillRect(myGLCD, 60,250);
    qrFillRect(myGLCD, 70,250);
  
    qrFillRect(myGLCD, 70,240);
    qrFillRect(myGLCD, 70,230);
    qrFillRect(myGLCD, 70,220);
    qrFillRect(myGLCD, 70,210);
    qrFillRect(myGLCD, 70,200);
    qrFillRect(myGLCD, 70,190);
    
    qrFillRect(myGLCD, 60,190);
    qrFillRect(myGLCD, 50,190);
    qrFillRect(myGLCD, 40,190);
    qrFillRect(myGLCD, 30,190);
    qrFillRect(myGLCD, 20,190);
    //TOP LEFT CORNER OUTER BOX END  
    
    //TOP LEFT CORNER INSIDE BOX START  
    qrFillRect(myGLCD, 30,230);
    qrFillRect(myGLCD, 30,220);
    qrFillRect(myGLCD, 30,210);
  
    qrFillRect(myGLCD, 40,230);
    qrFillRect(myGLCD, 40,220);
    qrFillRect(myGLCD, 40,210);
  
    qrFillRect(myGLCD, 50,230);
    qrFillRect(myGLCD, 50,220);
    qrFillRect(myGLCD, 50,210);
    //TOP LEFT CORNER INSIDE BOX END
  
  //TOP RIGHT OUTER BOX START
  qrFillRect(myGLCD, 10,50);
  qrFillRect(myGLCD, 10,60);
  qrFillRect(myGLCD, 10,70);
  qrFillRect(myGLCD, 10,80);
  qrFillRect(myGLCD, 10,90);
  qrFillRect(myGLCD, 10,100);
  qrFillRect(myGLCD, 10,110);

  qrFillRect(myGLCD, 20,50);
  qrFillRect(myGLCD, 30,50);
  qrFillRect(myGLCD, 40,50);
  qrFillRect(myGLCD, 50,50);
  qrFillRect(myGLCD, 60,50);
  qrFillRect(myGLCD, 70,50);

  qrFillRect(myGLCD, 70,60);
  qrFillRect(myGLCD, 70,70);
  qrFillRect(myGLCD, 70,80);
  qrFillRect(myGLCD, 70,90);
  qrFillRect(myGLCD, 70,100);
  qrFillRect(myGLCD, 70,110);

  qrFillRect(myGLCD, 60,110);
  qrFillRect(myGLCD, 50,110);
  qrFillRect(myGLCD, 40,110);  
  qrFillRect(myGLCD, 30,110);
  qrFillRect(myGLCD, 20,110);
  //TOP RIGHT OUTER BOX END
  
  //TOP RIGHT INNER BOX START
  qrFillRect(myGLCD, 30,90);
  qrFillRect(myGLCD, 30,80);
  qrFillRect(myGLCD, 30,70);

  qrFillRect(myGLCD, 40,90);
  qrFillRect(myGLCD, 40,80);
  qrFillRect(myGLCD, 40,70);

  qrFillRect(myGLCD, 50,90);
  qrFillRect(myGLCD, 50,80);
  qrFillRect(myGLCD, 50,70);
  //TOP RIGHT INNER BOX END
  
  
  //BOTTOM RIGHT OUTER BOX START
  qrFillRect(myGLCD, 210,250);
  qrFillRect(myGLCD, 200,250);
  qrFillRect(myGLCD, 190,250);
  qrFillRect(myGLCD, 180,250);
  qrFillRect(myGLCD, 170,250);
  qrFillRect(myGLCD, 160,250);
  qrFillRect(myGLCD, 150,250);

  qrFillRect(myGLCD, 210,240);
  qrFillRect(myGLCD, 210,230);
  qrFillRect(myGLCD, 210,220);
  qrFillRect(myGLCD, 210,210);
  qrFillRect(myGLCD, 210,200);
  qrFillRect(myGLCD, 210,190);

  qrFillRect(myGLCD, 200,190);
  qrFillRect(myGLCD, 190,190);
  qrFillRect(myGLCD, 180,190);
  qrFillRect(myGLCD, 170,190);
  qrFillRect(myGLCD, 160,190);
  qrFillRect(myGLCD, 150,190);

  qrFillRect(myGLCD, 150,200);
  qrFillRect(myGLCD, 150,210);
  qrFillRect(myGLCD, 150,220);
  qrFillRect(myGLCD, 150,230);
  qrFillRect(myGLCD, 150,240);
   //BOTTOM RIGHT OUTER BOX END
  
  //BOTTOM RIGHT INNER BOX START
  qrFillRect(myGLCD, 170,230);
  qrFillRect(myGLCD, 170,220);
  qrFillRect(myGLCD, 170,210);
  
  qrFillRect(myGLCD, 180,230);
  qrFillRect(myGLCD, 180,220);
  qrFillRect(myGLCD, 180,210);

  qrFillRect(myGLCD, 190,230);
  qrFillRect(myGLCD, 190,220);
  qrFillRect(myGLCD, 190,210);
  //BOTTOM RIGHT INNER BOX END

  //Timing Pattern
   qrFillRect(myGLCD, 70,170);
   qrFillRect(myGLCD, 70,150);
   qrFillRect(myGLCD, 70,130);

   qrFillRect(myGLCD, 90,190);
   qrFillRect(myGLCD, 110,190);
   qrFillRect(myGLCD, 130,190);

   qrFillRect(myGLCD, 140,170);
   //end Timing Pattern

}
