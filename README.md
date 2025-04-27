
# GPIO Button and LED Control with STM32

This project demonstrates GPIO control on an STM32 microcontroller, showcasing the interaction between a button input and two LEDs. It is designed to highlight basic embedded systems concepts such as GPIO configuration, button input handling, and LED output control.

## Overview

The project configures a button on pin **PA0** and two LEDs on **PD13** and **PD15**. The behavior is simple:
- When the button is pressed (PA0 is LOW), **LED6 (PD15)** blinks.
- When the button is released (PA0 is HIGH), **LED3 (PD13)** blinks.

The microcontroller's clock is enabled for GPIOA and GPIOD peripherals, and a basic delay function is used to control the blink timing of the LEDs.

## Features
- **GPIO Pin Configuration**: Configures pins for input (PA0) and output (PD13, PD15).
- **Button Input**: Detects whether the button is pressed or released using a pull-down resistor.
- **LED Output**: Controls two LEDs based on the button state.
- **Clock Management**: Enables clocks for GPIOA and GPIOD to allow interaction with their respective registers.
- **Simple Delay**: Implements a software delay for controlling the blink rate of the LEDs.

## Hardware Setup

- **Button**: Connected to **PA0** (input pin) with an internal pull-down resistor enabled.
- **LED6 (PD15)**: Connected to **PD15** (output pin), which blinks when the button is pressed.
- **LED3 (PD13)**: Connected to **PD13** (output pin), which blinks when the button is released.

## Code Explanation

### 1. **Clock Enable for GPIOA and GPIOD**  
```c
rcc_en->gpioa_en = 1;
rcc_en->gpiod_en = 1;
```
The clock for GPIOA and GPIOD peripherals is enabled to allow access to their registers.

### 2. **Button Configuration (PA0)**  
```c
gpioa_moder->pmode_0 = 0x0; // Input Mode
gpioa_pup->pup_0 = 0x1; // Pull-down 
```
PA0 is configured as an input pin with an internal pull-down resistor, which helps detect button presses.

### 3. **LED Configuration (PD13, PD15)**  
```c
gpiod_moder->pmode_13 = 0x1; // Output
gpiod_moder->pmode_15 = 0x1; // Output
```
PD13 and PD15 are configured as output pins for controlling the LEDs.

### 4. **Button Press Logic**  
```c
if (gpioa_idr->idr_0) { // Button pressed (PA0 LOW)
    gpiod_odr->odr_15 = 1; // Turn ON LED6 (PD15)
    delay();
    gpiod_odr->odr_15 = 0; // Turn OFF LED6
    delay();
}
```
When the button is pressed (PA0 is LOW), LED6 blinks. The software delay function ensures the LED stays on/off for a brief period.

### 5. **Button Release Logic**  
```c
else { // Button released (PA0 HIGH)
    gpiod_odr->odr_13 = 1; // Turn ON LED3 (PD13)
    delay();
    gpiod_odr->odr_13 = 0; // Turn OFF LED3
    delay();
}
```
When the button is released (PA0 is HIGH), LED3 blinks instead.

### 6. **Delay Function**  
```c
void delay(void) {
    for (uint32_t i = 0; i < 300000; i++);
}
```
A simple delay function is used to control the on/off duration of the LEDs.

## How to Use

1. **Hardware Setup**:
   - Connect a button to PA0 and configure it to pull down.
   - Connect LEDs to PD13 and PD15 for output control.

2. **Compilation**:
   - Compile the code using your preferred STM32 development toolchain (e.g., STM32CubeIDE or Keil).

3. **Flashing**:
   - Flash the compiled firmware onto the STM32 microcontroller.

4. **Testing**:
   - Press the button and observe the LEDs:
     - **LED6 (PD15)** blinks when the button is pressed.
     - **LED3 (PD13)** blinks when the button is released.

## Conclusion

This project is a simple demonstration of basic embedded systems programming with an STM32 microcontroller. It helps understand GPIO pin configuration, input handling, and output control, which are fundamental in embedded system development. The project can be extended by incorporating interrupts, debouncing mechanisms, or more advanced features.
