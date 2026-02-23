# Common Embedded Mistakes

## Avoid the following

- Hidden or undocumented timing assumptions
- Undefined behavior in edge or fault conditions
- Missing error states or undefined error handling
- Missing units in numerical requirements
- Undefined calling context (ISR, task, thread-safe)

### Bad

> The function must not block
Problem: `block` is non-measurable

### Better

> The function must return within 50 µs and must not wait for hardware events.
