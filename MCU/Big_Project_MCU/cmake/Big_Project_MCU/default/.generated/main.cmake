include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Big_Project_MCU_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(Big_Project_MCU_default_default_XC8_FILE_TYPE_assemble)
add_library(Big_Project_MCU_default_default_XC8_assemble OBJECT ${Big_Project_MCU_default_default_XC8_FILE_TYPE_assemble})
    Big_Project_MCU_default_default_XC8_assemble_rule(Big_Project_MCU_default_default_XC8_assemble)
    list(APPEND Big_Project_MCU_default_library_list "$<TARGET_OBJECTS:Big_Project_MCU_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(Big_Project_MCU_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(Big_Project_MCU_default_default_XC8_assemblePreprocess OBJECT ${Big_Project_MCU_default_default_XC8_FILE_TYPE_assemblePreprocess})
    Big_Project_MCU_default_default_XC8_assemblePreprocess_rule(Big_Project_MCU_default_default_XC8_assemblePreprocess)
    list(APPEND Big_Project_MCU_default_library_list "$<TARGET_OBJECTS:Big_Project_MCU_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(Big_Project_MCU_default_default_XC8_FILE_TYPE_compile)
add_library(Big_Project_MCU_default_default_XC8_compile OBJECT ${Big_Project_MCU_default_default_XC8_FILE_TYPE_compile})
    Big_Project_MCU_default_default_XC8_compile_rule(Big_Project_MCU_default_default_XC8_compile)
    list(APPEND Big_Project_MCU_default_library_list "$<TARGET_OBJECTS:Big_Project_MCU_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(Big_Project_MCU_default_image_qAeg3d78 ${Big_Project_MCU_default_library_list})

set_target_properties(Big_Project_MCU_default_image_qAeg3d78 PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${Big_Project_MCU_default_output_dir}")
target_link_libraries(Big_Project_MCU_default_image_qAeg3d78 PRIVATE ${Big_Project_MCU_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
Big_Project_MCU_default_link_rule( Big_Project_MCU_default_image_qAeg3d78)


