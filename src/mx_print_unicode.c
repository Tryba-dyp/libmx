#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
	if (c < 0x80) {
		char symb[1]; 
		symb[0] = (c >> 0 & 0x7F) | 0x00;

		write(1, symb, 1);
	} else if (c < 0x0800) {
		char symb[2];
		symb[0] = (c >> 6 & 0x1F) | 0xC0;
		symb[1] = (c >> 0 & 0x3F) | 0x80;

		write(1, symb, 2);
	} else if (c < 0x010000) {
		char symb[3];
		symb[0] = (c >> 12 & 0x0F) | 0xE0;
		symb[1] = (c >> 6 & 0x3F) | 0x80;
		symb[2] = (c >> 0 & 0x3F) | 0x80;

		write(1, symb, 3);
	} else if (c < 0x110000) {
		char symb[4];
		symb[0] = (c >> 18 & 0x07) | 0xF0;
		symb[1] = (c >> 12 & 0x3F) | 0x80;
		symb[2] = (c >> 6 & 0x3F) | 0x80;
		symb[3] = (c >> 0 & 0x3F) | 0x80;

		write(1, symb, 4);
	}   
}

