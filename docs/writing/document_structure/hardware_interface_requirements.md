
### Hardware Interface Requirements

Hardware interface requirements should define how the software interacts with the underlying hardware.

- GPIO direction and behavior.
- ADC resolution.
- SPI/I2C configuration.
- CAN frame format.
- Interrupt usage.
Example:

> The SPI interface must operate as master in Mode 0 at a clock frequency of 1 MHz.
> The module must transmit a CAN frame with standard ID 0x123 and a period of 100 ms.
