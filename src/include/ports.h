#if !defined(PORTS_H)
#define PORTS_H

#define PORT_COM1          0x03F8

#define PORT_PS2_DATA      0x0060
#define PORT_PS2_STATUS    0x0064

#define PORT_PIC1_COMMAND  0x0020
#define PORT_PIC1_DATA     0x0021

#define PORT_PIC2_COMMAND  0x00A0
#define PORT_PIC2_DATA     0x00A1

extern void outb(uint16_t port, uint8_t value);
extern uint8_t inb(uint16_t port);

#endif
