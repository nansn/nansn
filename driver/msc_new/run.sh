setpci -s 0001:00:00.0  0x900.l=0x80000000 		
setpci -s 0001:00:00.0  0x918.l=0xf6000000  
setpci -s 0001:00:00.0  0x91c.l=0x0  				    
setpci -s 0001:00:00.0  0x90c.l=0x0 					 	
setpci -s 0001:00:00.0  0x910.l=0x0			
setpci -s 0001:00:00.0  0x914.l=0x8000			
setpci -s 0001:00:00.0  0x904.l=0x0		
setpci -s 0001:00:00.0  0x908.l=0x80000000		
stty -F /dev/ttyF0 115200
