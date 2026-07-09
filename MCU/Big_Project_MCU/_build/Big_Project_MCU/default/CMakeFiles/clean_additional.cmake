# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "D:\\Documents\\Study\\Microcontroller\\BTL\\Big_Project_MCU\\out\\Big_Project_MCU\\default.cmf"
  "D:\\Documents\\Study\\Microcontroller\\BTL\\Big_Project_MCU\\out\\Big_Project_MCU\\default.hex"
  "D:\\Documents\\Study\\Microcontroller\\BTL\\Big_Project_MCU\\out\\Big_Project_MCU\\default.hxl"
  "D:\\Documents\\Study\\Microcontroller\\BTL\\Big_Project_MCU\\out\\Big_Project_MCU\\default.mum"
  "D:\\Documents\\Study\\Microcontroller\\BTL\\Big_Project_MCU\\out\\Big_Project_MCU\\default.o"
  "D:\\Documents\\Study\\Microcontroller\\BTL\\Big_Project_MCU\\out\\Big_Project_MCU\\default.sdb"
  "D:\\Documents\\Study\\Microcontroller\\BTL\\Big_Project_MCU\\out\\Big_Project_MCU\\default.sym"
  )
endif()
