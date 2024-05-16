FROM lganzzzo/alpine-cmake:latest

RUN apk add postgresql-dev

RUN apk update && apk upgrade

RUN apk add g++

RUN apk add git
RUN apk add make
RUN apk add cmake

ADD . /service

WORKDIR /service/utility

RUN ./install-oatpp-modules.sh

WORKDIR /service/build

RUN cmake ..
RUN make

EXPOSE 8000 8000

ENTRYPOINT ["./crud-exe"]
