#
# Makefile
# Makefile.  Generated from Makefile.in by configure.
#

SHELL=/bin/sh
PACKAGE = w3m
VERSION = 0.5.3
DOMAIN = $(PACKAGE)
prefix = /usr/local
exec_prefix = ${prefix}
datarootdir = ${prefix}/share
bindir = ${exec_prefix}/bin
datadir = ${datarootdir}
localedir = $(datadir)/locale
libdir = ${exec_prefix}/lib
includedir = ${prefix}/include
infodir = ${datarootdir}/info
libexecdir = ${exec_prefix}/libexec
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
oldincludedir = /usr/include
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
top_srcdir = .
top_builddir = .
VPATH = $(top_srcdir):.

CGIBIN_DIR = $(libexecdir)/$(PACKAGE)/cgi-bin
AUXBIN_DIR = $(libexecdir)/$(PACKAGE)
HELP_DIR = ${datarootdir}/w3m
RC_DIR = ~/.w3m
ETC_DIR = $(sysconfdir)
CONF_DIR = $(sysconfdir)/$(PACKAGE)

CFLAGS = $(OPTS) -I. -I$(top_srcdir) -g -O2 -I$(srcdir)/libwc $(CPPFLAGS) $(DEFS)
WCCFLAGS = -DUSE_UNICODE -I$(srcdir) -I$(srcdir)/..
CPPFLAGS = 
DEFS = -DHAVE_CONFIG_H -DAUXBIN_DIR=\"$(AUXBIN_DIR)\" \
	-DCGIBIN_DIR=\"$(CGIBIN_DIR)\" -DHELP_DIR=\"$(HELP_DIR)\" \
	-DETC_DIR=\"$(ETC_DIR)\" -DCONF_DIR=\"$(CONF_DIR)\" \
	-DRC_DIR=\"$(RC_DIR)\" \
        -DLOCALEDIR=\"$(localedir)\"
LDFLAGS = 
LIBS = -lm  -lnsl -ldl
GC_LIBS = -lgc
EXT_LIBS = -L. -lindep  $(GC_LIBS)
W3M_LIBS =  -L./libwc -lwc -ltermcap
WCTARGET = libwc/libwc.a
NLSTARGET = po

MAKE_ARGS = PERL='$(PERL)' MKDIR='$(MKDIR)' \
	BIN_DIR='$(bindir)' AUXBIN_DIR='$(AUXBIN_DIR)' \
	CGIBIN_DIR='$(CGIBIN_DIR)' \
	HELP_DIR='$(HELP_DIR)' MAN_DIR='$(mandir)' ETC_DIR='$(ETC_DIR)' \
	CONF_DIR='$(CONF_DIR)' \
	RC_DIR='$(RC_DIR)' DESTDIR='$(DESTDIR)' KEYBIND_SRC='$(KEYBIND_SRC)'

IMGCFLAGS =   
IMGLDFLAGS = -lImlib2 -lImlib2 

CC0 = gcc
CXX = g++
IMGLINK = $(CC)
CC =  $(CC0)
CPP = gcc -E
RANLIB=ranlib
AWK = gawk
PERL = /bin/perl
MKDIR=mkdir -p
MV=mv
RM=rm
AR=ar
INSTALL=/bin/install -c
INSTALL_PROGRAM=${INSTALL}
INSTALL_SCRIPT=${INSTALL}
INSTALL_DATA=${INSTALL} -m 644
INSTALL_W3MIMGDISPLAY=${INSTALL_PROGRAM}

HELP_FILE = w3mhelp-w3m_en.html
KEYBIND_SRC = keybind.c
KEYBIND_OBJ = keybind.o

VERSION=0.5.3
MODEL=-EN

SRCS=main.c file.c buffer.c display.c etc.c search.c linein.c table.c local.c \
	form.c map.c frame.c rc.c menu.c mailcap.c image.c \
	symbol.c entity.c terms.c url.c ftp.c mimehead.c regex.c news.c \
	func.c cookie.c history.c backend.c $(KEYBIND_SRC)
OBJS=main.o file.o buffer.o display.o etc.o search.o linein.o table.o local.o\
	form.o map.o frame.o rc.o menu.o mailcap.o image.o \
	symbol.o entity.o terms.o url.o ftp.o mimehead.o regex.o news.o \
	func.o cookie.o history.o backend.o $(KEYBIND_OBJ)
LSRCS=anchor.c parsetagx.c tagtable.c istream.c
LOBJS=anchor.o parsetagx.o tagtable.o istream.o
LLOBJS=version.o
ALIBOBJS=Str.o indep.o regex.o textlist.o parsetag.o myctype.o hash.o
ALIB=libindep.a
ALLOBJS=$(OBJS) $(LOBJS) $(LLOBJS)

EXT=

TARGET=$(PACKAGE)$(EXT)
BOOKMARKER=w3mbookmark$(EXT)
HELPER=w3mhelperpanel$(EXT)
INFLATE=inflate$(EXT)
IMGDISPLAY=w3mimgdisplay$(EXT)
MAN1_TARGET=$(PACKAGE).1
MAN1=$(top_srcdir)/doc/w3m.1
MAN1_JA=$(top_srcdir)/doc-jp/w3m.1

LIB_TARGETS=$(BOOKMARKER) $(HELPER)
AUXBIN_TARGETS= w3mimgdisplay$(EXT) inflate$(EXT)
TARGETS=$(TARGET) $(LIB_TARGETS) $(AUXBIN_TARGETS)
HELP_TARGET=w3mhelp.html
HELP_ALLFILES=w3mhelp-w3m_en.html w3mhelp-w3m_ja.html \
	w3mhelp-lynx_en.html w3mhelp-lynx_ja.html

DEFUNS=$(top_srcdir)/main.c $(top_srcdir)/menu.c
SCRIPTSUBDIRS= scripts
SUBDIRS = $(SCRIPTSUBDIRS) w3mimg libwc po
.PHONY: $(SUBDIRS)

$(IMGDISPLAY): w3mimgdisplay.o $(ALIB) w3mimg/w3mimg.a
	$(IMGLINK) $(CFLAGS) -o $(IMGDISPLAY) w3mimgdisplay.o w3mimg/w3mimg.a $(LDFLAGS) $(LIBS) $(IMGLDFLAGS) -lX11

w3mimgdisplay.o: w3mimgdisplay.c w3mimg/w3mimg.h
	$(CC) $(CFLAGS) $(IMGCFLAGS) -o $@ -c $(srcdir)/w3mimgdisplay.c

w3mimg/w3mimg.a: w3mimg
w3mimg:
	(cd w3mimg && $(MAKE) CC="$(CC0)" OPTS="$(OPTS)")
