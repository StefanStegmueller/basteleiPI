FROM resin/rpi-raspbian:jessie

ENV INITSYSTEM on

RUN rm /bin/sh && ln -s /bin/bash /bin/sh
RUN apt-get -y update && apt-get install -y \
git-core \
build-essential \
python-dev \
python-pip \
libcurl3 \
libcurl3-gnutls
RUN pip install pyserial
RUN git clone git://git.drogon.net/wiringPi
RUN cd wiringPi && ./build
RUN git clone https://github.com/miloyip/rapidjson.git
RUN cp -a /rapidjson/include/rapidjson /usr/local/include

COPY . /usr/src/app
WORKDIR /usr/src/app/basteleiPI/basteleiPI/Debug

RUN make all

CMD ./basteleiPI pn8TPhSpIiD2qlF1XS4IXPcnmMivSpwslhVR9yHhpHqeX8Dray2hdawXlS0bTZ 60
