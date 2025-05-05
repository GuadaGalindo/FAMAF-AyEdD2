#ifndef _WEATHER_UNTILS
#define _WEATHER_UNTILS

#include <stdbool.h>
#include "weather.h"
#include "array_helpers.h"

int historical_min_temp(WeatherTable a);

void max_temp_year(WeatherTable a, int output[YEARS]);

void month_max_rainfall(WeatherTable a, month_t output[YEARS]);

#endif