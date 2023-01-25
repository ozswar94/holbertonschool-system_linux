#include <stdio.h>
#include <elf.h>
#include "machine.h"

void choose_machine(int id_machine)
{
	int i;
	machine_t table_machine[] = {
	{EM_NONE, "No machine"}, {EM_M32, "AT&T WE 32100"}, {EM_ARM, "ARM"},
	{EM_SPARC, "SUN SPARC"}, {EM_386, "Intel 80386"},
	{EM_68K, "Motorola m68k family"}, {EM_88K, "Motorola m88k family"},
	{EM_860, "Intel 80860"}, {EM_MIPS, "MIPS R3000 big-endian"},
	{EM_S370, "IBM System/370"}, {EM_SVX, "Silicon Graphics SVx"},
	{EM_MIPS_RS3_LE, "MIPS R3000 little-endian"},
	{EM_PARISC, "HPPA"}, {EM_VPP500, "Fujitsu VPP500"},
	{EM_SPARC32PLUS, "Sun's \"v8plus\""}, {EM_960, "Intel 80960"},
	{EM_PPC, "PowerPC"}, {EM_PPC64, "PowerPC 64-bit"},
	{EM_S390, "IBM S390"}, {EM_V800, "NEC V800 series"},
	{EM_FR20, "Fujitsu FR20"}, {EM_RH32, "TRW RH-32"},
	{EM_RCE, "Motorola RCE"}, {EM_PCP, "Siemens PCP"},
	{EM_FAKE_ALPHA, "Digital Alpha"}, {EM_SH, "Hitachi SH"},
	{EM_SPARCV9, "SPARC v9 64-bit"}, {EM_TRICORE, "Siemens Tricore"},
	{EM_SPARC, "Argonaut RISC Core"}, {EM_H8_300, "Hitachi H8/300"},
	{EM_H8_300H, "Hitachi H8/300H"}, {EM_H8S, "Hitachi H8S"},
	{EM_H8_500, "Hitachi H8/500"}, {EM_IA_64, "Intel Merced"},
	{EM_MIPS_X, "Stanford MIPS-X"}, {EM_COLDFIRE, " Motorola Coldfire"},
	{EM_68HC12, "Motorola M68HC12"}, {EM_FX66, "Siemens FX66 microcontroller"},
	{EM_MMA, "Fujitsu MMA Multimedia Accelerator"},
	{EM_NCPU, "Sony nCPU embeeded RISC"},
	{EM_NDR1, "Denso NDR1 microprocessor"},
	{EM_STARCORE, "Motorola Start*Core processor"},
	{EM_ME16, "Toyota ME16 processor"}, {EM_PRISM, "SiTera Prism"},
	{EM_ST100, "STMicroelectronic ST100 processor"},
	{EM_TINYJ, "Advanced Logic Corp. Tinyj emb.fam"},
	{EM_X86_64, "AMD x86-64 architecture"},
	{EM_PDSP, "Sony DSP Processor"}, {EM_VAX, "Digital VAX"},
	{EM_ST9PLUS, "STMicroelectronics ST9+ 8/16 mc"},
	{EM_ST7, "STmicroelectronics ST7 8 bit mc"},
	{EM_68HC16, "Motorola MC68HC16 microcontroller"},
	{EM_68HC11, "Motorola MC68HC11 microcontroller"},
	{EM_68HC08, "Motorola MC68HC08 microcontroller"},
	{EM_68HC05, "Motorola MC68HC05 microcontroller"},
	{EM_ST19, "STMicroelectronics ST19 8 bit mc"},
	{EM_CRIS, "Axis Communications 32-bit embedded processor"},
	{EM_JAVELIN, "Infineon Technologies 32-bit embedded processor"},
	{EM_FIREPATH, "Element 14 64-bit DSP Processor"},
	{EM_ZSP, "LSI Logic 16-bit DSP Processor"},
	{EM_MMIX, "Donald Knuth's educational 64-bit processor"},
	{EM_HUANY, "Harvard University machine-independent object files"},
	{EM_AVR, "Atmel AVR 8-bit microcontroller"}, {EM_FR30, "Fujitsu FR30"},
	{EM_D10V, "Mitsubishi D10V"}, {EM_D30V, "Mitsubishi D30V"},
	{EM_V850, "NEC v850"}, {EM_M32R, "Mitsubishi M32R"},
	{EM_MN10300, "Matsushita MN10300"}, {EM_MN10200, "Matsushita MN10200"},
	{EM_PJ, "picoJava"}, {EM_ARC_A5, "ARC Cores Tangent-A5"},
	{EM_OPENRISC, "OpenRISC 32-bit embedded processor"},
	{EM_XTENSA, "Tensilica Xtensa Architecture"},
	{0, "\0"}
	};

	for (i = 0; table_machine[i].name != "\0"; i++)
	{
		if (table_machine[i].id == id_machine)
		{
			printf("%s\n", table_machine[i].name);
			return;
		}
	}
}
