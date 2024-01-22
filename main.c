#include <stdint.h>

#define SIM_5    (*((volatile uint32_t*)0x40048038))

#define PCR_PTB22 (*((volatile uint32_t*)0x4004A058))//manipula al PTB22 4004A058
#define PCR_PTB21 (*((volatile uint32_t*)0x4004A054))//manipula al PTB21 4004A054
#define PCR_PTE26 (*((volatile uint32_t*)0x4004D068))//manipula al PTE26 primer cambio

//REGISTROS GPIO
// sirve para el GPIO del puerto B 21 y 22 y para E 26

#define GPIO_B_BASE_ADDR (((volatile uint32_t*)0x400FF040))
#define GPIO_E_BASE_ADDR (((volatile uint32_t*)0x400FF100))

typedef struct
    	{
		uint32_t PDOR;
		uint32_t PSOR;
		uint32_t PCOR;
		uint32_t PTOR;
		uint32_t PDIR;
		uint32_t PDDR;
    	} GPIO_t;

#define GPIO_B ((GPIO_t*)GPIO_B_BASE_ADDR)
#define GPIO_E ((GPIO_t*)GPIO_E_BASE_ADDR)

int main (void){

    SIM_5 = 0X00002400; // este es para el B

    PCR_PTB22 = 0X00000100;
    PCR_PTB21 = 0X00000100;
    PCR_PTE26 = 0X00000100;

    while (1){

        GPIO_B -> PDDR = 0X00400000;
    	GPIO_B -> PDOR = 0X00400000; //enciende led rojo

    	GPIO_B -> PDDR = 0X00200000;
        GPIO_B -> PDOR = 0X00200000; //enciende led azul

        GPIO_E -> PDDR = 0X04000000;
        GPIO_E -> PDOR = 0X04000000; //enciende led verde

    }

    return 0;
}
