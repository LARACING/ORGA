# C API Documentation

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
