#if !defined(PRIVATE_KEYBOARD_H)
#define PRIVATE_KEYBOARD_H

#define KEYBOARD_BUFFER_SIZE 128u

typedef struct keyboard_t {
	char key_buffer[KEYBOARD_BUFFER_SIZE];

	unsigned int key_head;
	unsigned int key_tail;

	uint8_t left_shift;
	uint8_t right_shift;
	uint8_t caps_lock;
	uint8_t extended;
	uint8_t pause_remaining;
} keyboard_t;

extern keyboard_t kb;

extern void keyboard_init(void);

extern void keyboard_enqueue(char c);
extern char keyboard_getchar(void);
extern void keyboard_irq_handler(void);

#endif
