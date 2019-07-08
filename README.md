# A Mongoose OS library for Lora1276 module by NiceRF 


## Overview

This library is intended to use library of lora1276 by NiceRF for arduino with mongoos os.

### Usage

mos.yml, add:
```
config_schema:
 - ["", ]
libs:
 - origin: https://github.com/lidraikh/arduino-lora1276
  ```
  
  main.c, add:
```
#include "mgos_arduino_lora1276.h"
```
