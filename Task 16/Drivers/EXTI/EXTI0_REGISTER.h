#ifndef EXTI0_REGISTER_H_
#define EXTI0_REGISTER_H_

#define GICR    (*(volatile uint8*)0x5B)
#define GIFR    (*(volatile uint8*)0x5A)

#define MCUCR   (*(volatile uint8*)0x55)
#define MCUCSR  (*(volatile uint8*)0x54)

#define INT0    6
#define INT1    7
#define INT2    5

#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define ISC2    6

#endif