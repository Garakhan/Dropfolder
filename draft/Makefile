define _cmake
	@cd build && cmake ..
endef

define _make
	@cd build && make
endef

define _build
	@if [ ! -d build ]; then \
		mkdir build; \
	fi
	$(call _cmake)
	$(call _make)
endef

define _run
	@cd build && ./draft
endef

default:
	@$(call _make)
	@echo ---------------
	@$(call _run)

run:
	@$(call _run)

build:
	@$(call _build)
	
rbuild:
	@$(call _build)
	@$(call _run)



help:
	@echo build - cmake + make
	@echo rbuild  - cmake + make + run
	@echo run 	  - run
	@echo ~    - make + run
