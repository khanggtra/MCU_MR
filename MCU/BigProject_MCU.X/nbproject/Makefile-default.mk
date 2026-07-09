#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/BigProject_MCU.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/BigProject_MCU.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../Big_Project_MCU/firmware/app/app_commute/app_commute.c ../Big_Project_MCU/firmware/app/app_control/app_control.c ../Big_Project_MCU/firmware/app/main.c "../Big_Project_MCU/firmware/drivers/DC motor/DC_Motor.c" ../Big_Project_MCU/firmware/drivers/Encoder/encoder.c ../Big_Project_MCU/firmware/hal/hal_adc/hal_adc.c ../Big_Project_MCU/firmware/hal/hal_gpio/hal_gpio.c ../Big_Project_MCU/firmware/hal/hal_pwm/hal_pwm.c ../Big_Project_MCU/firmware/hal/hal_timer0/hal_timer0.c ../Big_Project_MCU/firmware/hal/hal_uart/hal_uart.c ../Big_Project_MCU/firmware/sys/sys_config/sys_config.c ../Big_Project_MCU/firmware/sys/sys_tick/sys_tick.c ../Big_Project_MCU/firmware/utils/utils_pid/utils_pid.c ../Big_Project_MCU/firmware/utils/utils_string/utils_string.c ../Big_Project_MCU/firmware/project_config/fuse/fuse.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1017655614/app_commute.p1 ${OBJECTDIR}/_ext/1018784641/app_control.p1 ${OBJECTDIR}/_ext/1833872209/main.p1 ${OBJECTDIR}/_ext/748048728/DC_Motor.p1 ${OBJECTDIR}/_ext/198953624/encoder.p1 ${OBJECTDIR}/_ext/1954527576/hal_adc.p1 ${OBJECTDIR}/_ext/460622137/hal_gpio.p1 ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1 ${OBJECTDIR}/_ext/89585283/hal_timer0.p1 ${OBJECTDIR}/_ext/460219194/hal_uart.p1 ${OBJECTDIR}/_ext/1812980294/sys_config.p1 ${OBJECTDIR}/_ext/1423614369/sys_tick.p1 ${OBJECTDIR}/_ext/768968271/utils_pid.p1 ${OBJECTDIR}/_ext/925227827/utils_string.p1 ${OBJECTDIR}/_ext/1932871448/fuse.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1017655614/app_commute.p1.d ${OBJECTDIR}/_ext/1018784641/app_control.p1.d ${OBJECTDIR}/_ext/1833872209/main.p1.d ${OBJECTDIR}/_ext/748048728/DC_Motor.p1.d ${OBJECTDIR}/_ext/198953624/encoder.p1.d ${OBJECTDIR}/_ext/1954527576/hal_adc.p1.d ${OBJECTDIR}/_ext/460622137/hal_gpio.p1.d ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1.d ${OBJECTDIR}/_ext/89585283/hal_timer0.p1.d ${OBJECTDIR}/_ext/460219194/hal_uart.p1.d ${OBJECTDIR}/_ext/1812980294/sys_config.p1.d ${OBJECTDIR}/_ext/1423614369/sys_tick.p1.d ${OBJECTDIR}/_ext/768968271/utils_pid.p1.d ${OBJECTDIR}/_ext/925227827/utils_string.p1.d ${OBJECTDIR}/_ext/1932871448/fuse.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1017655614/app_commute.p1 ${OBJECTDIR}/_ext/1018784641/app_control.p1 ${OBJECTDIR}/_ext/1833872209/main.p1 ${OBJECTDIR}/_ext/748048728/DC_Motor.p1 ${OBJECTDIR}/_ext/198953624/encoder.p1 ${OBJECTDIR}/_ext/1954527576/hal_adc.p1 ${OBJECTDIR}/_ext/460622137/hal_gpio.p1 ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1 ${OBJECTDIR}/_ext/89585283/hal_timer0.p1 ${OBJECTDIR}/_ext/460219194/hal_uart.p1 ${OBJECTDIR}/_ext/1812980294/sys_config.p1 ${OBJECTDIR}/_ext/1423614369/sys_tick.p1 ${OBJECTDIR}/_ext/768968271/utils_pid.p1 ${OBJECTDIR}/_ext/925227827/utils_string.p1 ${OBJECTDIR}/_ext/1932871448/fuse.p1

# Source Files
SOURCEFILES=../Big_Project_MCU/firmware/app/app_commute/app_commute.c ../Big_Project_MCU/firmware/app/app_control/app_control.c ../Big_Project_MCU/firmware/app/main.c ../Big_Project_MCU/firmware/drivers/DC motor/DC_Motor.c ../Big_Project_MCU/firmware/drivers/Encoder/encoder.c ../Big_Project_MCU/firmware/hal/hal_adc/hal_adc.c ../Big_Project_MCU/firmware/hal/hal_gpio/hal_gpio.c ../Big_Project_MCU/firmware/hal/hal_pwm/hal_pwm.c ../Big_Project_MCU/firmware/hal/hal_timer0/hal_timer0.c ../Big_Project_MCU/firmware/hal/hal_uart/hal_uart.c ../Big_Project_MCU/firmware/sys/sys_config/sys_config.c ../Big_Project_MCU/firmware/sys/sys_tick/sys_tick.c ../Big_Project_MCU/firmware/utils/utils_pid/utils_pid.c ../Big_Project_MCU/firmware/utils/utils_string/utils_string.c ../Big_Project_MCU/firmware/project_config/fuse/fuse.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/BigProject_MCU.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F887
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1017655614/app_commute.p1: ../Big_Project_MCU/firmware/app/app_commute/app_commute.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1017655614" 
	@${RM} ${OBJECTDIR}/_ext/1017655614/app_commute.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1017655614/app_commute.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1017655614/app_commute.p1 ../Big_Project_MCU/firmware/app/app_commute/app_commute.c 
	@-${MV} ${OBJECTDIR}/_ext/1017655614/app_commute.d ${OBJECTDIR}/_ext/1017655614/app_commute.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1017655614/app_commute.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1018784641/app_control.p1: ../Big_Project_MCU/firmware/app/app_control/app_control.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1018784641" 
	@${RM} ${OBJECTDIR}/_ext/1018784641/app_control.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1018784641/app_control.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1018784641/app_control.p1 ../Big_Project_MCU/firmware/app/app_control/app_control.c 
	@-${MV} ${OBJECTDIR}/_ext/1018784641/app_control.d ${OBJECTDIR}/_ext/1018784641/app_control.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1018784641/app_control.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1833872209/main.p1: ../Big_Project_MCU/firmware/app/main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1833872209" 
	@${RM} ${OBJECTDIR}/_ext/1833872209/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1833872209/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1833872209/main.p1 ../Big_Project_MCU/firmware/app/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1833872209/main.d ${OBJECTDIR}/_ext/1833872209/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1833872209/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/748048728/DC_Motor.p1: ../Big_Project_MCU/firmware/drivers/DC\ motor/DC_Motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/748048728" 
	@${RM} ${OBJECTDIR}/_ext/748048728/DC_Motor.p1.d 
	@${RM} ${OBJECTDIR}/_ext/748048728/DC_Motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/748048728/DC_Motor.p1 "../Big_Project_MCU/firmware/drivers/DC motor/DC_Motor.c" 
	@-${MV} ${OBJECTDIR}/_ext/748048728/DC_Motor.d ${OBJECTDIR}/_ext/748048728/DC_Motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/748048728/DC_Motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/198953624/encoder.p1: ../Big_Project_MCU/firmware/drivers/Encoder/encoder.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/198953624" 
	@${RM} ${OBJECTDIR}/_ext/198953624/encoder.p1.d 
	@${RM} ${OBJECTDIR}/_ext/198953624/encoder.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/198953624/encoder.p1 ../Big_Project_MCU/firmware/drivers/Encoder/encoder.c 
	@-${MV} ${OBJECTDIR}/_ext/198953624/encoder.d ${OBJECTDIR}/_ext/198953624/encoder.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/198953624/encoder.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1954527576/hal_adc.p1: ../Big_Project_MCU/firmware/hal/hal_adc/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1954527576" 
	@${RM} ${OBJECTDIR}/_ext/1954527576/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1954527576/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1954527576/hal_adc.p1 ../Big_Project_MCU/firmware/hal/hal_adc/hal_adc.c 
	@-${MV} ${OBJECTDIR}/_ext/1954527576/hal_adc.d ${OBJECTDIR}/_ext/1954527576/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1954527576/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/460622137/hal_gpio.p1: ../Big_Project_MCU/firmware/hal/hal_gpio/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/460622137" 
	@${RM} ${OBJECTDIR}/_ext/460622137/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/_ext/460622137/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/460622137/hal_gpio.p1 ../Big_Project_MCU/firmware/hal/hal_gpio/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/_ext/460622137/hal_gpio.d ${OBJECTDIR}/_ext/460622137/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/460622137/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1954512562/hal_pwm.p1: ../Big_Project_MCU/firmware/hal/hal_pwm/hal_pwm.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1954512562" 
	@${RM} ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1 ../Big_Project_MCU/firmware/hal/hal_pwm/hal_pwm.c 
	@-${MV} ${OBJECTDIR}/_ext/1954512562/hal_pwm.d ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/89585283/hal_timer0.p1: ../Big_Project_MCU/firmware/hal/hal_timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/89585283" 
	@${RM} ${OBJECTDIR}/_ext/89585283/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/_ext/89585283/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/89585283/hal_timer0.p1 ../Big_Project_MCU/firmware/hal/hal_timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/_ext/89585283/hal_timer0.d ${OBJECTDIR}/_ext/89585283/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/89585283/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/460219194/hal_uart.p1: ../Big_Project_MCU/firmware/hal/hal_uart/hal_uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/460219194" 
	@${RM} ${OBJECTDIR}/_ext/460219194/hal_uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/460219194/hal_uart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/460219194/hal_uart.p1 ../Big_Project_MCU/firmware/hal/hal_uart/hal_uart.c 
	@-${MV} ${OBJECTDIR}/_ext/460219194/hal_uart.d ${OBJECTDIR}/_ext/460219194/hal_uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/460219194/hal_uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1812980294/sys_config.p1: ../Big_Project_MCU/firmware/sys/sys_config/sys_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1812980294" 
	@${RM} ${OBJECTDIR}/_ext/1812980294/sys_config.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1812980294/sys_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1812980294/sys_config.p1 ../Big_Project_MCU/firmware/sys/sys_config/sys_config.c 
	@-${MV} ${OBJECTDIR}/_ext/1812980294/sys_config.d ${OBJECTDIR}/_ext/1812980294/sys_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1812980294/sys_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1423614369/sys_tick.p1: ../Big_Project_MCU/firmware/sys/sys_tick/sys_tick.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1423614369" 
	@${RM} ${OBJECTDIR}/_ext/1423614369/sys_tick.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1423614369/sys_tick.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1423614369/sys_tick.p1 ../Big_Project_MCU/firmware/sys/sys_tick/sys_tick.c 
	@-${MV} ${OBJECTDIR}/_ext/1423614369/sys_tick.d ${OBJECTDIR}/_ext/1423614369/sys_tick.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1423614369/sys_tick.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/768968271/utils_pid.p1: ../Big_Project_MCU/firmware/utils/utils_pid/utils_pid.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/768968271" 
	@${RM} ${OBJECTDIR}/_ext/768968271/utils_pid.p1.d 
	@${RM} ${OBJECTDIR}/_ext/768968271/utils_pid.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/768968271/utils_pid.p1 ../Big_Project_MCU/firmware/utils/utils_pid/utils_pid.c 
	@-${MV} ${OBJECTDIR}/_ext/768968271/utils_pid.d ${OBJECTDIR}/_ext/768968271/utils_pid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/768968271/utils_pid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/925227827/utils_string.p1: ../Big_Project_MCU/firmware/utils/utils_string/utils_string.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/925227827" 
	@${RM} ${OBJECTDIR}/_ext/925227827/utils_string.p1.d 
	@${RM} ${OBJECTDIR}/_ext/925227827/utils_string.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/925227827/utils_string.p1 ../Big_Project_MCU/firmware/utils/utils_string/utils_string.c 
	@-${MV} ${OBJECTDIR}/_ext/925227827/utils_string.d ${OBJECTDIR}/_ext/925227827/utils_string.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/925227827/utils_string.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1932871448/fuse.p1: ../Big_Project_MCU/firmware/project_config/fuse/fuse.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1932871448" 
	@${RM} ${OBJECTDIR}/_ext/1932871448/fuse.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1932871448/fuse.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1932871448/fuse.p1 ../Big_Project_MCU/firmware/project_config/fuse/fuse.c 
	@-${MV} ${OBJECTDIR}/_ext/1932871448/fuse.d ${OBJECTDIR}/_ext/1932871448/fuse.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1932871448/fuse.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1017655614/app_commute.p1: ../Big_Project_MCU/firmware/app/app_commute/app_commute.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1017655614" 
	@${RM} ${OBJECTDIR}/_ext/1017655614/app_commute.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1017655614/app_commute.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1017655614/app_commute.p1 ../Big_Project_MCU/firmware/app/app_commute/app_commute.c 
	@-${MV} ${OBJECTDIR}/_ext/1017655614/app_commute.d ${OBJECTDIR}/_ext/1017655614/app_commute.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1017655614/app_commute.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1018784641/app_control.p1: ../Big_Project_MCU/firmware/app/app_control/app_control.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1018784641" 
	@${RM} ${OBJECTDIR}/_ext/1018784641/app_control.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1018784641/app_control.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1018784641/app_control.p1 ../Big_Project_MCU/firmware/app/app_control/app_control.c 
	@-${MV} ${OBJECTDIR}/_ext/1018784641/app_control.d ${OBJECTDIR}/_ext/1018784641/app_control.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1018784641/app_control.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1833872209/main.p1: ../Big_Project_MCU/firmware/app/main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1833872209" 
	@${RM} ${OBJECTDIR}/_ext/1833872209/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1833872209/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1833872209/main.p1 ../Big_Project_MCU/firmware/app/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1833872209/main.d ${OBJECTDIR}/_ext/1833872209/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1833872209/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/748048728/DC_Motor.p1: ../Big_Project_MCU/firmware/drivers/DC\ motor/DC_Motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/748048728" 
	@${RM} ${OBJECTDIR}/_ext/748048728/DC_Motor.p1.d 
	@${RM} ${OBJECTDIR}/_ext/748048728/DC_Motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/748048728/DC_Motor.p1 "../Big_Project_MCU/firmware/drivers/DC motor/DC_Motor.c" 
	@-${MV} ${OBJECTDIR}/_ext/748048728/DC_Motor.d ${OBJECTDIR}/_ext/748048728/DC_Motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/748048728/DC_Motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/198953624/encoder.p1: ../Big_Project_MCU/firmware/drivers/Encoder/encoder.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/198953624" 
	@${RM} ${OBJECTDIR}/_ext/198953624/encoder.p1.d 
	@${RM} ${OBJECTDIR}/_ext/198953624/encoder.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/198953624/encoder.p1 ../Big_Project_MCU/firmware/drivers/Encoder/encoder.c 
	@-${MV} ${OBJECTDIR}/_ext/198953624/encoder.d ${OBJECTDIR}/_ext/198953624/encoder.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/198953624/encoder.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1954527576/hal_adc.p1: ../Big_Project_MCU/firmware/hal/hal_adc/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1954527576" 
	@${RM} ${OBJECTDIR}/_ext/1954527576/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1954527576/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1954527576/hal_adc.p1 ../Big_Project_MCU/firmware/hal/hal_adc/hal_adc.c 
	@-${MV} ${OBJECTDIR}/_ext/1954527576/hal_adc.d ${OBJECTDIR}/_ext/1954527576/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1954527576/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/460622137/hal_gpio.p1: ../Big_Project_MCU/firmware/hal/hal_gpio/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/460622137" 
	@${RM} ${OBJECTDIR}/_ext/460622137/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/_ext/460622137/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/460622137/hal_gpio.p1 ../Big_Project_MCU/firmware/hal/hal_gpio/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/_ext/460622137/hal_gpio.d ${OBJECTDIR}/_ext/460622137/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/460622137/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1954512562/hal_pwm.p1: ../Big_Project_MCU/firmware/hal/hal_pwm/hal_pwm.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1954512562" 
	@${RM} ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1 ../Big_Project_MCU/firmware/hal/hal_pwm/hal_pwm.c 
	@-${MV} ${OBJECTDIR}/_ext/1954512562/hal_pwm.d ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1954512562/hal_pwm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/89585283/hal_timer0.p1: ../Big_Project_MCU/firmware/hal/hal_timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/89585283" 
	@${RM} ${OBJECTDIR}/_ext/89585283/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/_ext/89585283/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/89585283/hal_timer0.p1 ../Big_Project_MCU/firmware/hal/hal_timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/_ext/89585283/hal_timer0.d ${OBJECTDIR}/_ext/89585283/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/89585283/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/460219194/hal_uart.p1: ../Big_Project_MCU/firmware/hal/hal_uart/hal_uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/460219194" 
	@${RM} ${OBJECTDIR}/_ext/460219194/hal_uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/460219194/hal_uart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/460219194/hal_uart.p1 ../Big_Project_MCU/firmware/hal/hal_uart/hal_uart.c 
	@-${MV} ${OBJECTDIR}/_ext/460219194/hal_uart.d ${OBJECTDIR}/_ext/460219194/hal_uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/460219194/hal_uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1812980294/sys_config.p1: ../Big_Project_MCU/firmware/sys/sys_config/sys_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1812980294" 
	@${RM} ${OBJECTDIR}/_ext/1812980294/sys_config.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1812980294/sys_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1812980294/sys_config.p1 ../Big_Project_MCU/firmware/sys/sys_config/sys_config.c 
	@-${MV} ${OBJECTDIR}/_ext/1812980294/sys_config.d ${OBJECTDIR}/_ext/1812980294/sys_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1812980294/sys_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1423614369/sys_tick.p1: ../Big_Project_MCU/firmware/sys/sys_tick/sys_tick.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1423614369" 
	@${RM} ${OBJECTDIR}/_ext/1423614369/sys_tick.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1423614369/sys_tick.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1423614369/sys_tick.p1 ../Big_Project_MCU/firmware/sys/sys_tick/sys_tick.c 
	@-${MV} ${OBJECTDIR}/_ext/1423614369/sys_tick.d ${OBJECTDIR}/_ext/1423614369/sys_tick.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1423614369/sys_tick.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/768968271/utils_pid.p1: ../Big_Project_MCU/firmware/utils/utils_pid/utils_pid.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/768968271" 
	@${RM} ${OBJECTDIR}/_ext/768968271/utils_pid.p1.d 
	@${RM} ${OBJECTDIR}/_ext/768968271/utils_pid.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/768968271/utils_pid.p1 ../Big_Project_MCU/firmware/utils/utils_pid/utils_pid.c 
	@-${MV} ${OBJECTDIR}/_ext/768968271/utils_pid.d ${OBJECTDIR}/_ext/768968271/utils_pid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/768968271/utils_pid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/925227827/utils_string.p1: ../Big_Project_MCU/firmware/utils/utils_string/utils_string.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/925227827" 
	@${RM} ${OBJECTDIR}/_ext/925227827/utils_string.p1.d 
	@${RM} ${OBJECTDIR}/_ext/925227827/utils_string.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/925227827/utils_string.p1 ../Big_Project_MCU/firmware/utils/utils_string/utils_string.c 
	@-${MV} ${OBJECTDIR}/_ext/925227827/utils_string.d ${OBJECTDIR}/_ext/925227827/utils_string.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/925227827/utils_string.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1932871448/fuse.p1: ../Big_Project_MCU/firmware/project_config/fuse/fuse.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1932871448" 
	@${RM} ${OBJECTDIR}/_ext/1932871448/fuse.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1932871448/fuse.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1932871448/fuse.p1 ../Big_Project_MCU/firmware/project_config/fuse/fuse.c 
	@-${MV} ${OBJECTDIR}/_ext/1932871448/fuse.d ${OBJECTDIR}/_ext/1932871448/fuse.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1932871448/fuse.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/BigProject_MCU.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/BigProject_MCU.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=pickit3  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -mrom=default,-1f00-1ffe -mram=default,-0-0,-70-70,-80-80,-f0-f0,-100-100,-170-170,-180-180,-1e5-1f0  $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/BigProject_MCU.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/BigProject_MCU.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/BigProject_MCU.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/BigProject_MCU.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/BigProject_MCU.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
