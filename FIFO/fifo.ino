#include <QueueArray.h> // Manage FIFO
#include <JeeLib.h> // Low power functions library
#include <MemoryFree.h>

ISR(WDT_vect) { Sleepy::watchdogEvent(); } // Setup the watchdog
QueueArray <int> queue;
int counter = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);

  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  

  if(freeMemory() > 622) {

    digitalWrite(12, HIGH);
    
    queue.enqueue (random(10));

    digitalWrite(12, LOW);
    
  } else {

    digitalWrite(13, HIGH);
    
    Serial.print("Memory is full, trying to make some space.");

    Serial.print("freeMemory() before=");
    Serial.println(freeMemory());

    
    while(!queue.isEmpty()) {
      queue.dequeue();
    }

    Serial.print("freeMemory() after=");
    Serial.println(freeMemory());

    delay(10000);

    digitalWrite(13, LOW);
  }

  counter++;

  Serial.print("freeMemory()=");
  Serial.println(freeMemory());
  
  Serial.print("counter=");
  Serial.println(counter);

  //Sleepy::loseSomeTime(1000);
  //delay(100);
  
}
