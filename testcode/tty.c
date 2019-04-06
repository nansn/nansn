#include    <string.h>
#include    <termios.h>         
#include    <sys/select.h>
#include    <time.h>
#include    <sys/syscall.h>
#include    <sys/types.h>
#include    <fcntl.h>
#include    <stdio.h>
#include <sched.h>





int fd = 0;
int len = 0;
unsigned char recv_data[512] = {0};
unsigned char send_buff[512] = {0};

static void * read_uart(void *arg)
{
    int count = 0;
    int i = 0;



    struct sched_param param;
    param.sched_priority = 90;
    if(0 != sched_setscheduler(syscall(SYS_gettid), SCHED_FIFO, &param))
    {
        printf("Error, sched_setscheduler() failed.\n");
        return ;
    }


    for (;;) {
        
        memset(recv_data, 0, len);

        count = 0;



        printf("\n---begin\n\n");

        do {

            count += read(fd, recv_data + count , len - count);

        } while (count != len);

        for (i = 0; i < len; i++ ) {
            printf("%04u ", recv_data[i]);
            if (( (i+1) % 8) == 0) {
                printf("\n");
            }

        }

        printf("\n--end\n\n");

    } 

    return NULL;
}


int main(int argc,char *argv[])
{
	struct termios options;


    pthread_t tid;


    int  i = 0;

    int ret = 0;


     len = 32;

    if (argc > 1) {
    
        len = atoi(argv[1]);
    
    }

	fd = open("/dev/ti335x_uart1", O_RDWR | O_NOCTTY);
	if(fd < 0) {
		printf("error cann't open node:%s\n" ); 
		return -1;
	}
  
	tcgetattr (fd, &options);
 	cfsetispeed (&options, B115200);
  	cfsetospeed (&options, B115200);


    options.c_cflag &= ~(CRTSCTS | PARENB | CSTOPB | CSIZE);
    options.c_cflag |= (CS8 | CLOCAL | CREAD);  

    /* cfg c_iflag */
    options.c_iflag = 0;
    options.c_oflag &= ~OPOST;

    /* cfg c_lflag */
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

  	options.c_cc[VTIME]= 0;
    options.c_cc[VMIN]= 1;
  	
  	tcsetattr (fd, TCSANOW, &options);

    tcflush(fd, TCIOFLUSH);

    pthread_create(&tid, NULL, read_uart, NULL);
    sleep(1);


    for (i = 0 ; i <  len; i++) {
        send_buff[i] = i;
    }



    while (1) {
        ret = write(fd , send_buff, len); 

        if (ret != len) {
        
            printf("no send complete\n");
        }
        usleep(10);

    }


	return(0);
}
