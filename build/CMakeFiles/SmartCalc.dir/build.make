# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sparrvio/SmartCalc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sparrvio/SmartCalc/build

# Include any dependencies generated for this target.
include CMakeFiles/SmartCalc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SmartCalc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SmartCalc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SmartCalc.dir/flags.make

../SmartCalc_ru_RU.ts: CMakeFiles/3.23.0/CompilerIdC/CMakeCCompilerId.c
../SmartCalc_ru_RU.ts: CMakeFiles/3.23.0/CompilerIdCXX/CMakeCXXCompilerId.cpp
../SmartCalc_ru_RU.ts: ../creditcalc.cpp
../SmartCalc_ru_RU.ts: ../creditcalc.h
../SmartCalc_ru_RU.ts: ../creditcalc.ui
../SmartCalc_ru_RU.ts: ../main.cpp
../SmartCalc_ru_RU.ts: ../sparrvio.cpp
../SmartCalc_ru_RU.ts: ../sparrvio.h
../SmartCalc_ru_RU.ts: ../sparrvio.ui
../SmartCalc_ru_RU.ts: ../src/calc.c
../SmartCalc_ru_RU.ts: ../src/credit_calc_ann.c
../SmartCalc_ru_RU.ts: ../src/credit_calc_diff.c
../SmartCalc_ru_RU.ts: ../src/my_main.c
../SmartCalc_ru_RU.ts: ../src/new_main.c
../SmartCalc_ru_RU.ts: ../src/notation.c
../SmartCalc_ru_RU.ts: ../src/parser.c
../SmartCalc_ru_RU.ts: ../src/s21_SmartCalc.h
../SmartCalc_ru_RU.ts: ../src/second_func.c
../SmartCalc_ru_RU.ts: ../src/validator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/sparrvio/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../SmartCalc_ru_RU.ts"
	/usr/local/bin/lupdate @/Users/sparrvio/SmartCalc/build/CMakeFiles/SmartCalc_ru_RU.ts_lst_file -ts /Users/sparrvio/SmartCalc/SmartCalc_ru_RU.ts

CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o: SmartCalc_autogen/mocs_compilation.cpp
CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sparrvio/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o -MF CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o -c /Users/sparrvio/SmartCalc/build/SmartCalc_autogen/mocs_compilation.cpp

CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sparrvio/SmartCalc/build/SmartCalc_autogen/mocs_compilation.cpp > CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.i

CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sparrvio/SmartCalc/build/SmartCalc_autogen/mocs_compilation.cpp -o CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.s

CMakeFiles/SmartCalc.dir/main.cpp.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/main.cpp.o: ../main.cpp
CMakeFiles/SmartCalc.dir/main.cpp.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sparrvio/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SmartCalc.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/main.cpp.o -MF CMakeFiles/SmartCalc.dir/main.cpp.o.d -o CMakeFiles/SmartCalc.dir/main.cpp.o -c /Users/sparrvio/SmartCalc/main.cpp

CMakeFiles/SmartCalc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SmartCalc.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sparrvio/SmartCalc/main.cpp > CMakeFiles/SmartCalc.dir/main.cpp.i

CMakeFiles/SmartCalc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SmartCalc.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sparrvio/SmartCalc/main.cpp -o CMakeFiles/SmartCalc.dir/main.cpp.s

CMakeFiles/SmartCalc.dir/sparrvio.cpp.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/sparrvio.cpp.o: ../sparrvio.cpp
CMakeFiles/SmartCalc.dir/sparrvio.cpp.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sparrvio/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SmartCalc.dir/sparrvio.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/sparrvio.cpp.o -MF CMakeFiles/SmartCalc.dir/sparrvio.cpp.o.d -o CMakeFiles/SmartCalc.dir/sparrvio.cpp.o -c /Users/sparrvio/SmartCalc/sparrvio.cpp

CMakeFiles/SmartCalc.dir/sparrvio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SmartCalc.dir/sparrvio.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sparrvio/SmartCalc/sparrvio.cpp > CMakeFiles/SmartCalc.dir/sparrvio.cpp.i

CMakeFiles/SmartCalc.dir/sparrvio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SmartCalc.dir/sparrvio.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sparrvio/SmartCalc/sparrvio.cpp -o CMakeFiles/SmartCalc.dir/sparrvio.cpp.s

CMakeFiles/SmartCalc.dir/creditcalc.cpp.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/creditcalc.cpp.o: ../creditcalc.cpp
CMakeFiles/SmartCalc.dir/creditcalc.cpp.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sparrvio/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SmartCalc.dir/creditcalc.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/creditcalc.cpp.o -MF CMakeFiles/SmartCalc.dir/creditcalc.cpp.o.d -o CMakeFiles/SmartCalc.dir/creditcalc.cpp.o -c /Users/sparrvio/SmartCalc/creditcalc.cpp

CMakeFiles/SmartCalc.dir/creditcalc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SmartCalc.dir/creditcalc.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sparrvio/SmartCalc/creditcalc.cpp > CMakeFiles/SmartCalc.dir/creditcalc.cpp.i

CMakeFiles/SmartCalc.dir/creditcalc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SmartCalc.dir/creditcalc.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sparrvio/SmartCalc/creditcalc.cpp -o CMakeFiles/SmartCalc.dir/creditcalc.cpp.s

CMakeFiles/SmartCalc.dir/src/calc.c.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/src/calc.c.o: ../src/calc.c
CMakeFiles/SmartCalc.dir/src/calc.c.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sparrvio/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/SmartCalc.dir/src/calc.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/src/calc.c.o -MF CMakeFiles/SmartCalc.dir/src/calc.c.o.d -o CMakeFiles/SmartCalc.dir/src/calc.c.o -c /Users/sparrvio/SmartCalc/src/calc.c

CMakeFiles/SmartCalc.dir/src/calc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SmartCalc.dir/src/calc.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sparrvio/SmartCalc/src/calc.c > CMakeFiles/SmartCalc.dir/src/calc.c.i

CMakeFiles/SmartCalc.dir/src/calc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SmartCalc.dir/src/calc.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sparrvio/SmartCalc/src/calc.c -o CMakeFiles/SmartCalc.dir/src/calc.c.s

CMakeFiles/SmartCalc.dir/src/parser.c.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/src/parser.c.o: ../src/parser.c
CMakeFiles/SmartCalc.dir/src/parser.c.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sparrvio/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/SmartCalc.dir/src/parser.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/src/parser.c.o -MF CMakeFiles/SmartCalc.dir/src/parser.c.o.d -o CMakeFiles/SmartCalc.dir/src/parser.c.o -c /Users/sparrvio/SmartCalc/src/parser.c

CMakeFiles/SmartCalc.dir/src/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SmartCalc.dir/src/parser.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sparrvio/SmartCalc/src/parser.c > CMakeFiles/SmartCalc.dir/src/parser.c.i

CMakeFiles/SmartCalc.dir/src/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SmartCalc.dir/src/parser.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sparrvio/SmartCalc/src/parser.c -o CMakeFiles/SmartCalc.dir/src/parser.c.s

CMakeFiles/SmartCalc.dir/src/notation.c.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/src/notation.c.o: ../src/notation.c
CMakeFiles/SmartCalc.dir/src/notation.c.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sparrvio/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/SmartCalc.dir/src/notation.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/src/notation.c.o -MF CMakeFiles/SmartCalc.dir/src/notation.c.o.d -o CMakeFiles/SmartCalc.dir/src/notation.c.o -c /Users/sparrvio/SmartCalc/src/notation.c

CMakeFiles/SmartCalc.dir/src/notation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SmartCalc.dir/src/notation.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sparrvio/SmartCalc/src/notation.c > CMakeFiles/SmartCalc.dir/src/notation.c.i

CMakeFiles/SmartCalc.dir/src/notation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SmartCalc.dir/src/notation.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sparrvio/SmartCalc/src/notation.c -o CMakeFiles/SmartCalc.dir/src/notation.c.s

CMakeFiles/SmartCalc.dir/src/validator.c.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/src/validator.c.o: ../src/validator.c
CMakeFiles/SmartCalc.dir/src/validator.c.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sparrvio/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/SmartCalc.dir/src/validator.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/src/validator.c.o -MF CMakeFiles/SmartCalc.dir/src/validator.c.o.d -o CMakeFiles/SmartCalc.dir/src/validator.c.o -c /Users/sparrvio/SmartCalc/src/validator.c

CMakeFiles/SmartCalc.dir/src/validator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SmartCalc.dir/src/validator.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sparrvio/SmartCalc/src/validator.c > CMakeFiles/SmartCalc.dir/src/validator.c.i

CMakeFiles/SmartCalc.dir/src/validator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SmartCalc.dir/src/validator.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sparrvio/SmartCalc/src/validator.c -o CMakeFiles/SmartCalc.dir/src/validator.c.s

CMakeFiles/SmartCalc.dir/src/my_main.c.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/src/my_main.c.o: ../src/my_main.c
CMakeFiles/SmartCalc.dir/src/my_main.c.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sparrvio/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/SmartCalc.dir/src/my_main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/src/my_main.c.o -MF CMakeFiles/SmartCalc.dir/src/my_main.c.o.d -o CMakeFiles/SmartCalc.dir/src/my_main.c.o -c /Users/sparrvio/SmartCalc/src/my_main.c

CMakeFiles/SmartCalc.dir/src/my_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SmartCalc.dir/src/my_main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sparrvio/SmartCalc/src/my_main.c > CMakeFiles/SmartCalc.dir/src/my_main.c.i

CMakeFiles/SmartCalc.dir/src/my_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SmartCalc.dir/src/my_main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sparrvio/SmartCalc/src/my_main.c -o CMakeFiles/SmartCalc.dir/src/my_main.c.s

# Object files for target SmartCalc
SmartCalc_OBJECTS = \
"CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/SmartCalc.dir/main.cpp.o" \
"CMakeFiles/SmartCalc.dir/sparrvio.cpp.o" \
"CMakeFiles/SmartCalc.dir/creditcalc.cpp.o" \
"CMakeFiles/SmartCalc.dir/src/calc.c.o" \
"CMakeFiles/SmartCalc.dir/src/parser.c.o" \
"CMakeFiles/SmartCalc.dir/src/notation.c.o" \
"CMakeFiles/SmartCalc.dir/src/validator.c.o" \
"CMakeFiles/SmartCalc.dir/src/my_main.c.o"

# External object files for target SmartCalc
SmartCalc_EXTERNAL_OBJECTS =

SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/main.cpp.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/sparrvio.cpp.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/creditcalc.cpp.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/src/calc.c.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/src/parser.c.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/src/notation.c.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/src/validator.c.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/src/my_main.c.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/build.make
SmartCalc.app/Contents/MacOS/SmartCalc: /usr/local/lib/QtWidgets.framework/Versions/A/QtWidgets
SmartCalc.app/Contents/MacOS/SmartCalc: /usr/local/lib/QtGui.framework/Versions/A/QtGui
SmartCalc.app/Contents/MacOS/SmartCalc: /usr/local/lib/QtCore.framework/Versions/A/QtCore
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sparrvio/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable SmartCalc.app/Contents/MacOS/SmartCalc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SmartCalc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SmartCalc.dir/build: SmartCalc.app/Contents/MacOS/SmartCalc
.PHONY : CMakeFiles/SmartCalc.dir/build

CMakeFiles/SmartCalc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SmartCalc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SmartCalc.dir/clean

CMakeFiles/SmartCalc.dir/depend: ../SmartCalc_ru_RU.ts
	cd /Users/sparrvio/SmartCalc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sparrvio/SmartCalc /Users/sparrvio/SmartCalc /Users/sparrvio/SmartCalc/build /Users/sparrvio/SmartCalc/build /Users/sparrvio/SmartCalc/build/CMakeFiles/SmartCalc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SmartCalc.dir/depend

