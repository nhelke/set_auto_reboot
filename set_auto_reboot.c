#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <sys/ioctl.h>
#include <sys/pciio.h>
#include <fcntl.h>

int main() {

	int ret;

	int f = open("/dev/pci", O_RDONLY|O_WRONLY);
	if (f < 0) {
		perror("Unable to open PCI dev for reading and writing");
		exit(2);
	}
	struct pci_io d;
	d.pi_sel.pc_domain = 0;
	d.pi_sel.pc_bus = 0;
	d.pi_sel.pc_dev = 3;
	d.pi_sel.pc_func = 0;
	d.pi_reg = 0x7b;
	d.pi_width = 1;

	ret = ioctl(f, PCIOCREAD, &d);
	if (ret != 0) {
		perror("Unable to perform PCIOCREAD");
		exit(3);
	} else {
		const unsigned mask = 1<<6;
		if (d.pi_data & mask) {
			printf("Auto reboot bit NOT SET. Setting auto reboot bit.\n");
			d.pi_data = d.pi_data & ~mask;
			ret = ioctl(f, PCIOCWRITE, &d);
			if (ret != 0) {
				perror("Unable to perform PCIOCWRITE");
				exit(4);
			}
		} else {
			printf("Auto reboot bit SET. Nothing to do.\n");
		}
	}
}
