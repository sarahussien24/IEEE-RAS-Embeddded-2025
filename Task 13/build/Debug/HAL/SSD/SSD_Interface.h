#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define COMMON_ANODE               0
#define COMMON_CATHODE             1

void SSD_voidInitSegmentPort ( u8 Copy_u8PortNumber );
void SSD_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_SegmentPolarity , u8 Copy_u8Number );

#endif