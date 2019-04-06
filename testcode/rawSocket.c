#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netpacket/packet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <unistd.h>
#include <net/if.h>
#include <string.h>
#include <linux/if_ether.h>
#include <arpa/inet.h>

/* copy from linux kernel */

#define ETH_ALEN    6       /* Octets in one ethernet addr   */
#define ETH_P_8021Q 0x8100          /* 802.1Q VLAN Extended Header  */
#define VLAN_VID_MASK       0x0fff /* VLAN Identifier */

struct ethhdr {
    unsigned char   h_dest[ETH_ALEN];   /* destination eth addr */
    unsigned char   h_source[ETH_ALEN]; /* source ether addr    */
    unsigned short  h_proto;        /* packet type ID field */
} __attribute__((packed));


struct vlan_ethhdr {
    unsigned char   h_dest[ETH_ALEN];
    unsigned char   h_source[ETH_ALEN];
    unsigned short  h_vlan_proto;
    unsigned short  h_vlan_TCI;
    unsigned short  h_vlan_encapsulated_proto;
} __attribute__((packed));



int getifindex(int fd, char *ifname)
{
    struct ifreq ifr;

    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, ifname);

    if(-1 == ioctl(fd, SIOCGIFINDEX, &ifr)) {
        perror("ioctl");
        return -1;
    }

    return ifr.ifr_ifindex;
}


#define ETH_FRAME_LEN  1518
 
int main(int argc, char *argv[])
{
    int fd;
    int n;
    int i;
    unsigned char buf[ETH_FRAME_LEN];
    struct sockaddr_ll sll;
    struct ethhdr * mac_hdr = NULL;
    struct vlan_ethhdr * vlan_hdr = NULL;


    if (argc < 2) {
        printf("less parameter, please enter ethX\n");
    }

    fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));    
    if (fd < 0) {
        perror("socket()");
        return -1;
    }

    sll.sll_family = PF_PACKET;
    sll.sll_ifindex = getifindex(fd, argv[1]);
    sll.sll_protocol = htons(ETH_P_ALL);

    if (bind(fd, (struct sockaddr *)&sll, sizeof(sll)) < 0) {
        perror("bind");
        return -1;
    }
     
    while (1) {
        n = recv(fd, buf, ETH_FRAME_LEN, 0);
        if (n <= 0) {
            continue;
        }

        mac_hdr = (struct ethhdr *) (&buf[0]);
        if (mac_hdr->h_proto == htons(ETH_P_8021Q)) {
            vlan_hdr = (struct vlan_hdr *) (&buf[0]);

            printf("dst %2x:%2x:%2X:%2x:%2x:%2x \n", vlan_hdr->h_dest[0], vlan_hdr->h_dest[1], vlan_hdr->h_dest[2],
                    vlan_hdr->h_dest[3],vlan_hdr->h_dest[4],vlan_hdr->h_dest[5]);
            printf("src %2x:%2x:%2X:%2x:%2x:%2x \n", vlan_hdr->h_source[0], vlan_hdr->h_source[1], vlan_hdr->h_source[2],
                    vlan_hdr->h_source[3],vlan_hdr->h_source[4],vlan_hdr->h_source[5]);
            printf("vlan: %d\n", vlan_hdr->h_vlan_TCI & VLAN_VID_MASK);

        }
    }
     
    return 0;
}
