
#include "scheduler.h"
#include "switch.h"
#include "ppg.h"

// pin:
#define SWITCH_PIN_1 33
#define SWITCH_PIN_2 34
#define RED_LED_PIN 32 
#define BLUE_LED_PIN 13 
#define GREEN_LED_PIN 26 
//#define SENSOR_PIN 25 // defined in ppg.h


// const:
#define DEBOUNCE_CNT 5 
#define BAUD 115200 
#define BUFFER_LENGTH 50 // two seconds

// variables:
int threshold = 1600;
uint8_t low_pulse_threshold = 50;
uint8_t high_pulse_threshold = 100;
float pulse_rate = 0.0;

// flags
bool device_status = false;
bool ppg_trigger = false;
uint8_t pulse_warning = NORMAL; // defined in ppg.h
bool pulse_train = false;

// classes:
Scheduler scheduler(20); // Create a scheduler with a 20ms interval

Button device_switch(1, DEBOUNCE_CNT, SWITCH_PIN_1);
Button ppg_switch(2, DEBOUNCE_CNT, SWITCH_PIN_2);

PPG ppg_1(threshold, low_pulse_threshold, high_pulse_threshold);

void task1() {
  device_switch.inputParse();
  ppg_switch.inputParse();
  device_status = device_switch.getLatch();
  ppg_trigger = ppg_switch.getLatch();
}

void task2() {
  if (device_status) {
//    Serial.println("\n Device is on. \n");
    
    if (ppg_trigger) {
//        Serial.println("\n Measuring PPG. \n");
        ppg_1.run();
        pulse_rate = ppg_1.getPulseRate();
        pulse_train = ppg_1.getPulseTrain();
        // if (pulse_train) >>> blink LED
    }
    
  }
  else {
//    Serial.println("\n Device is turned off. \n");
    ppg_trigger = false;
  }

}

void setup() {
  // Add tasks to the scheduler
  scheduler.addTask(task1);
  scheduler.addTask(task2);
  scheduler.initLastTick();

  pinMode(SWITCH_PIN_1, INPUT);
  pinMode(SWITCH_PIN_2, INPUT);
  pinMode(SENSOR_PIN, INPUT);
  
  // Other setup code
  Serial.begin(BAUD);
  Serial.println("\nTestScheduler\n");
}

void loop() {
  // Run the scheduler
  scheduler.run();
  // Other loop code
  
}
