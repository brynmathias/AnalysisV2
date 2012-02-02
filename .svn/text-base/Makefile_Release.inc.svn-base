# need to determine the platform and define the appropriate:
MAKE=make

PROJECTDIR=$(SUSY_WORKING_SW_DIR)
CXX=g++

EXE_EXT=

ifndef PLATFORM
PLATFORM=linux
endif

INCDIR= \
-Iinclude

CXXFLAGS= -c -Wall -ansi -O3 -D$(PLATFORM) -D_REENTRANT -fPIC

ifeq ($(PLATFORM),"linux")
CXXFLAGS+= -pthread -D_REENTRANT
endif

DEPFLAGS= -MM -D$(PLATFORM)

ifdef NTUPLE_TYPE
CXXFLAGS+= -D$(NTUPLE_TYPE)
DEPFLAGS+= -D$(NTUPLE_TYPE)
endif

SRCDIR=src
OBJDIR=obj
LIBDIR=lib

PLATFORM_SRCDIR=$(SRCDIR)/$(PLATFORM)
COMMON_SRCDIR=$(SRCDIR)/common

PLAT_SRC=$(wildcard $(PLATFORM_SRCDIR)/*.cc)
PLAT_OBJ=$(subst $(PLATFORM_SRCDIR), $(OBJDIR),$(PLAT_SRC:.cc=.o))

COMM_SRC=$(wildcard $(COMMON_SRCDIR)/*.cc)
COMM_OBJ=$(subst $(COMMON_SRCDIR), $(OBJDIR),$(COMM_SRC:.cc=.o))

DEP_FILES=$(subst $(COMMON_SRCDIR),$(OBJDIR), $(COMM_SRC:.cc=.d))
DEP_FILES+=$(subst $(PLATFORM_SRCDIR),$(OBJDIR), $(PLAT_SRC:.cc=.d))

# link variables:

LD=g++

LIB_EXT=so

ifeq ($(PLATFORM),"Win32")
LIB_EXT=dll
endif

LINK_SEARCH=

LIBTARGET=lib$(MODULE).$(LIB_EXT)

LIBS=

LDFLAGS= -shared -o

#
# main target : library
#
$(LIBDIR)/$(LIBTARGET): $(DEP_FILES) $(PLAT_OBJ) $(COMM_OBJ)


# dependencies

$(OBJDIR)/%.d: $(COMMON_SRCDIR)/%.cc
#	@echo =============================================================
#	@echo $*
#	@echo $<
#	@echo $@.$$$$
#	@echo $+
#	@echo $%
	@echo =============================================================
	$(CXX) $(DEPFLAGS) $(INCDIR) $< > $@.temp
	sed 's,\($*\).o[ :]*,$(OBJDIR)/\1.o $@ : ,g' < $@.temp > $@
	rm -f $@.temp
	@echo =============================================================


include $(DEP_FILES)

$(OBJDIR)/%.d: $(PLATFORM_SRCDIR)/%.cc
	@echo =============================================================
	$(CXX) $(DEPFLAGS) $(INCDIR) $< -o $@
	@echo =============================================================

# build rules:

$(OBJDIR)/%.o:$(COMMON_SRCDIR)/%.cc #%(OBJ)/$*.d
	@echo =============================================================
	$(CXX) $(CXXFLAGS) $(INCDIR) $< -o $@

$(OBJDIR)/%.o:$(PLATFORM_SRCDIR)/%.cc #%(OBJ)/%.d
	@echo =============================================================
	$(CXX) $(CXXFLAGS) $(INCDIR) $< -o $@

$(LIBDIR)/$(LIBTARGET) : $(COMM_OBJ) $(PLAT_OBJ)
	@echo =============================================================
	$(LD) $(LDFLAGS) $(LIBDIR)/$(LIBTARGET) $(LINK_SEARCH) $(LIBS) $(COMM_OBJ) $(PLAT_OBJ)
	cp $(LIBDIR)/$(LIBTARGET) $(PROJECTDIR)/lib/.


# other things:

vars:
	@echo "------------------------------------"
	@echo "GCT_SC_SW_DIR= " $(GCT_SC_SW_DIR)
	@echo $(INCDIR)
	@echo "Comm. Source dir: " $(COMMON_SRCDIR)
	@echo "Plat. Source dir: " $(PLATFORM_SRCDIR)
	@echo "Comm. Object files: " $(COMM_OBJ)
	@echo "Plat. Object files: " $(PLAT_OBJ)
	@echo "Library:      " $(LIBDIR)/$(LIBTARGET)
	@echo "------------------------------------"
	@echo "platform src files: " $(PLAT_SRC)
	@echo "                ->: " $(PLAT_OBJ)
	@echo "common src files  : " $(COMM_SRC)
	@echo "                ->: " $(COMM_OBJ)
	@echo "------------------------------------"
	@echo "Dependencies : " $(DEP_FILES)
	@echo "------------------------------------"


clean:
	rm -f $(DEP_FILES) $(COMM_OBJ) $(PLAT_OBJ) $(LIBDIR)/$(LIBTARGET)
	rm -f $(OBJDIR)/*.o $(LIBDIR)/*.dll $(LIBDIR)/*.a

force:
	@$(MAKE) clean
	@$(MAKE)


tests:
	@$(MAKE) -C tests

