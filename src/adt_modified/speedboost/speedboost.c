#include "speedboost.h"

void resetSpeedboost(Speedboost *s)
{
  SB_ISACTIVE(*s) = false;
  SB_COUNTER(*s) = 1;
}