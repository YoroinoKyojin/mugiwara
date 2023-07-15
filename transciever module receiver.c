#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define BAUD_RATE B9600
#define SERIAL_PORT "/dev/ttyUSB0"

int configure_serial(int fd)
{
    struct termios serial_options;
    tcgetattr(fd, &serial_options);
    
    // Set baud rate
    cfsetispeed(&serial_options, BAUD_RATE);
    cfsetospeed(&serial_options, BAUD_RATE);

    // Set data size and parity
    serial_options.c_cflag &= ~PARENB; // No parity
    serial_options.c_cflag &= ~CSTOPB; // 1 stop bit
    serial_options.c_cflag &= ~CSIZE;  // Clear data size bits
    serial_options.c_cflag |= CS8;     // 8 bits per byte

    // Apply the configuration
    tcsetattr(fd, TCSANOW, &serial_options);

    return 0;
}

int main()
{
    int fd;
    char data[256];

    // Open the serial port
    fd = open(SERIAL_PORT, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("Error opening serial port");
        return -1;
    }

    // Configure serial port
    if (configure_serial(fd) != 0) {
        perror("Error configuring serial port");
        close(fd);
        return -1;
    }

    // Send data
    strcpy(data, "Hello, transceiver!");
    write(fd, data, strlen(data));

    // Receive data
    memset(data, 0, sizeof(data));
    read(fd, data, sizeof(data));
    printf("Received data: %s\n", data);

    // Close the serial port
    close(fd);

    return 0;
}
