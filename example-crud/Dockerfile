FROM alpine:latest

RUN apk update && apk upgrade

RUN apk add g++

RUN apk add git
RUN apk add make
RUN apk add cmake

COPY . /service

WORKDIR /service/utility


RUN ls /service/utility/tmp
RUN cat /service/utility/modules.sh
RUN /service/utility/modules.sh

WORKDIR /service/build

RUN cmake ..
RUN make

EXPOSE 8000 8000

ENTRYPOINT ["./crud-exe"]
