
### Non-Functional Requirements

Timing:

- The interrupt handler must complete within 20 µs under worst-case execution conditions.
- The control loop must be executed with a nominal period of 5 ms and a tolerance of ±1 %.
Memory:
- The module must not use more than 8 KB of RAM, including static allocation and stack usage.
- The module must not use dynamic memory allocation (e.g., malloc, calloc, realloc).
CPU Usage:
- The module must not exceed 15 % CPU usage at a 100 Hz update rate on the target platform.
Safety:
- The system must enter a defined safe state within 10 ms after a watchdog timeout.
