#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "i2c-dev.h"
#include <stdio.h>

int main(int argc, char *argv[])
{

	int fd = 0;
	int ret = 0;

	char dev_name[64] = {};

	int addr = 0x6c;
	char data = 0;

	int bus = 0;
	int write_flag = 0;
	int offset = 0;
	int opt = 0;


	while ((opt = getopt(argc, argv, "b:rw:o:")) != -1) {
		switch (opt) {
		case 'b':
			bus = strtol(optarg, NULL, 16);
			break;
		case 'r':
			write_flag = 0;
			break;
		case 'w':
			write_flag = 1;
			data = strtol(optarg, NULL, 16);
			break;
		case 'o':
			offset = strtol(optarg, NULL, 16);
			break;

		}
	}

	snprintf(dev_name, 64, "/dev/i2c-%1d", bus);

	fd = open(dev_name, O_RDWR);
	if (fd < 0) {
		perror("open");
		exit(1);
	}

	ret = ioctl(fd, I2C_TENBIT, 0);
	if (ret < 0) {
		perror("I2C_TENBIT");
		exit(1);
	}

	ret = ioctl(fd, I2C_SLAVE, addr);
	if(ret < 0) {
		perror("I2C_SLAVE");
		exit(1);
	}

	if (write_flag) {
		i2c_smbus_write_byte_data(fd, offset, data);

	} else {
		data = i2c_smbus_read_byte_data(fd, offset);
		printf("data = 0x%x\n", data);
	}


	return 0;
	
}
