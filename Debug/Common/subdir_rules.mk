################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Common/gpio_if.obj: C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/gpio_if.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me -Ooff --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/include" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/source" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/inc/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/" --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak/Common" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/netapps/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink_extlib/provisioninglib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/oslib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib" --include_path="C:/ti/ti-cgt-arm_20.2.4.LTS/include" --define=ccs --define=__SL__ --define=USE_FREERTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 -g --c99 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Common/$(basename $(<F)).d_raw" --obj_directory="Common" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Common/i2c_if.obj: C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/i2c_if.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me -Ooff --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/include" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/source" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/inc/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/" --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak/Common" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/netapps/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink_extlib/provisioninglib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/oslib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib" --include_path="C:/ti/ti-cgt-arm_20.2.4.LTS/include" --define=ccs --define=__SL__ --define=USE_FREERTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 -g --c99 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Common/$(basename $(<F)).d_raw" --obj_directory="Common" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Common/network_common.obj: C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/network_common.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me -Ooff --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/include" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/source" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/inc/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/" --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak/Common" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/netapps/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink_extlib/provisioninglib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/oslib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib" --include_path="C:/ti/ti-cgt-arm_20.2.4.LTS/include" --define=ccs --define=__SL__ --define=USE_FREERTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 -g --c99 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Common/$(basename $(<F)).d_raw" --obj_directory="Common" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Common/network_if.obj: C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/network_if.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me -Ooff --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/include" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/source" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/inc/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/" --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak/Common" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/netapps/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink_extlib/provisioninglib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/oslib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib" --include_path="C:/ti/ti-cgt-arm_20.2.4.LTS/include" --define=ccs --define=__SL__ --define=USE_FREERTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 -g --c99 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Common/$(basename $(<F)).d_raw" --obj_directory="Common" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Common/timer_if.obj: C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/timer_if.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me -Ooff --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/include" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/source" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/inc/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/" --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak/Common" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/netapps/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink_extlib/provisioninglib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/oslib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib" --include_path="C:/ti/ti-cgt-arm_20.2.4.LTS/include" --define=ccs --define=__SL__ --define=USE_FREERTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 -g --c99 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Common/$(basename $(<F)).d_raw" --obj_directory="Common" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Common/%.obj: ../Common/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me -Ooff --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/include" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/source" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/inc/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/" --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak/Common" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/netapps/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink_extlib/provisioninglib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/oslib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib" --include_path="C:/ti/ti-cgt-arm_20.2.4.LTS/include" --define=ccs --define=__SL__ --define=USE_FREERTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 -g --c99 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Common/$(basename $(<F)).d_raw" --obj_directory="Common" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Common/uart_if.obj: C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/uart_if.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me -Ooff --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/include" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/source" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/inc/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/" --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak/Common" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/netapps/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink_extlib/provisioninglib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/oslib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib" --include_path="C:/ti/ti-cgt-arm_20.2.4.LTS/include" --define=ccs --define=__SL__ --define=USE_FREERTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 -g --c99 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Common/$(basename $(<F)).d_raw" --obj_directory="Common" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Common/udma_if.obj: C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/udma_if.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me -Ooff --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/include" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/source" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/inc/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/" --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak/Common" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/netapps/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink_extlib/provisioninglib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/oslib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib" --include_path="C:/ti/ti-cgt-arm_20.2.4.LTS/include" --define=ccs --define=__SL__ --define=USE_FREERTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 -g --c99 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Common/$(basename $(<F)).d_raw" --obj_directory="Common" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Common/wdt_if.obj: C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/wdt_if.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=none -me -Ooff --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/include" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink/source" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/inc/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/example/common/" --include_path="C:/Users/rom/workspace_v8/CC3200lp_Thingspeak/Common" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/netapps/" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/simplelink_extlib/provisioninglib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/oslib" --include_path="C:/ti/CC3200SDK_1.5.0/cc3200-sdk/driverlib" --include_path="C:/ti/ti-cgt-arm_20.2.4.LTS/include" --define=ccs --define=__SL__ --define=USE_FREERTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 -g --c99 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Common/$(basename $(<F)).d_raw" --obj_directory="Common" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


