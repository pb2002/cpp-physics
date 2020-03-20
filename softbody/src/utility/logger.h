/*
- src/logger.h -
Formal logging implementation
*/

#pragma once
#include <iostream> // used for printing
#include <ctime> // used for timestamp that isn't currently working

#define __now__ ctime(&std::time(0)) // doesn't work atm

// LOG_LEVELS
// ---------------------------
// Minimum log level to output
#define MIN_LOG_LEVEL 0

// Log level constants

#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_TRACE 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_WARN 3
#define LOG_LEVEL_ERROR 4
// ---------------------------
// Assertion macro
#define log_assert(c, m) if (!(c)) { log_err("Assertion Failed:\n" << m); __debugbreak(); }

#if MIN_LOG_LEVEL <= 0
// Log debug message
#define log_deb(x) std::cout << "[" << __FILE__ << "" << __FUNCTION__ << "] DEB: " << x << std::endl;
#else
// Log debug message (Currently non-functional due to log level)
#define log_deb(x)
#endif

#if MIN_LOG_LEVEL <= 1
// Log trace message
#define log_trc(x) std::cout << "[" << __FILE__ << "" << __FUNCTION__ << "] TRC: " << x << std::endl;
#else
// Log trace message (Currently non-functional due to log level)
#define log_trc(x)
#endif
// Log info message
#if MIN_LOG_LEVEL <= 2
#define log_inf(x) std::cout << "[" << __FILE__ << "" << __FUNCTION__ << "] INF: " << x << std::endl;
#else
// Log info message (Currently non-functional due to log level)
#define log_inf(x)
#endif

#if MIN_LOG_LEVEL <= 3
// Log warning message
#define log_wrn(x) std::cout << "[" << __FILE__ << "" << __FUNCTION__ << "] WRN: " << x << std::endl;
#else
// Log warning message (Currently non-functional due to log level)
#define log_wrn(x)
#endif
// Log error message
#define log_err(x) std::cout << "[" << __FILE__ << "" << __FUNCTION__ << "] ERR: " << x << std::endl;

