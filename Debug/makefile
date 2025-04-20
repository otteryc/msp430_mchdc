################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs2002/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./hv.obj" \
"./image.obj" \
"./main.obj" \
"./uart.obj" \
"./DriverLib/adc12_b.obj" \
"./DriverLib/aes256.obj" \
"./DriverLib/comp_e.obj" \
"./DriverLib/crc.obj" \
"./DriverLib/crc32.obj" \
"./DriverLib/cs.obj" \
"./DriverLib/dma.obj" \
"./DriverLib/esi.obj" \
"./DriverLib/eusci_a_spi.obj" \
"./DriverLib/eusci_a_uart.obj" \
"./DriverLib/eusci_b_i2c.obj" \
"./DriverLib/eusci_b_spi.obj" \
"./DriverLib/framctl.obj" \
"./DriverLib/framctl_a.obj" \
"./DriverLib/gpio.obj" \
"./DriverLib/hspll.obj" \
"./DriverLib/lcd_c.obj" \
"./DriverLib/mpu.obj" \
"./DriverLib/mpy32.obj" \
"./DriverLib/mtif.obj" \
"./DriverLib/pmm.obj" \
"./DriverLib/ram.obj" \
"./DriverLib/ref_a.obj" \
"./DriverLib/rtc_b.obj" \
"./DriverLib/rtc_c.obj" \
"./DriverLib/saph.obj" \
"./DriverLib/saph_a.obj" \
"./DriverLib/sdhs.obj" \
"./DriverLib/sfr.obj" \
"./DriverLib/sysctl.obj" \
"./DriverLib/timer_a.obj" \
"./DriverLib/timer_b.obj" \
"./DriverLib/tlv.obj" \
"./DriverLib/uups.obj" \
"./DriverLib/wdt_a.obj" \
"./lib/hdc.obj" \
"./lib/popcount_table.obj" \
"../lnk_msp430fr5994.cmd" \
$(GEN_CMDS__FLAG) \
-llibmpu_init.a \
-llibmath.a \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include DriverLib/subdir_vars.mk
-include lib/subdir_vars.mk
-include subdir_rules.mk
-include DriverLib/subdir_rules.mk
-include lib/subdir_rules.mk
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
msp430_mchdc.out 

EXE_OUTPUTS__QUOTED += \
"msp430_mchdc.out" 


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "msp430_mchdc.out"

# Tool invocations
msp430_mchdc.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: MSP430 Linker'
	"C:/ti/ccs2002/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O4 --use_hw_mpy=F5 --advice:power="all" --advice:hw_config=all --define=__MSP430FR5994__ --define=_MPU_ENABLE --define=_MPU_MANUAL --define=_MPU_SEGB1=0x4400 --define=_MPU_SEGB2=0x4800 --define=_MPU_SAM1=11 --define=_MPU_SAM2=11 --define=_MPU_SAM3=15 --define=_MPU_SAM0=9 -g --c99 --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 -z -m"msp430_mchdc.map" --heap_size=0 --stack_size=1024 --cinit_hold_wdt=on -i"C:/ti/ccs2002/ccs/ccs_base/msp430/include" -i"C:/ti/ccs2002/ccs/ccs_base/msp430/lib/5xx_6xx_FRxx" -i"C:/ti/ccs2002/ccs/ccs_base/msp430/lib/FR59xx" -i"C:/ti/ccs2002/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/lib" -i"C:/ti/ccs2002/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --priority --reread_libs --define=_MPU_ENABLE --define=_MPU_MANUAL --define=_MPU_SEGB1=0x4400 --define=_MPU_SEGB2=0x4800 --define=_MPU_SAM1=11 --define=_MPU_SAM2=11 --define=_MPU_SAM3=15 --define=_MPU_SAM0=9 --diag_wrap=off --display_error_number --warn_sections --xml_link_info="msp430_mchdc_linkInfo.xml" --use_hw_mpy=F5 --rom_model -o "msp430_mchdc.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "hv.obj" "image.obj" "main.obj" "uart.obj" "DriverLib\adc12_b.obj" "DriverLib\aes256.obj" "DriverLib\comp_e.obj" "DriverLib\crc.obj" "DriverLib\crc32.obj" "DriverLib\cs.obj" "DriverLib\dma.obj" "DriverLib\esi.obj" "DriverLib\eusci_a_spi.obj" "DriverLib\eusci_a_uart.obj" "DriverLib\eusci_b_i2c.obj" "DriverLib\eusci_b_spi.obj" "DriverLib\framctl.obj" "DriverLib\framctl_a.obj" "DriverLib\gpio.obj" "DriverLib\hspll.obj" "DriverLib\lcd_c.obj" "DriverLib\mpu.obj" "DriverLib\mpy32.obj" "DriverLib\mtif.obj" "DriverLib\pmm.obj" "DriverLib\ram.obj" "DriverLib\ref_a.obj" "DriverLib\rtc_b.obj" "DriverLib\rtc_c.obj" "DriverLib\saph.obj" "DriverLib\saph_a.obj" "DriverLib\sdhs.obj" "DriverLib\sfr.obj" "DriverLib\sysctl.obj" "DriverLib\timer_a.obj" "DriverLib\timer_b.obj" "DriverLib\tlv.obj" "DriverLib\uups.obj" "DriverLib\wdt_a.obj" "lib\hdc.obj" "lib\popcount_table.obj" 
	-$(RM) "hv.d" "image.d" "main.d" "uart.d" "DriverLib\adc12_b.d" "DriverLib\aes256.d" "DriverLib\comp_e.d" "DriverLib\crc.d" "DriverLib\crc32.d" "DriverLib\cs.d" "DriverLib\dma.d" "DriverLib\esi.d" "DriverLib\eusci_a_spi.d" "DriverLib\eusci_a_uart.d" "DriverLib\eusci_b_i2c.d" "DriverLib\eusci_b_spi.d" "DriverLib\framctl.d" "DriverLib\framctl_a.d" "DriverLib\gpio.d" "DriverLib\hspll.d" "DriverLib\lcd_c.d" "DriverLib\mpu.d" "DriverLib\mpy32.d" "DriverLib\mtif.d" "DriverLib\pmm.d" "DriverLib\ram.d" "DriverLib\ref_a.d" "DriverLib\rtc_b.d" "DriverLib\rtc_c.d" "DriverLib\saph.d" "DriverLib\saph_a.d" "DriverLib\sdhs.d" "DriverLib\sfr.d" "DriverLib\sysctl.d" "DriverLib\timer_a.d" "DriverLib\timer_b.d" "DriverLib\tlv.d" "DriverLib\uups.d" "DriverLib\wdt_a.d" "lib\hdc.d" "lib\popcount_table.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

