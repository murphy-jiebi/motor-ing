class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
  private:
    int _pin;
    int _dottime;
};
Morse morse(13);
String comdata ="";
int count =0;
void setup()
{
  Serial.begin(9600);
}

//**** */*-** ** *- -* --*
void loop()
{
  while(Serial.available()>0)
  {
    comdata += char(Serial.read());
    delay(2);
    count +=1;
  }
  for(int i=0;i<=count;i++)
  {
   switch(comdata[i])
  {
    case 'a': morse.dot();morse.dash(); break;
    case 'b': morse.dash();morse.dot();morse.dot();morse.dot();break;
    case 'c': morse.dash();morse.dot();morse.dash();morse.dot();break;
    case 'd': morse.dash();morse.dot();morse.dot(); break;
    case 'e': morse.dot();break;
    case 'f': morse.dot();morse.dot();morse.dash();morse.dot();break;
    case 'g': morse.dash();morse.dash();morse.dot();break;
    case 'h': morse.dot();morse.dot();morse.dot();morse.dot();break;
    case 'i': morse.dot();morse.dot();break;
    case 'j': morse.dot();morse.dash();morse.dash();morse.dash();break;
    case 'k': morse.dash();morse.dot();morse.dash();break;
    case 'l': morse.dot();morse.dash();morse.dot();morse.dot();break;
    case 'm': morse.dash();morse.dash();break;
    case 'n': morse.dash();morse.dot();break;
    case 'o': morse.dash();morse.dash();morse.dash();break;
    case 'p': morse.dot();morse.dash();morse.dash();morse.dot();break;
    case 'q': morse.dash();morse.dash();morse.dot();morse.dash();break;
    case 'r': morse.dot();morse.dash();morse.dot();break;
    case 's': morse.dot();morse.dot();morse.dot();morse.dot();break;
    case 't': morse.dash();break;
    case 'u': morse.dot();morse.dot();morse.dash();break;
    case 'v': morse.dot();morse.dot();morse.dot();morse.dash();break;
    case 'w': morse.dot();morse.dash();morse.dash();break;
    case 'x': morse.dash();morse.dot();morse.dot();morse.dash();break;
    case 'y': morse.dash();morse.dot();morse.dash();morse.dash();break;
    case 'z': morse.dash();morse.dash();morse.dot();morse.dot();break;
    default:  break;      
  }
  delay(200);
  }

  delay(3000);
}
Morse::Morse(int pin)
{
  pinMode(pin,OUTPUT);
  _pin=pin;
  _dottime=250;
}

void Morse::dot()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morse::dash()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime*4);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morse::c_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*3);
}

void Morse::w_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*7);
}
