## Introduction
> This example is about applying local AI on the MCU with the support of TensorFlow lite.

The AI model can recognize two voice commands 'YES' and 'NO'.
The input data to the AI model can either be a pre-stored Audio data, or realtime data from the ADC, which measures the voltage from a microphone.


## Build
```
git submodule update --init
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
make
```

## Acknowledgemen
- pico-work
	- https://github.com/iwatake2222/pico-work