FROM resin/rpi-raspbian:jessie

ENV INITSYSTEM on

RUN rm /bin/sh && ln -s /bin/bash /bin/sh
RUN apt-get -y update && apt-get install -y \
git-core \
build-essential \
python-dev \
python-pip \
libcurl3 \
libcurl3-gnutls \
curl \
libcurl4-openssl-dev \
libi2c-dev

RUN pip install pyserial
RUN git clone git://git.drogon.net/wiringPi
RUN cd wiringPi && ./build
RUN git clone https://github.com/miloyip/rapidjson.git
RUN cp -a /rapidjson/include/rapidjson /usr/local/include

COPY . /app
WORKDIR /app/basteleiPI/Debug

RUN make all

CMD modprobe i2c-dev && chmod +x runApp.sh && ./runApp.sh
