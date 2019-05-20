set_auto_reboot
===============

This tiny FreeBSD utility set the control bit on the following card:

	isab0@pci0:0:3:0:	class=0x060100 card=0xcb89106b chip=0x0d8010de rev=0xa2 hdr=0x00
	    vendor     = 'nVidia Corporation'
	    device     = 'MCP89 LPC Bridge'
	    class      = bridge
	    subclass   = PCI-ISA
	    bar   [10] = type I/O Port, range 32, base 0x2100, size 256, enabled

in order to activate the auto reboot on power failure setting.

This has been tested on a Mac mini 2011.

This script will now check that the chip id is infact the one listed above to prevent it from running on the wrong type of machine


Usage
-----

I use this software to set that bit on each boot of a Mac mini server I have at home and which runs FreeBSD because ZFS is the best filesystem there is.

If you are interested in using this please give me a shout at nhelke+set_auto_reboot@gmail.com and I will be more than happy to help integrate this into your setup.
