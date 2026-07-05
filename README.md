# Industrial Safety Monitoring System

A multithreaded C application that simulates an industrial safety monitoring system. This project leverages POSIX threads (`pthreads`) to concurrently manage sensor readings, system control, event logging, and a live terminal dashboard.

## Overview

The system simulates a hazardous industrial environment where machinery must be instantly stopped if a human enters a dangerous proximity. It constantly monitors:
- **Distance Sensor**: Measures the distance of objects near the machinery.
- **IR Sensor (Human Detection)**: Detects if a human is present in the vicinity.
- **Machine Status**: Controls the on/off state of the machinery based on safety protocols.

If a human is detected within the danger zone (distance < 50 cm), the system will automatically trigger a safety cutoff, shutting down the machine.

## Architecture

The application is built using four concurrent threads that share data via a thread-safe struct protected by a mutex lock:

1. **Sensor Thread (`sensor.c`)**: Simulates reading real-time values from the distance and IR sensors. Updates the shared system state.
2. **Control Thread (`control.c`)**: The safety logic unit. Constantly evaluates sensor data and immediately shuts down the machine if safety thresholds are breached (Human Detected AND Distance < 50cm).
3. **Logger Thread (`logger.c`)**: Periodically (every 5 seconds) logs the current system state, including timestamp, sensor readings, and machine status, to a local file (`events.log`).
4. **Dashboard Thread (`dashboard.c`)**: Provides a live, auto-refreshing terminal UI that displays the real-time status of all sensors and the machine.

## Prerequisites

To build and run this project, you will need:
- GCC (GNU Compiler Collection)
- Make
- POSIX compliant operating system (Linux, macOS, WSL on Windows) with `pthread` support.

## Build Instructions

The project includes a `Makefile` for easy compilation.

To build the project, open your terminal in the project root directory and run:

```bash
make
```

This will compile the source files and generate an executable named `monitor`.

To clean up compiled binaries:
```bash
make clean
```

## Running the Application

After building the project, execute the generated binary:

```bash
./monitor
```

You will see a live updating dashboard in your terminal:

```
===============================================
     INDUSTRIAL SAFETY MONITOR v1.0
===============================================

Distance Sensor : 42 cm
IR Sensor       : DETECTED
Danger Zone     : ACTIVE
Machine Status  : OFF

Threads Running : Sensor | Control | Logger | Dashboard

Press Ctrl+C to Exit
```

To stop the simulation, press `Ctrl+C`.

## File Structure

- `main.c` - Entry point, initializes mutex and spawns all application threads.
- `sensor.h` / `sensor.c` - Defines the shared data structure and sensor simulation logic.
- `control.h` / `control.c` - Implements the safety cutoff logic.
- `logger.h` / `logger.c` - Handles asynchronous file logging.
- `dashboard.h` / `dashboard.c` - Renders the live terminal interface.
- `Makefile` - Build configuration.
- `events.log` - Generated log file containing system history.

## Safety Protocol

- **Danger Zone**: A distance of less than 50 cm combined with human presence.
- **Action**: The control thread will immediately set `machineStatus = 0` (OFF) if the danger zone is active, preventing accidents.
