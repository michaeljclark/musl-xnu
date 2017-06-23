musl-xnu
===============

musl-xnu is a port of musl libc to the macOS XNU kernel.


Build Prerequisites
-------------------

The only build-time prerequisites for musl-xnu are GNU Make and Xcode.

Tested with macOS-10.12.4, clang-802.0.42 and ld64-278.4.


Supported Targets
-----------------

musl-xnu can be built for the following versions of macOS:

* macOS (10.12 Sierra x86_64)


Build and Installation Procedure
--------------------------------

To build musl-xnu:

1. Run "make -f Makefile.xnu" to compile.

3. Run "make -f Makefile.xnu examples" to build the test programs
