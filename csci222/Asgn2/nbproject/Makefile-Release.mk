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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/console.o \
	${OBJECTDIR}/library/sqlite3pp.o \
	${OBJECTDIR}/library/sqlite3ppext.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/query.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2

# C Compiler Flags
CFLAGS=`cppunit-config --cflags` 

# CC Compiler Flags
CCFLAGS=-lsqlite3 -std=c++0x
CXXFLAGS=-lsqlite3 -std=c++0x

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Llibrary

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci222asgn2

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci222asgn2: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci222asgn2 ${OBJECTFILES} ${LDLIBSOPTIONS} -std=c++0x -lsqlite3

${OBJECTDIR}/console.o: console.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/console.o console.cpp

${OBJECTDIR}/library/sqlite3pp.o: library/sqlite3pp.cpp 
	${MKDIR} -p ${OBJECTDIR}/library
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/library/sqlite3pp.o library/sqlite3pp.cpp

${OBJECTDIR}/library/sqlite3ppext.o: library/sqlite3ppext.cpp 
	${MKDIR} -p ${OBJECTDIR}/library
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/library/sqlite3ppext.o library/sqlite3ppext.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/query.o: query.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/query.o query.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/newtestrunner.o ${TESTDIR}/tests/testQuery.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/newtestrunner.o: tests/newtestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestrunner.o tests/newtestrunner.cpp


${TESTDIR}/tests/testQuery.o: tests/testQuery.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/testQuery.o tests/testQuery.cpp


${OBJECTDIR}/console_nomain.o: ${OBJECTDIR}/console.o console.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/console.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/console_nomain.o console.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/console.o ${OBJECTDIR}/console_nomain.o;\
	fi

${OBJECTDIR}/library/sqlite3pp_nomain.o: ${OBJECTDIR}/library/sqlite3pp.o library/sqlite3pp.cpp 
	${MKDIR} -p ${OBJECTDIR}/library
	@NMOUTPUT=`${NM} ${OBJECTDIR}/library/sqlite3pp.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/library/sqlite3pp_nomain.o library/sqlite3pp.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/library/sqlite3pp.o ${OBJECTDIR}/library/sqlite3pp_nomain.o;\
	fi

${OBJECTDIR}/library/sqlite3ppext_nomain.o: ${OBJECTDIR}/library/sqlite3ppext.o library/sqlite3ppext.cpp 
	${MKDIR} -p ${OBJECTDIR}/library
	@NMOUTPUT=`${NM} ${OBJECTDIR}/library/sqlite3ppext.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/library/sqlite3ppext_nomain.o library/sqlite3ppext.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/library/sqlite3ppext.o ${OBJECTDIR}/library/sqlite3ppext_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/query_nomain.o: ${OBJECTDIR}/query.o query.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/query.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Ilibrary -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/query_nomain.o query.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/query.o ${OBJECTDIR}/query_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci222asgn2

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
