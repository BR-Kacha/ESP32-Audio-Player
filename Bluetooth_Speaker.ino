//Created by Brijraj Kacha - (VU2AXQ)
//Have a Happy and Healthy Development!

#include "BluetoothA2DPSink.h"
unsigned char play_pause = 22;
unsigned char next = 17;
unsigned char prev = 16;
bool status = true;

BluetoothA2DPSink a2dp_sink;

void setup() {
    i2s_pin_config_t my_pin_config = {
        .bck_io_num = 27, ////BCLK 
        .ws_io_num = 26,  ////LRC pin 
        .data_out_num = 25, ///Din pin
        .data_in_num = I2S_PIN_NO_CHANGE
    };
    a2dp_sink.set_pin_config(my_pin_config);
    a2dp_sink.start("MyMusic");
    Serial.begin(115200);
    pinMode(play_pause,INPUT);
    pinMode(prev,INPUT);
    pinMode(next,INPUT);
}     
void loop() {

if (digitalRead(prev) == true) {
  a2dp_sink.previous();
  Serial.println("Previous");
}

if (digitalRead(play_pause) == true) {
 // Serial.println("loop");
  if(status == true) {
      a2dp_sink.pause();
      status = false;
      Serial.println("Pause");
  }
  else if(status == false) {
      a2dp_sink.play();
      status = true;
      Serial.println("Play");
  } 
} 

if (digitalRead(next) == true) {
  a2dp_sink.next();
  Serial.println("Next");
}

while(digitalRead(next) == true || digitalRead(prev) == true || digitalRead(play_pause) == true);
delay(5);

}
