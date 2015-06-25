#
# w3mimg/Makefile
#

SHELL=/bin/sh
srcdir = .
top_srcdir = ..
VPATH = .
CFLAGS=$(OPTS) -I.. -I$(top_srcdir) -I$(srcdir) -g -O2 -I$(srcdir)/libwc  -DHAVE_CONFIG_H $(IMGCFLAGS)
AR=ar
RANLIB=ranlib
RM=rm

SUBDIRS=fb x11 win
IMGCFLAGS=  
IMGOBJS=w3mimg.o x11/x11_w3mimg.o fb/fb_w3mimg.o fb/fb.o fb/fb_img.o fb/fb_w3mimg.o fb/fb.o fb/fb_img.o

.PHONY: $(SUBDIRS)
all: x11 fb w3mimg.a

w3mimg.a: $(IMGOBJS)
	$(AR) rv $@ $(IMGOBJS)
	$(RANLIB) $@

w3mimg.o: w3mimg.c
	$(CC) $(CFLAGS) -c $<

$(SUBDIRS):
	cd $@ && $(MAKE) CC="$(CC)" OPTS="$(OPTS)"

clean:
	@-$(RM) -f *.o
	@for dir in $(SUBDIRS); do \
		(cd $$dir && $(MAKE) clean RM=$(RM)); \
	 done
	-$(RM) -f w3mimg.a

distclean: clean
	for subdir in $(SUBDIRS); \
	do \
		(cd $$subdir && $(MAKE) distclean); \
	done
	-$(RM) -f Makefile


#
