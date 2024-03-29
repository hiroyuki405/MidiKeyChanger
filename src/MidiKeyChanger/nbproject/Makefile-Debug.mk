#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=avr-gcc
CCC=avr-g++
CXX=avr-g++
FC=gfortran
AS=avr-as

# Macros
CND_PLATFORM=Arduino-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/common.o \
	${OBJECTDIR}/debugPrint.o \
	${OBJECTDIR}/hardInterface.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/midiMng.o \
	${OBJECTDIR}/pinMonitor.o \
	${OBJECTDIR}/timerParameter.o \
	${OBJECTDIR}/timerState.o


# C Compiler Flags
CFLAGS=${FLAGS_GCC}

# CC Compiler Flags
CCFLAGS=${FLAGS_GPP}
CXXFLAGS=${FLAGS_GPP}

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/midikeychanger.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/midikeychanger.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	avr-gcc -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/midikeychanger ${OBJECTFILES} ${LDLIBSOPTIONS} ${FLAGS_LINKER}

${OBJECTDIR}/State.o: State.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/common.o: common.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/common.o common.cpp

${OBJECTDIR}/debugPrint.o: debugPrint.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/debugPrint.o debugPrint.cpp

${OBJECTDIR}/hardInterface.o: hardInterface.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hardInterface.o hardInterface.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/midiMng.o: midiMng.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/midiMng.o midiMng.cpp

${OBJECTDIR}/pinMonitor.o: pinMonitor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/pinMonitor.o pinMonitor.cpp

${OBJECTDIR}/timerParameter.o: timerParameter.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/timerParameter.o timerParameter.cpp

${OBJECTDIR}/timerState.o: timerState.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/timerState.o timerState.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
