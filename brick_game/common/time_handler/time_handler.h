/**
 * @file time_handler.h
 * @brief This file contains the declaration of the function for getting the
 * current time in milliseconds.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_TIME_HANDLER_TIME_HANDLER_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_TIME_HANDLER_TIME_HANDLER_H_

#include <sys/time.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get the current time in milliseconds.
 *
 * @return The current time in milliseconds.
 */
long long getTimeInMS();

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_TIME_HANDLER_TIME_HANDLER_H_
