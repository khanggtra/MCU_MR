# The following variables contains the files used by the different stages of the build process.
set(Big_Project_MCU_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${Big_Project_MCU_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${Big_Project_MCU_default_default_XC8_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(Big_Project_MCU_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${Big_Project_MCU_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${Big_Project_MCU_default_default_XC8_FILE_TYPE_assemblePreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(Big_Project_MCU_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/app/app_commute/app_commute.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/app/app_control/app_control.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/app/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/drivers/DC motor/DC_Motor.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/drivers/Encoder/encoder.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/hal/hal_adc/hal_adc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/hal/hal_gpio/hal_gpio.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/hal/hal_pwm/hal_pwm.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/hal/hal_timer0/hal_timer0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/hal/hal_uart/hal_uart.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/project_config/fuse/fuse.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/sys/sys_config/sys_config.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/sys/sys_tick/sys_tick.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/utils/utils_pid/utils_pid.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../firmware/utils/utils_string/utils_string.c")
set_source_files_properties(${Big_Project_MCU_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(Big_Project_MCU_default_default_XC8_FILE_TYPE_link)
set(Big_Project_MCU_default_image_name "default.elf")
set(Big_Project_MCU_default_image_base_name "default")

# The output directory of the final image.
set(Big_Project_MCU_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/Big_Project_MCU")

# The full path to the final image.
set(Big_Project_MCU_default_full_path_to_image ${Big_Project_MCU_default_output_dir}/${Big_Project_MCU_default_image_name})

# Potential output file extensions
set(output_extensions
    .hex
    .hxl
    .mum
    .o
    .sdb
    .sym
    .cmf)
list(TRANSFORM output_extensions PREPEND "${Big_Project_MCU_default_output_dir}/${Big_Project_MCU_default_image_base_name}")
