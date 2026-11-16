
# CPE-2600 Lab 10 - Signals

CC = gcc
CFLAGS = -Wall -lm -Wextra -std=c11 -g -D_POSIX_C_SOURCE=200809L

TARGETS = signal_handler signal_alarm signal_segfault signal_sigaction recv_signal send_signal

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean
