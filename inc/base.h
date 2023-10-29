#pragma once

//
// CONFIG - pass as -DFOO=1 to the script
//

#ifndef NWSERVER
#define NWSERVER ./nwserver-linux
#endif

#ifndef NWSERVER_NAME
#define NWSERVER_NAME "nwserver-linux"
#endif

#ifndef INTERACTIVE
#define INTERACTIVE 0
#endif

#define LOG_LEVEL_DEBUG   7
#define LOG_LEVEL_INFO    6
#define LOG_LEVEL_NOTICE  5
#define LOG_LEVEL_WARNING 4
#define LOG_LEVEL_ERROR   3
#define LOG_LEVEL_FATAL   2

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_NOTICE
#endif

// The macros need to contain the ;, and be invoked without it, as
// INFO("Foo") since bpftrace doesn't allow for a simple way to consume stray ;
#if LOG_LEVEL >= LOG_LEVEL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__);
#else
#define DEBUG(...)
#endif
#if LOG_LEVEL >= LOG_LEVEL_INFO
#define INFO(...) printf(__VA_ARGS__);
#else
#define INFO(...)
#endif
#if LOG_LEVEL >= LOG_LEVEL_NOTICE
#define NOTICE(...) printf(__VA_ARGS__);
#else
#define NOTICE(...)
#endif
#if LOG_LEVEL >= LOG_LEVEL_WARNING
#define WARNING(...) printf(__VA_ARGS__);
#else
#define WARNING(...)
#endif
#if LOG_LEVEL >= LOG_LEVEL_ERROR
#define ERROR(...) printf(__VA_ARGS__);
#else
#define ERROR(...)
#endif
#if LOG_LEVEL >= LOG_LEVEL_FATAL
#define FATAL(...) printf(__VA_ARGS__); exit();
#else
#define FATAL(...)
#endif


#define NSEC_TO_SEC(ns) ((ns) / 1000000000)
