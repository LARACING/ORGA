# Naming Convention

## Table of Contents

- [Naming Convention](#naming-convention)
  - [Table of Contents](#table-of-contents)
  - [General Rules](#general-rules)
  - [Variables](#variables)
  - [Functions](#functions)
  - [Typedefs](#typedefs)
  - [Struct Members](#struct-members)
  - [Enums](#enums)
  - [Macros](#macros)
  - [Constants](#constants)
  - [Include Guards](#include-guards)
  - [Include Order](#include-order)
  - [File Naming](#file-naming)
  - [Pointer Style](#pointer-style)
  - [Visibility Rules](#visibility-rules)
  - [Booleans](#booleans)

## General Rules

- English names shall be used.
- Descriptive names like `total_amount` are preferred over
    abbreviations like `ta`.

------------------------------------------------------------------------

## Variables

- Use `snake_case`.

``` c
int total_amount;
float current_speed_rpm;
```

------------------------------------------------------------------------

## Functions

- Use `snake_case`.

``` c
int module_name_of_function(void) {
    return 0;
}
```

------------------------------------------------------------------------

## Typedefs

- Use `CamelCase` for structs, enums, and other typedefs.

``` c
typedef struct ExampleStruct {
    int example_int;
} ExampleStruct;
```

------------------------------------------------------------------------

## Struct Members

- Use `snake_case`.

``` c
typedef struct MotorController {
    int current_speed_rpm;
    int target_speed_rpm;
} MotorController;
```

## Enums

- Enum type name → `CamelCase`
- Enum values → `UPPER_CASE`
- Assign actual values to the enum values.

``` c
typedef enum SystemState {
    SYSTEM_STATE_INIT     = 0,
    SYSTEM_STATE_RUNNING  = 1,
    SYSTEM_STATE_ERROR    = 2
} SystemState;
```

## Macros

- Use `UPPER_CASE` with underscores.

``` c
#define MAX_BUFFER_SIZE 256
#define DEFAULT_TIMEOUT_MS 1000
#define MIN(a, b) ((a) < (b) ? (a) : (b))
```

## Constants

- Constants are treated like variables → `snake_case`.

``` c
static const int default_timeout_ms = 1000;
const float pi_approx = 3.1415926f;
```

## Include Guards

Every header file must use include guards.

- Uppercase
- File path based
- _H suffix
- No leading/trailing underscores
- No double underscores

```c
#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

/* content */

#endif /* MOTOR_CONTROLLER_H */
```

## Include Order

The include order shall be following.

1. Own header
2. C Standard libaries headers
3. Third-Party headers
4. Project headers

```c
#include "motor_controller.h"

#include <stdint.h>
#include <stdbool.h>

#include "can_bus.h"
#include "pwm_driver.h"
```

## File Naming

- File names use `snake_case`.
- One module per `.c` / `.h` pair.

Examples:

- `motor_controller.c`
- `motor_controller.h`
- `can_bus.c`
- `can_bus.h`

## Pointer Style

- The `*` belongs to the name.

``` c
int *buffer;
char *message;
const uint8_t *rx_data;
MotorController *controller;
```

## Visibility Rules

- Public API functions are declared in header files.
- Internal functions are declared `static` and remain inside the `.c`
    file.

## Booleans

- Use `<stdbool.h>`.

- Prefix boolean variables with:

  - `is_`
  - `has_`
  - `can_`
  - `should_`

``` c
bool is_initialized;
bool has_error;
```
