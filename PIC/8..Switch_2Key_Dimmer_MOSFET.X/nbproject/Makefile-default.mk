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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/8..Switch_2Key_Dimmer_MOSFET.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/8..Switch_2Key_Dimmer_MOSFET.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/Buzzer_B1.c ../src/CC2500_B1.c ../src/CDS_B1.c ../src/DelayOff_B1.c ../src/Dimmer_B1.c ../src/LED_B1.c ../src/MCU_B1.c ../src/OverLoad_B1.c ../src/OverTemperature_B1.c ../src/PIR_B1.c ../src/PowerFault_B1.c ../src/RF_Control_B1.c ../src/SYSC_B1.c ../src/SegmentDisplay_A2.c ../src/Switch_B1.c ../src/TriacRelay_B1.c ../src/main_B1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1 ${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1 ${OBJECTDIR}/_ext/1360937237/CDS_B1.p1 ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1 ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1 ${OBJECTDIR}/_ext/1360937237/LED_B1.p1 ${OBJECTDIR}/_ext/1360937237/MCU_B1.p1 ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1 ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1 ${OBJECTDIR}/_ext/1360937237/PIR_B1.p1 ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1 ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1 ${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1 ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1 ${OBJECTDIR}/_ext/1360937237/Switch_B1.p1 ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1 ${OBJECTDIR}/_ext/1360937237/main_B1.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1.d ${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1.d ${OBJECTDIR}/_ext/1360937237/CDS_B1.p1.d ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1.d ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1.d ${OBJECTDIR}/_ext/1360937237/LED_B1.p1.d ${OBJECTDIR}/_ext/1360937237/MCU_B1.p1.d ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1.d ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1.d ${OBJECTDIR}/_ext/1360937237/PIR_B1.p1.d ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1.d ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1.d ${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1.d ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1.d ${OBJECTDIR}/_ext/1360937237/Switch_B1.p1.d ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1.d ${OBJECTDIR}/_ext/1360937237/main_B1.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1 ${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1 ${OBJECTDIR}/_ext/1360937237/CDS_B1.p1 ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1 ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1 ${OBJECTDIR}/_ext/1360937237/LED_B1.p1 ${OBJECTDIR}/_ext/1360937237/MCU_B1.p1 ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1 ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1 ${OBJECTDIR}/_ext/1360937237/PIR_B1.p1 ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1 ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1 ${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1 ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1 ${OBJECTDIR}/_ext/1360937237/Switch_B1.p1 ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1 ${OBJECTDIR}/_ext/1360937237/main_B1.p1

# Source Files
SOURCEFILES=../src/Buzzer_B1.c ../src/CC2500_B1.c ../src/CDS_B1.c ../src/DelayOff_B1.c ../src/Dimmer_B1.c ../src/LED_B1.c ../src/MCU_B1.c ../src/OverLoad_B1.c ../src/OverTemperature_B1.c ../src/PIR_B1.c ../src/PowerFault_B1.c ../src/RF_Control_B1.c ../src/SYSC_B1.c ../src/SegmentDisplay_A2.c ../src/Switch_B1.c ../src/TriacRelay_B1.c ../src/main_B1.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/8..Switch_2Key_Dimmer_MOSFET.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F1518
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1: ../src/Buzzer_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1  ../src/Buzzer_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/Buzzer_B1.d ${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1: ../src/CC2500_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1  ../src/CC2500_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/CC2500_B1.d ${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/CDS_B1.p1: ../src/CDS_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/CDS_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/CDS_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/CDS_B1.p1  ../src/CDS_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/CDS_B1.d ${OBJECTDIR}/_ext/1360937237/CDS_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/CDS_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1: ../src/DelayOff_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1  ../src/DelayOff_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.d ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1: ../src/Dimmer_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1  ../src/Dimmer_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.d ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/LED_B1.p1: ../src/LED_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LED_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LED_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/LED_B1.p1  ../src/LED_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/LED_B1.d ${OBJECTDIR}/_ext/1360937237/LED_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/LED_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/MCU_B1.p1: ../src/MCU_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MCU_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MCU_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/MCU_B1.p1  ../src/MCU_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/MCU_B1.d ${OBJECTDIR}/_ext/1360937237/MCU_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/MCU_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1: ../src/OverLoad_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1  ../src/OverLoad_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.d ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1: ../src/OverTemperature_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1  ../src/OverTemperature_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.d ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/PIR_B1.p1: ../src/PIR_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PIR_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PIR_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/PIR_B1.p1  ../src/PIR_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/PIR_B1.d ${OBJECTDIR}/_ext/1360937237/PIR_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/PIR_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1: ../src/PowerFault_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1  ../src/PowerFault_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.d ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1: ../src/RF_Control_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1  ../src/RF_Control_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.d ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1: ../src/SYSC_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1  ../src/SYSC_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/SYSC_B1.d ${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1: ../src/SegmentDisplay_A2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1  ../src/SegmentDisplay_A2.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.d ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/Switch_B1.p1: ../src/Switch_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Switch_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Switch_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/Switch_B1.p1  ../src/Switch_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/Switch_B1.d ${OBJECTDIR}/_ext/1360937237/Switch_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/Switch_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1: ../src/TriacRelay_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1  ../src/TriacRelay_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.d ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/main_B1.p1: ../src/main_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/main_B1.p1  ../src/main_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/main_B1.d ${OBJECTDIR}/_ext/1360937237/main_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/main_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1: ../src/Buzzer_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1  ../src/Buzzer_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/Buzzer_B1.d ${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/Buzzer_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1: ../src/CC2500_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1  ../src/CC2500_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/CC2500_B1.d ${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/CC2500_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/CDS_B1.p1: ../src/CDS_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/CDS_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/CDS_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/CDS_B1.p1  ../src/CDS_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/CDS_B1.d ${OBJECTDIR}/_ext/1360937237/CDS_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/CDS_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1: ../src/DelayOff_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1  ../src/DelayOff_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.d ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/DelayOff_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1: ../src/Dimmer_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1  ../src/Dimmer_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.d ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/Dimmer_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/LED_B1.p1: ../src/LED_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LED_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LED_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/LED_B1.p1  ../src/LED_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/LED_B1.d ${OBJECTDIR}/_ext/1360937237/LED_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/LED_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/MCU_B1.p1: ../src/MCU_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MCU_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MCU_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/MCU_B1.p1  ../src/MCU_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/MCU_B1.d ${OBJECTDIR}/_ext/1360937237/MCU_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/MCU_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1: ../src/OverLoad_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1  ../src/OverLoad_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.d ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/OverLoad_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1: ../src/OverTemperature_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1  ../src/OverTemperature_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.d ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/OverTemperature_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/PIR_B1.p1: ../src/PIR_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PIR_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PIR_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/PIR_B1.p1  ../src/PIR_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/PIR_B1.d ${OBJECTDIR}/_ext/1360937237/PIR_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/PIR_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1: ../src/PowerFault_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1  ../src/PowerFault_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.d ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/PowerFault_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1: ../src/RF_Control_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1  ../src/RF_Control_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.d ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/RF_Control_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1: ../src/SYSC_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1  ../src/SYSC_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/SYSC_B1.d ${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/SYSC_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1: ../src/SegmentDisplay_A2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1  ../src/SegmentDisplay_A2.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.d ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/SegmentDisplay_A2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/Switch_B1.p1: ../src/Switch_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Switch_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Switch_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/Switch_B1.p1  ../src/Switch_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/Switch_B1.d ${OBJECTDIR}/_ext/1360937237/Switch_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/Switch_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1: ../src/TriacRelay_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1  ../src/TriacRelay_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.d ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/TriacRelay_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/main_B1.p1: ../src/main_B1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_B1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_B1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/main_B1.p1  ../src/main_B1.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/main_B1.d ${OBJECTDIR}/_ext/1360937237/main_B1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/main_B1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/8..Switch_2Key_Dimmer_MOSFET.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/8..Switch_2Key_Dimmer_MOSFET.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"        -odist/${CND_CONF}/${IMAGE_TYPE}/8..Switch_2Key_Dimmer_MOSFET.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/8..Switch_2Key_Dimmer_MOSFET.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/8..Switch_2Key_Dimmer_MOSFET.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/8..Switch_2Key_Dimmer_MOSFET.X.${IMAGE_TYPE}.map  --double=24 --float=24 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -odist/${CND_CONF}/${IMAGE_TYPE}/8..Switch_2Key_Dimmer_MOSFET.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
