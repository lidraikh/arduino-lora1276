# A Mongoose OS library for Lora1276 module by NiceRF 


## Overview

This library is intended to use library of lora1276 by NiceRF for arduino with mongoos os.

### Usage

mos.yml, add:
```
config_schema:
 - ["", ]
libs:
 - origin: https://github.com/lidraikh/Lora1276/
  ```
  
  main.c, add:
```
#include
init.js, add: (Coming later)
```
load('lora1276.js');
```
[ (JavaScript) usage example](https://github.com/mongoose-os-apps/example-arduino-adafruit-ads1x15-js)

 "mgos_arduino_lora1276.h"
```
