// XBOX Controller Joystick for X68000 Z
#include <Joystick.h>
#include <XBOXONE.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
XBOXONE Xbox(&Usb);

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
  12, 1,                  // Button Count, Hat Switch Count
  false, false, false,   // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

static bool r_b = false;
static bool r_a = false;
static bool k_b = false;
static bool k_a = false;
static unsigned long time_b = millis();
static unsigned long time_a = millis();

void setup() {
  if (Usb.Init() == -1) {
    while (1); //halt
  }
  Joystick.begin();
}
void loop() {
  unsigned long time = millis();

  Usb.Task();
  if (Xbox.XboxOneConnected) {
    bool up    = false;
    bool down  = false;
    bool left  = false;
    bool right = false;
    int16_t hat = JOYSTICK_HATSWITCH_RELEASE;
    if (Xbox.getButtonPress(UP) || (Xbox.getAnalogHat(LeftHatY) > 7500)) {
      up = true;
    }
    if (Xbox.getButtonPress(DOWN) || (Xbox.getAnalogHat(LeftHatY) < -7500)) {
      down = true;
    }
    if (Xbox.getButtonPress(LEFT) || (Xbox.getAnalogHat(LeftHatX) < -7500)) {
      left = true;
    }
    if (Xbox.getButtonPress(RIGHT) || (Xbox.getAnalogHat(LeftHatX) > 7500)) {
      right = true;
    }
    if ( up && !down && !left && !right) {
      hat =   0;
    } else
    if ( up && !down && !left &&  right) {
      hat =  45;
    } else
    if (!up && !down && !left &&  right) {
      hat =  90;
    } else
    if (!up &&  down && !left &&  right) {
      hat = 135;
    } else
    if (!up &&  down && !left && !right) {
      hat = 180;
    } else
    if (!up &&  down &&  left && !right) {
      hat = 225;
    } else
    if (!up && !down &&  left && !right) {
      hat = 270;
    } else
    if ( up && !down &&  left && !right) {
      hat = 315;
    }
    Joystick.setHatSwitch(0, hat);

    if (Xbox.getButtonPress(A)) {
      if (!r_b) {
        Joystick.setButton(1, true);
        k_b = true;
      } else {
        if (time_b < time) {
          if (!k_b) {
            Joystick.setButton(1, true);
            k_b = true;
          } else {
            Joystick.setButton(1, false);
            k_b = false;
          }
          time_b = time + 33;
        }
      }
    } else {
      Joystick.setButton(1, false);
      k_b = false;
      if (r_b) {
        time_b = time;
      }
    }
    if (Xbox.getButtonPress(B)) {
      if (!r_a) {
        Joystick.setButton(2, true);
        k_a = true;
      } else {
        if (time_a < time) {
          if (!k_a) {
            Joystick.setButton(2, true);
            k_a = true;
          } else {
            Joystick.setButton(2, false);
            k_a = false;
          }
          time_a = time + 33;
        }
      }
    } else {
      Joystick.setButton(2, false);
      k_a = false;
      if (r_a) {
        time_a = time;
      }
    }

    if (Xbox.getButtonPress(RB)) {
      Joystick.setButton(5, true);
    } else {
      Joystick.setButton(5, false);
    }
    if (Xbox.getButtonPress(LB)) {
      Joystick.setButton(4, true);
    } else {
      Joystick.setButton(4, false);
    }

    if (Xbox.getButtonClick(X)) {
      if (!r_b) {
        time_b = time;
        r_b = true;
      } else {
        r_b = false;
      }
    }
    if (Xbox.getButtonClick(Y)) {
      if (!r_a) {
        time_a = time;
        r_a = true;
      } else {
        r_a = false;
      }
    }

    if (Xbox.getButtonPress(BACK)) {
      Joystick.setButton(8, true);
    } else {
      Joystick.setButton(8, false);
    }
    if (Xbox.getButtonPress(START)) {
      Joystick.setButton(9, true);
    } else {
      Joystick.setButton(9, false);
    }
  }

  delay(1);
}
