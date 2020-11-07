HIPPATH=/opt/rocm/hip
HIPCC=$(HIPPATH)/bin/hipcc
HIP_INC=$(HIPPATH)/include
RSMI_INC=$(HIPPATH)/../rocm_smi/include
HIP_LIB=$(HIPPATH)/lib
RSMI_LIB=$(HIPPATH)/../rocm_smi/lib
HIPFLAGS=-std=c++11 -I$(RSMI_INC) -I$(HIP_INC) -L$(RSMI_LIB) -L$(HIP_LIB) -I../../ -lrocm_smi64
TARGETS=rsmi.test

all: $(TARGETS)

%.test: %.cpp
	$(HIPCC) $(HIPFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)
