# ARM_STM32F401CCU6_IR_MUSIC_PLAYER
## Description:
This project is an embedded software application for an ARM-based STM32F401CCU6 microcontroller, serving as an IR Music Player. It employs a layered architecture, featuring Microcontroller Abstraction Layer (MCAL), Hardware Abstraction Layer (HAL), and Application Layer.

## Features:
### 1) MCAL Layer:
Utilizes core functionalities of the microcontroller, including RCC (Reset and Clock Control), GPIO (General Purpose Input/Output), EXTI (External Interrupt), NVIC (Nested Vector Interrupt Controller), SYSTICK, and TIMERS.
### 2) HAL Layer:
Interfaces with various hardware components:
IR (Infrared) module for remote control functionality.
DAC (Digital to Analog Converter) for audio output.
TFT (Thin-Film Transistor) display for graphical user interface.
Serial to parallel interface for LED matrix control.
### 3) Application Layer:
Implements high-level functions to facilitate user interaction:
Switching between songs and pictures displayed on the TFT screen.
Response to button presses on the IR Remote controller.
Setup and Installation:

## Requirements:
- STM32F401CCU6 development board.
- Necessary development tools such as STM32CubeIDE, STM32CubeMX, or equivalent.
- IR Remote controller compatible with the project.
- DAC, TFT, and LED Matrix connected to appropriate pins of the STM32F401CCU6.

## Configuration:

Configure the project in STM32CubeMX or equivalent tool, ensuring correct pin mappings and peripheral configurations.
Import the project into your development environment.

## Building and Flashing:
Build the project using your preferred IDE.
Flash the compiled binary onto the STM32F401CCU6 development board.

## Usage:
Power up the STM32F401CCU6 development board.
Ensure all peripherals and hardware components are connected properly.
Use the IR Remote controller to interact with the application:
Press buttons to navigate through songs and pictures displayed on the TFT.
Observe the corresponding actions on the display and audio output.

## Contributors:
Mohammed Nagah Amr - Embedded Software Engineer

## License:
MIT License

