FROM lizhizhou/openfpgaduino64
MAINTAINER Zhizhou Li <lzz@meteroi.com>
RUN  apt-get update && apt-get -y upgrade 
RUN rm -rf /var/lib/apt/lists/*
RUN git clone https://github.com/OpenFPGAduino/libAduino.git
RUN cd libAduino; make clean; make
