#define IOCPARM_MASK    0x1fff
#define	IOC_VOID        0x20000000
#define IOC_OUT         0x40000000
#define IOC_IN          0x80000000
#define IOC_INOUT       (IOC_IN|IOC_OUT)

#define _IOC(inout,group,num,len) (inout | ((len & IOCPARM_MASK) << 16) | ((group) << 8) | (num))
#define _IO(g,n)        _IOC(IOC_VOID,  (g), (n), 0)
#define _IOR(g,n,t)     _IOC(IOC_OUT,   (g), (n), sizeof(t))
#define _IOW(g,n,t)     _IOC(IOC_IN,    (g), (n), sizeof(t))
#define _IOWR(g,n,t)    _IOC(IOC_INOUT, (g), (n), sizeof(t))

struct winsize {
	unsigned short  ws_row;
	unsigned short  ws_col;
	unsigned short  ws_xpixel;
	unsigned short  ws_ypixel;
};

#define TIOCMODG        _IOR('t', 3, int)
#define TIOCMODS        _IOW('t', 4, int)
#define TIOCM_LE             0001
#define TIOCM_DTR            0002
#define TIOCM_RTS            0004
#define TIOCM_ST             0010
#define TIOCM_SR             0020
#define TIOCM_CTS            0040
#define TIOCM_CAR            0100
#define TIOCM_CD             TIOCM_CAR
#define TIOCM_RNG            0200
#define TIOCM_RI             TIOCM_RNG
#define TIOCM_DSR            0400
#define TIOCEXCL         _IO('t', 13)
#define TIOCNXCL         _IO('t', 14)
#define TIOCFLUSH       _IOW('t', 16, int)
#define TIOCGETA        _IOR('t', 19, struct termios)
#define TIOCSETA        _IOW('t', 20, struct termios)
#define TIOCSETAW       _IOW('t', 21, struct termios)
#define TIOCSETAF       _IOW('t', 22, struct termios)
#define TIOCGETD        _IOR('t', 26, int)
#define TIOCSETD        _IOW('t', 27, int)
#define TIOCIXON         _IO('t', 129)
#define TIOCIXOFF        _IO('t', 128)
#define TIOCSBRK         _IO('t', 123)
#define TIOCCBRK         _IO('t', 122)
#define TIOCSDTR         _IO('t', 121)
#define TIOCCDTR         _IO('t', 120)
#define TIOCGPGRP       _IOR('t', 119, int)
#define TIOCSPGRP       _IOW('t', 118, int)
#define TIOCOUTQ        _IOR('t', 115, int)
#define TIOCSTI         _IOW('t', 114, char)
#define TIOCNOTTY        _IO('t', 113)
#define TIOCPKT         _IOW('t', 112, int)
#define TIOCPKT_DATA         0x00
#define TIOCPKT_FLUSHREAD    0x01
#define TIOCPKT_FLUSHWRITE   0x02
#define TIOCPKT_STOP         0x04
#define TIOCPKT_START        0x08
#define TIOCPKT_NOSTOP       0x10
#define TIOCPKT_DOSTOP       0x20
#define TIOCPKT_IOCTL        0x40
#define TIOCSTOP         _IO('t', 111)
#define TIOCSTART        _IO('t', 110)
#define TIOCMSET        _IOW('t', 109, int)
#define TIOCMBIS        _IOW('t', 108, int)
#define TIOCMBIC        _IOW('t', 107, int)
#define TIOCMGET        _IOR('t', 106, int)
#define TIOCREMOTE      _IOW('t', 105, int)
#define TIOCGWINSZ      _IOR('t', 104, struct winsize)
#define TIOCSWINSZ      _IOW('t', 103, struct winsize)
#define TIOCUCNTL       _IOW('t', 102, int)
#define TIOCSTAT         _IO('t', 101)
#define UIOCCMD(n)       _IO('u', n)
#define TIOCSCONS        _IO('t', 99)
#define TIOCCONS        _IOW('t', 98, int)
#define TIOCSCTTY        _IO('t', 97)
#define TIOCEXT         _IOW('t', 96, int)
#define TIOCSIG          _IO('t', 95)
#define TIOCDRAIN        _IO('t', 94)
#define TIOCMSDTRWAIT   _IOW('t', 91, int)
#define TIOCMGDTRWAIT   _IOR('t', 90, int)
#define TIOCTIMESTAMP   _IOR('t', 89, struct timeval)
#define TIOCDCDTIMESTAMP _IOR('t', 88, struct timeval) 
#define TIOCSDRAINWAIT  _IOW('t', 87, int)
#define TIOCGDRAINWAIT  _IOR('t', 86, int)
#define TIOCDSIMICROCODE _IO('t', 85)
#define TIOCPTYGRANT    _IO('t', 84)
#define TIOCPTYGNAME    _IOC(IOC_OUT, 't', 83, 128)
#define TIOCPTYUNLK     _IO('t', 82)

#define TTYDISC           0
#define TABLDISC          3
#define SLIPDISC          4
#define PPPDISC           5

