# LTC2943 Driver
LTC2943 IC is Multicell Battery Gas Gauge with Temperature, Voltage and Current Measurement.
[datasheet here](https://www.analog.com/media/en/technical-documentation/data-sheets/2943fa.pdf)

## Functionality
- read status register
- set/get control register
- set/get ADC modes
- temperature alert check
- voltage alert check

## Build and Run LTC2943Tests
```shell
$ mkdir build
```
```shell
$ cd build
```
```shell
$ cmake ../ & make
```
```shell
$ ./tests/LTC2943Tests
```
> this is my very first cmake project with googletests

## Build Tools used
- cmake, GCC (GNU compiler)
- vscode with C/C++, cmake tools extensions
- googletests library
