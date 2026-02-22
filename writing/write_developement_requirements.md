# Writing developement requirements for embedded systems

## Table of Contents

- [Writing developement requirements for embedded systems](#writing-developement-requirements-for-embedded-systems)
  - [Table of Contents](#table-of-contents)
  - [What should be covered?](#what-should-be-covered)
  - [General Writing Guidelines](#general-writing-guidelines)
    - [Writing Principles](#writing-principles)
    - [Avoid Ambiguity](#avoid-ambiguity)
    - [Normative Language](#normative-language)
      - [Must/Shall](#mustshall)
      - [Must Not/Shall Not](#must-notshall-not)
      - [Should/Recommend](#shouldrecommend)
      - [Should Not/Not Recommended](#should-notnot-recommended)
      - [May/Optional](#mayoptional)
    - [Use of TBD](#use-of-tbd)
  - [Document Structure](#document-structure)
  - [Functional Requirements](#functional-requirements)
  - [Non-Functional Requirements](#non-functional-requirements)
  - [Hardware Interface Requirements](#hardware-interface-requirements)
  - [C API Documentation](#c-api-documentation)
    - [API Design Principles](#api-design-principles)
    - [Example](#example)
      - [Requirements](#requirements)
      - [Result API](#result-api)
  - [Common Embedded Mistakes](#common-embedded-mistakes)
    - [Avoid the following](#avoid-the-following)
      - [Bad](#bad)
      - [Better](#better)
  - [Verification Strategy](#verification-strategy)
  - [Keep it Professional but readable](#keep-it-professional-but-readable)

## What should be covered?

For embedded systems requirements typically define:

- System behavior
- Timing constraints
- Hardware interaction
- Error handling
- Resource limitations
- Public C Interface (API)
They should describe what the software does, not how it does it.

## General Writing Guidelines

### Writing Principles

Requirements should be:

- Clear and unambiguous
- Measurable
- Testable
- Aware of hardware constraints
- Free from implementation details

### Avoid Ambiguity

Avoid using vague or subject terms such as:

- fast
- lightweight
- efficient
- stable
If performance or quality attributes are required, they should be expressed using measurable criteria.

### Normative Language

Requirements shall follow the terminology defined in RFC2119 with minor adaptations.
The following keywords indicate the level of a requirement.

#### Must/Shall

Indicates an absolute requirement. (“REQUIRED” may also be used)

#### Must Not/Shall Not

Indicates an absolute prohibition.

#### Should/Recommend

Indicates a strong recommendation. Valid reasons may exist to deviate, but the implications should be understood.

#### Should Not/Not Recommended

Indicates that a behavior is generally discouraged, but exceptions may exist.

#### May/Optional

Indicates that an item is optional.

### Use of TBD

TBD indicates that a detail has not yet been decided.
TBD items should be avoided where possible.
If used, additional context or expected directions should be provided in brackets.
TBD items can be highlighted by a red colorization.
> <span style="color: red;">TBD</span> (expected ADC resolution: 12-16 bit)

## Document Structure

A typical structure for an embedded requirements document may include:

1. Introduction
2. System Overview
3. Functional Requirements
4. Non-functional Requirements
5. Hardware Interface Requirements
6. Public C API Specifications
7. Constraints
8. Verification Strategy

## Functional Requirements

Functional requirements should describe the system’s behavior during normal operation and in defined edge or fault conditions.
Less precise:
> The module must sample the ADC every 1 ms.
More precise:
> The module must sample the ADC with a nominal period of 1 ms and a tolerance of ±5
The second version defines a measurable timing constraint and can be verified during testing.

## Non-Functional Requirements

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

## Hardware Interface Requirements

Hardware interface requirements should define how the software interacts with the underlying hardware.

- GPIO direction and behavior.
- ADC resolution.
- SPI/I2C configuration.
- CAN frame format.
- Interrupt usage.
Example:

> The SPI interface must operate as master in Mode 0 at a clock frequency of 1 MHz.
> The module must transmit a CAN frame with standard ID 0x123 and a period of 100 ms.

## C API Documentation

For embedded systems, the C API is part of the external interface.
The API documentation should define:

- Public functions.
- Parameters
- Return Values
- Units
- Error Handling
- Preconditions
- Postconditions

### API Design Principles

Good embedded APIs should:

- Be deterministic
- Avoid dynamic memory
- Avoid hidden blocking behavior
- Clearly define ownership of data
- Return explicit status codes.
- Functions should return status codes directly and provide additional output values via pointer parameters.

### Example

#### Requirements

- The module must provide an initialization function that configures internal state and validates configuration parameters.
- The function motor_update must complete execution within 200 µs ±10 %.
- All public functions must return a defined status code.

#### Result API

```c
#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

typedef enum MotorStatus {
    MOTOR_OK                    =  0,
    MOTOR_ERROR_INVALID_PARAM   = -1,
    MOTOR_ERROR_NOT_INITIALIZED = -2,
    MOTOR_ERROR_HW_FAILURE      = -3
} MotorStatus;

/**
 * @brief Initializes the motor module.
 *
 * @param config Pointer to configuration structure.
 *
 * @return MOTOR_OK if initialization was successful.
 *         MOTOR_ERROR_INVALID_PARAM if config is NULL.
 */
MotorStatus motor_init(const MotorConfig *config);

/**
 * @brief Executes one control cycle.
 *
 * Must be called every 5 ms.
 *
 * @return MOTOR_OK if execution completed successfully.
 */
MotorStatus motor_update(void);

#endif /* MOTOR_CONTROLLER_H */
```

## Common Embedded Mistakes

### Avoid the following

- Hidden or undocumented timing assumptions
- Undefined behavior in edge or fault conditions
- Missing error states or undefined error handling
- Missing units in numerical requirements
- Undefined calling context (ISR, task, thread-safe)

#### Bad
>
> The function must not block
Problem: `block` is non-measurable

#### Better
>
> The function must return within 50 µs and must not wait for hardware events.
>
## Verification Strategy

Each requirement should be verifiable via:

- Unit tests
- Integration tests
- Hardware tests/measurements
- Static analysis
- Code inspection
Example:

> Timing requirements must be verified using oscilloscope measurements or processor cycle counter analysis on the target.

## Keep it Professional but readable

This document serves as a guideline rather than a strict specification.
Its purpose is to promote clarity, consistency, and quality in embedded software requirements.
It is not intended to restrict reasonable engineering judgment.
Deviations are acceptable if they improve clarity or better suit the specific project context.
For example, if a tabular overview of all API functions including inputs and outputs improves readability, it should be used.
The document may be refined or adapted after internal review or peer feedback.
