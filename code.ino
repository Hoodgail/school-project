// C++ Arduino Test Bed
//

#include <Servo.h> //include servo library

Servo LeftJaw;
Servo RightJaw;

// Eyes pins
int LeftEye = 5;
int RightEye = 6;

// Jaws pins
int LeftJawPin = 1;
int RightJawPin = 2;

int Echo = 4;
int Trigger = 3;

int TriggerRead = 0;
int Toggle = 0;

// The rotations of both jaws.
int JawSpin = 0;

void setup() {

    LeftJaw.attach(LeftJawPin);
    RightJaw.attach(RightJawPin);

    pinMode(LeftJawPin, OUTPUT);
    pinMode(RightJawPin, OUTPUT);

    pinMode(LeftEye, OUTPUT);
    pinMode(RightEye, OUTPUT);

    pinMode(Trigger, INPUT);

    Serial.begin(9600);
}

void TurnEyesOn() {
    digitalWrite(LeftEye, HIGH);
    digitalWrite(RightEye, HIGH);
}

void TurnEyesOff() {
    digitalWrite(LeftEye, LOW);
    digitalWrite(RightEye, LOW);
}

void UpdateJaws(rotation: int) {
    LeftJaw.write(rotation);
    RightJaw.write(rotation);
}

void loop() {

    TriggerRead = digitalRead(Trigger);

    if (TriggerRead == 1) {

        if (Toggle == 0) {
            TurnEyesOn();
            UpdateJaws(90);
            Toggle = 1;
        }

        else {
            TurnEyesOff();
            UpdateJaws(0);
            Toggle = 0;
        }

        delay(250);
    }
}