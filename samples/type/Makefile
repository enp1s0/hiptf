HIPPATH=/opt/rocm/hip
HIPCC=$(HIPPATH)/bin/hipcc
HIP_INC=$(HIPPATH)/include
HIP_LIB=$(HIPPATH)/lib
HIPFLAGS=-std=c++11 -I$(HIP_INC) -L$(HIP_LIB) -I../../
TARGETS=type.test

all: $(TARGETS)

%.test: %.cpp
	$(HIPCC) $(HIPFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)
