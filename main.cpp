// This program initializes an HD44780-based LCD-Display, attached to the system's
// I2C-bus via an MCP23017 (e.g. https://learn.adafruit.com/adafruit-16x2-character-lcd-plus-keypad-for-raspberry-pi)

#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <unistd.h>

int file;

void write2byte(uint8_t byte0, uint8_t byte1) {
    uint8_t buf[2];
    buf[0] = byte0;
    buf[1] = byte1;
    write(file, buf, 2);
}

void write13(uint8_t byte) {
    uint8_t buf[2];
    buf[0] = 0x13;
    buf[1] = byte;
    write(file, buf, 2);
}

int main() {
    uint8_t buf[2];

    if ((file = open("/dev/i2c-1", O_RDWR)) < 0) {
        exit(1);
    }

    // The I2C expander is listening at address 0x20
    if (ioctl(file, I2C_SLAVE, 0x20) < 0) {
        exit(1);
    }

    // The initialisation sequence is taken from the starup of LCDd
    // with the respective driver as seen by strace
    write2byte(0x00, 0x1f);
    write2byte(0x01, 0x00);
    write2byte(0x0c, 0x1f);
    write2byte(0x0d, 0x00);

    write13(0x38);
    usleep(1);
    write13(0x18);
    write13(0x38);
    usleep(1);
    write13(0x18);
    usleep(2);
    write13(0x38);
    usleep(1);
    write13(0x18);
    write13(0x28);
    usleep(1);
    write13(0x08);
    usleep(2);
    write13(0x28);
    usleep(1);
    write13(0x08);
    write13(0x22);
    usleep(1);
    write13(0x02);
    usleep(41);
    write13(0x20);
    usleep(1);
    write13(0x00);
    write13(0x22);
    usleep(1);
    write13(0x02);
    usleep(41);
    write13(0x20);
    usleep(1);
    write13(0x00);
    write13(0x30);
    usleep(1);
    write13(0x10);
    usleep(1601);
    write13(0x20);
    usleep(1);
    write13(0x00);
    write13(0x2c);
    usleep(1);
    write13(0x0c);
    usleep(41);
    write13(0x20);
    usleep(1);
    write13(0x00);
    write13(0x28);
    usleep(1);
    write13(0x08);
    usleep(1601);
    write13(0x20);
    usleep(1);
    write13(0x00);
    write13(0x26);
    usleep(1);
    write13(0x06);
    usleep(41);

    write2byte(0x12, 0x1f);

    // Begin Text ;)
    write13(0x06);
    write13(0x22);
    usleep(1);
    write13(0x02);
    write13(0x20);
    usleep(1);
    write13(0x00);
    usleep(1);
    usleep(41);
    write13(0xa4);
    usleep(1);
    write13(0x84);
    write13(0xa4);
    usleep(1);
    write13(0x84);
    usleep(1);
    usleep(40);
    write13(0xac);
    usleep(1);
    write13(0x8c);
    write13(0xb2);
    usleep(1);
    write13(0x92);
    usleep(1);
    usleep(40);
    write13(0xac);
    usleep(1);
    write13(0x8c);
    write13(0xb4);
    usleep(1);
    write13(0x94);
    usleep(1);
    usleep(40);
    write13(0xa8);
    usleep(1);
    write13(0x88);
    write13(0xa0);
    usleep(1);
    write13(0x80);
    usleep(1);
    usleep(40);
    write13(0xa4);
    usleep(1);
    write13(0x84);
    write13(0xba);
    usleep(1);
    write13(0x9a);
    usleep(1);
    usleep(40);
    write13(0xac);
    usleep(1);
    write13(0x8c);
    write13(0xb2);
    usleep(1);
    write13(0x92);
    usleep(1);
    usleep(40);
    write13(0xbc);
    usleep(1);
    write13(0x9c);
    write13(0xb8);
    usleep(1);
    write13(0x98);
    usleep(1);
    usleep(40);
    write13(0xbc);
    usleep(1);
    write13(0x9c);
    write13(0xa4);
    usleep(1);
    write13(0x84);
    usleep(1);
    usleep(40);
    write13(0xac);
    usleep(1);
    write13(0x8c);
    write13(0xb4);
    usleep(1);
    write13(0x94);
    usleep(1);
    usleep(40);
    write13(0xa8);
    usleep(1);
    write13(0x88);
    write13(0xa0);
    usleep(1);
    write13(0x80);
    usleep(1);
    usleep(40);
    write13(0xb8);
    usleep(1);
    write13(0x98);
    write13(0xb8);
    usleep(1);
    write13(0x98);
    usleep(1);
    usleep(40);
    write13(0xb8);
    usleep(1);
    write13(0x98);
    write13(0xa0);
    usleep(1);
    write13(0x80);
    usleep(1);
    usleep(40);
    write13(0xb8);
    usleep(1);
    write13(0x98);
    write13(0xa0);
    usleep(1);
    write13(0x80);
    usleep(1);
    usleep(40);
    write13(0xb8);
    usleep(1);
    write13(0x98);
    write13(0xa0);
    usleep(1);
    write13(0x80);
    usleep(1);
    usleep(40);
    write13(0xa8);
    usleep(1);
    write13(0x88);
    write13(0xa0);
    usleep(1);
    write13(0x80);
    usleep(1);
    usleep(40);
    write13(0xa8);
    usleep(1);
    write13(0x88);
    write13(0xa0);
    usleep(1);
    write13(0x80);
    usleep(1);
    usleep(40);
    write13(0x26);
    usleep(1);
    write13(0x06);
    write13(0x20);
    usleep(1);
    write13(0x00);
    usleep(1);
    usleep(40);
    write13(0xa8);
    usleep(1);
    write13(0x88);
    write13(0xa0);
    usleep(1);
    write13(0x80);
    usleep(1);
    usleep(40);
    write13(0xa4);
    usleep(1);
    write13(0x84);
    write13(0xac);
    usleep(1);
    write13(0x8c);
    usleep(1);
    usleep(40);
    write13(0xae);
    usleep(1);
    write13(0x8e);
    write13(0xb0);
    usleep(1);
    write13(0x90);
    usleep(1);
    usleep(40);
    write13(0xac);
    usleep(1);
    write13(0x8c);
    write13(0xa2);
    usleep(1);
    write13(0x82);
    usleep(1);
    usleep(40);
    write13(0xbc);
    usleep(1);
    write13(0x9c);
    write13(0xa8);
    usleep(1);
    write13(0x88);
    usleep(1);
    usleep(40);
    write13(0xbc);
    usleep(1);
    write13(0x9c);
    write13(0xa4);
    usleep(1);
    write13(0x84);
    usleep(1);
    usleep(40);
    write13(0xa8);
    usleep(1);
    write13(0x88);
    write13(0xa0);
    usleep(1);
    write13(0x80);
    usleep(1);
    usleep(40);
    write13(0xa4);
    usleep(1);
    write13(0x84);
    write13(0xae);
    usleep(1);
    write13(0x8e);
    usleep(1);
    usleep(40);
    write13(0xbc);
    usleep(1);
    write13(0x9c);
    write13(0xb4);
    usleep(1);
    write13(0x94);
    usleep(1);
    usleep(40);
    write13(0xac);
    usleep(1);
    write13(0x8c);
    write13(0xac);
    usleep(1);
    write13(0x8c);
    usleep(1);
    usleep(40);
    write13(0xac);
    usleep(1);
    write13(0x8c);
    write13(0xac);
    usleep(1);
    write13(0x8c);
    usleep(1);
    usleep(40);
    write13(0xa8);
    usleep(1);
    write13(0x88);
    write13(0xa0);
    usleep(1);
    write13(0x80);
    usleep(1);
    usleep(40);
    write13(0xb8);
    usleep(1);
    write13(0x98);
    write13(0xaa);
    usleep(1);
    write13(0x8a);
    usleep(1);
    usleep(40);
    write13(0xa4);
    usleep(1);
    write13(0x84);
    write13(0xa4);
    usleep(1);
    write13(0x84);

    close(file);
}
