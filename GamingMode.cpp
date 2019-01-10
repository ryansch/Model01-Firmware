#include "GamingMode.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-SpaceCadet.h"

namespace kaleidoscope {
  uint8_t GamingMode::gamingLayer;

  void GamingMode::setGamingColors() {
    ::LEDControl.set_all_leds_to(CRGB(0, 0, 170));

    ::LEDControl.setCrgbAt(1, 2, CRGB(170, 0, 0)); // w
    ::LEDControl.setCrgbAt(2, 1, CRGB(170, 0, 0)); // a
    ::LEDControl.setCrgbAt(2, 2, CRGB(170, 0, 0)); // s
    ::LEDControl.setCrgbAt(2, 3, CRGB(170, 0, 0)); // d

    ::LEDControl.setCrgbAt(3, 7, CRGB(203, 101, 0)); // shift
    ::LEDControl.setCrgbAt(2, 0, CRGB(203, 101, 0)); // shift (pgup)

    ::LEDControl.setCrgbAt(0, 7, CRGB(0, 160, 0)); // control
    ::LEDControl.setCrgbAt(3, 0, CRGB(0, 160, 0)); // control (pgdn)

    ::LEDControl.setCrgbAt(1, 7, CRGB(0, 160, 160)); // space (backspace)
    ::LEDControl.setCrgbAt(2, 7, CRGB(0, 160, 160)); // alt (cmd)
  }

  EventHandlerResult GamingMode::beforeReportingState() {
    if (Layer.isActive(gamingLayer)) {
      ::SpaceCadet.disable();
      setGamingColors();
    } else {
      ::SpaceCadet.enable();
    }

    return EventHandlerResult::OK;
  }
}

kaleidoscope::GamingMode GamingMode;
