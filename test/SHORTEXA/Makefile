CFLAGS += -std=c11 -fPIE -g -O3 -fstack-protector-all -D_FORTIFY_SOURCE=2 -DREENTRANT -I../../src -L../../lib
LDFLAGS += -lm -lspacelib

OBJECTS := CARDAH CARDAM CARDA_OM CARDA-OM CARDAW CARDG CARDOPTO E_dhtom E_DYN_EQ EXTRACT FRAME4P FRAME4V FRAMEP FRAMEV GTOM INTERSLP JTOJ MAKEL0 MAKEL MAKEL_P MTOSCREW PROJPONL ROTAT RTOCARDA SCREWTOM TRASF_MA TRASF_MH TR_MAMT VELWH2 WTOL_P WTOL_R WTOVEL WTOVEL_P

.PHONY: all clean distclean

all : $(OBJECTS)

$(OBJECTS): %: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) -o $@ $<

clean:
	@- $(RM) $(OBJECTS)

distclean: clean