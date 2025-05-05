#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"
#include "weather_utils.h"

int historical_min_temp(WeatherTable a) {

    int min = a[0][january][0]._min_temp;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (a[year][month][day]._min_temp < min) {
                    min = a[year][month][day]._min_temp;
                }
            }
        }
    }
    return min;
}

void max_temp_year(WeatherTable a, int output[YEARS]) {

    for (unsigned int year = 0u; year < YEARS; ++year) {
        int max = a[year][january][0]._max_temp;
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (a[year][month][day]._max_temp > max) {
                    max = a[year][month][day]._max_temp;
                }
            }
        }
        output[year] = max;
    }
}

void month_max_rainfall(WeatherTable a, month_t output[YEARS]) {

    for (unsigned int year = 0u; year < YEARS; ++year) {
        month_t month_max_rain = january;
        unsigned int max_rain = 0, sum_rain = 0;
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                sum_rain = sum_rain + a[year][month][day]._rainfall;
                if (sum_rain > max_rain) {
                    max_rain = sum_rain;
                    month_max_rain = month;
                }
            }
        }
        output[year] = month_max_rain;
    }
}