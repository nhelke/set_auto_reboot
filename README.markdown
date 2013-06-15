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

**WARNING!** The utility does no checking of what card it actually talking to. If you run this on a machine with a different device at that address the results are not defined and could cause permanent damage to your hardware. Only use this if you know what you are doing and use at own risk.
