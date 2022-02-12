//the selector button will cycle between modes that will be displayed on the 7segment display:
//1 - AND
//2 - OR
//3 - XOR
//4 - NAND
//5 - NOR
//6 - XNOR
//
//the two other buttons will work as inputs for the logic gates funcion.
//the left and right leds will light with the button pressing, and the middle led will display the funcion result.
//
//Needed:
//Arduino (Micro in my case)
//3 buttons
//3 leds
//1 seven segment display (common cathode)
//several resistors and wires





int selector = 4;
int lbutton = 5;
int rbutton = 6;
int lled = 13;
int rled = 22;
int mled = 23;

//7 segment display
int displaya = 19;
int displayb = 18;
int displayc = 11;
int displayd = 7;
int displaye = 12;
int displayf = 20;
int displayg = 21;


int lbuttonstate = 0;
int rbuttonstate = 0;
int selectorstate = 0;


int logic = 0;


void setup() {

  pinMode (selector, INPUT);
  pinMode (lbutton, INPUT);
  pinMode (rbutton, INPUT);
  pinMode (lled, OUTPUT);
  pinMode (rled, OUTPUT);
  pinMode (mled, OUTPUT);
  pinMode (displaya, OUTPUT);
  pinMode (displayb, OUTPUT);
  pinMode (displayc, OUTPUT);
  pinMode (displayd, OUTPUT);
  pinMode (displaye, OUTPUT);
  pinMode (displayf, OUTPUT);
  pinMode (displayg, OUTPUT);

}


void loop() {

  selectorstate = digitalRead(selector);
  lbuttonstate = digitalRead(lbutton);
  rbuttonstate = digitalRead(rbutton);


//logic state selector. Note that although the 7 segment will show states 1 to 6, they're really 0 to 5 here (yes, in hindsight i could have simplified it. Maybe i will.

  if (logic < 5) {
    if (selectorstate == HIGH) {
      logic += 1;
      delay(500);
    }
    else if (selectorstate == LOW)
    {
      logic = logic;
    }
  }
  else
  {
    if (selectorstate == HIGH) {
      logic = 0;
      delay(500);
    } else if (selectorstate == LOW) {
      logic = logic;
    }
  }


  if (lbuttonstate == HIGH) {
    digitalWrite(lled, HIGH);
  } else {
    digitalWrite(lled, LOW);
  }

  if (rbuttonstate == HIGH) {
    digitalWrite(rled, HIGH);
  } else {
    digitalWrite(rled, LOW);
  }

  if (logic == 0) { //and

    sevensegone();

    if (lbuttonstate == HIGH & rbuttonstate == HIGH) {
      digitalWrite(mled, HIGH);
    } else {
      digitalWrite(mled, LOW);
    }
  }

  if (logic == 1) { //or

    sevensegtwo();

    if (lbuttonstate == HIGH | rbuttonstate == HIGH) {
      digitalWrite(mled, HIGH);
    } else {
      digitalWrite(mled, LOW);
    }
  }

  if (logic == 2) { //xor

    sevensegthree();

    if (lbuttonstate == HIGH ^ rbuttonstate == HIGH) {
      digitalWrite(mled, HIGH);
    } else {
      digitalWrite(mled, LOW);
    }
  }

  if (logic == 3) { //nand

    sevensegfour();

    if (!(lbuttonstate == HIGH & rbuttonstate == HIGH)) {
      digitalWrite(mled, HIGH);
    } else {
      digitalWrite(mled, LOW);
    }
  }

  if (logic == 4) { //nor

    sevensegfive();

    if (!(lbuttonstate == HIGH | rbuttonstate == HIGH)) {
      digitalWrite(mled, HIGH);
    } else {
      digitalWrite(mled, LOW);
    }
  }

  if (logic == 5) { //xnor

    sevensegsix();

    if (!(lbuttonstate == HIGH ^ rbuttonstate == HIGH)) {
      digitalWrite(mled, HIGH);
    } else {
      digitalWrite(mled, LOW);
    }
  }
}

//the following functions will enable the use of the 7 segment display without added libraries. I only did it to 6, as there's no need for more in this code.

void clear7seg(void) {
  digitalWrite(displaya, LOW);
  digitalWrite(displayb, LOW);
  digitalWrite(displayc, LOW);
  digitalWrite(displayd, LOW);
  digitalWrite(displaye, LOW);
  digitalWrite(displayf, LOW);
  digitalWrite(displayg, LOW);


}

void sevensegone(void) {
  clear7seg();
  digitalWrite(displayb, HIGH);
  digitalWrite(displayc, HIGH);
}

void sevensegtwo(void) {
  clear7seg();
  digitalWrite(displaya, HIGH);
  digitalWrite(displayb, HIGH);
  digitalWrite(displayd, HIGH);
  digitalWrite(displaye, HIGH);
  digitalWrite(displayg, HIGH);

}

void sevensegthree(void) {
  clear7seg();
  digitalWrite(displaya, HIGH);
  digitalWrite(displayb, HIGH);
  digitalWrite(displayc, HIGH);
  digitalWrite(displayd, HIGH);
  digitalWrite(displayg, HIGH);

}

void sevensegfour(void) {
  clear7seg();
  digitalWrite(displayb, HIGH);
  digitalWrite(displayc, HIGH);
  digitalWrite(displayf, HIGH);
  digitalWrite(displayg, HIGH);

}

void sevensegfive(void) {
  clear7seg();
  digitalWrite(displaya, HIGH);
  digitalWrite(displayc, HIGH);
  digitalWrite(displayd, HIGH);
  digitalWrite(displayf, HIGH);
  digitalWrite(displayg, HIGH);

}

void sevensegsix(void) {
  clear7seg();
  digitalWrite(displaya, HIGH);
  digitalWrite(displayc, HIGH);
  digitalWrite(displayd, HIGH);
  digitalWrite(displaye, HIGH);
  digitalWrite(displayf, HIGH);
  digitalWrite(displayg, HIGH);

}
