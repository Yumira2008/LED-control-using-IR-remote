#include<IRremote.h>

IRrecv irrecv(7);
decode_results results;

#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  irrecv.enableIRIn();

}

void loop() {
  // put your main code here, to run repeatedly:

  if(irrecv.decode(&results)){
    Serial.println(results.value,DEC);
    irrecv.resume();
  }
  delay(100);

  long val = results.value;

  if(val == 16724175){
    digitalWrite(led1,HIGH);
  }
  if(val == 16718055){
    digitalWrite(led2,HIGH);
  }
  if(val == 16743045){
    digitalWrite(led3,HIGH); 
  }
  if(val == 16716015){
    digitalWrite(led4,HIGH);
  }
  if(val == 16726215){
    digitalWrite(led5,HIGH);
  }
  if(val == 16738455){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
  }

}
