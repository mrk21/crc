.DEFAULT: all
.PHONY: all
all: lpc11xx_lib googlemock_lib bandit_lib bandit_with_gmock

.PHONY: clean
clean:
	$(RM) -r googlemock bandit bandit_with_gmock
	$(MAKE) -C CMSISv2p00_LPC11xx clean

.PHONY: rebuild
rebuild: clean all


.PHONY: lpc11xx_lib
lpc11xx_lib: CMSISv2p00_LPC11xx
	$(MAKE) -C $<

.PHONY: googlemock_lib
googlemock_lib: googlemock
	cd $< && cmake . && $(MAKE)

.PHONY: bandit_lib
bandit_lib: bandit
	cd $< && git checkout v1.0.0


googlemock:
	svn checkout http://googlemock.googlecode.com/svn/tags/release-1.6.0 $@

bandit:
	git clone https://github.com/joakimkarlsson/bandit.git $@

bandit_with_gmock:
	git clone https://github.com/mrk21/bandit_with_gmock.git $@
