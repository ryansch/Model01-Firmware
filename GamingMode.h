#pragma once

#include "Kaleidoscope.h"

namespace kaleidoscope {
  class GamingMode : public kaleidoscope::Plugin {
    public:
      GamingMode(void) {}

      static uint8_t gamingLayer;

      EventHandlerResult beforeReportingState();

    private:
      void setGamingColors(void);
  };
}

extern kaleidoscope::GamingMode GamingMode;
