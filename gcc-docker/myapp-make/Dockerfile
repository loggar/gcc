FROM gcc:4.9
COPY . /usr/src/myapp-make
WORKDIR /usr/src/myapp-make
RUN make
CMD [ "./hider_msg" ]
