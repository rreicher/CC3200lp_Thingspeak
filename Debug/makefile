################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ti-cgt-arm_20.2.4.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./app_cloud.obj" \
"./main.obj" \
"./rom_pin_mux_config.obj" \
"./startup_ccs.obj" \
"./Common/gpio_if.obj" \
"./Common/i2c_if.obj" \
"./Common/network_common.obj" \
"./Common/network_if.obj" \
"./Common/timer_if.obj" \
"./Common/tmp006drv.obj" \
"./Common/uart_if.obj" \
"./Common/udma_if.obj" \
"./Common/wdt_if.obj" \
"../cc3200v1p32.cmd" \
$(GEN_CMDS__FLAG) \
-l"C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/ccs/OS_debug/simplelink.a" \
-l"C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib/ccs/Release/driverlib.a" \
-l"C:/ti/CC3200SDK_1.5.0/cc3200-sdk/oslib/ccs/free_rtos/free_rtos.a" \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Common/subdir_vars.mk
-include subdir_rules.mk
-include Common/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
CC3200lp_Thingspeak.out \

EXE_OUTPUTS__QUOTED += \
"CC3200lp_Thingspeak.out" \

BIN_OUTPUTS += \
CC3200lp_Thingspeak.bin \

BIN_OUTPUTS__QUOTED += \
"CC3200lp_Thingspeak.bin" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "CC3200lp_Thingspeak.out"

# Tool invocations
CC3200lp_Thingspeak.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me -Ooff --define=ccs --define=__SL__ --define=USE_FREERTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 -g --c99 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"CC3200lp_Thingspeak.map" --heap_size=0x4000 --stack_size=0x800 -i"C:/ti/ti-cgt-arm_20.2.4.LTS/lib" -i"C:/ti/ti-cgt-arm_20.2.4.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="CC3200lp_Thingspeak_linkInfo.xml" --rom_model -o "CC3200lp_Thingspeak.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

CC3200lp_Thingspeak.bin: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: Arm Hex Utility'
	"C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armhex"  -o "CC3200lp_Thingspeak.bin" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "app_cloud.obj" "main.obj" "rom_pin_mux_config.obj" "startup_ccs.obj" "Common\gpio_if.obj" "Common\i2c_if.obj" "Common\network_common.obj" "Common\network_if.obj" "Common\timer_if.obj" "Common\tmp006drv.obj" "Common\uart_if.obj" "Common\udma_if.obj" "Common\wdt_if.obj" 
	-$(RM) "app_cloud.d" "main.d" "rom_pin_mux_config.d" "startup_ccs.d" "Common\gpio_if.d" "Common\i2c_if.d" "Common\network_common.d" "Common\network_if.d" "Common\timer_if.d" "Common\tmp006drv.d" "Common\uart_if.d" "Common\udma_if.d" "Common\wdt_if.d" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-C:/ti/ccsv8/utils/tiobj2bin/tiobj2bin CC3200lp_Thingspeak.out CC3200lp_Thingspeak.bin C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armofd C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armhex C:/ti/ccsv8/utils/tiobj2bin/mkhex4bin
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

