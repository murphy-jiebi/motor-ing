void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, OUTPUT);//ledt
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);//right
  Serial.begin(9600);
}
int income=0;
void loop()
{
	if(Serial.available()>0)
    {
    	income=Serial.read();
      	switch(income)
        {
        	case 'f':
          		forward();
          		break;
          	case 'b':
          		backward();
          		break;
          	case 'l':
          		left();
          		break;
          	case 'r':
          		right();
          		break;
          	case 's':
          		stop();
          		break;
          	default:
          		break;
        }
    }
}

void forward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}

void backward()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}

void left()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  while(0)
  {
  digitalWrite(12,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(2,LOW);
  }
}

void right()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
   while(0)
  {
  digitalWrite(13,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(4,LOW);
  }
}

void stop()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}
