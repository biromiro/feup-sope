# Polling vs Interrupts vs DMA

## i - most of the services asked by an user program to the I/O device are very simple and can be satisfied very quickly

The best programming model would be Polling

## ii - the computer's interrupts implementation is rather slow, and a process' context change takes a lot of time

The best programming model would be Polling

## iii - most of the I/O operations of a specific device are very slow

The best programming model would be DMA

## iv - the computer's bus is very slow

The best programming model would be DMA

## v - the CPU operates much faster compared to the speed of the DMA controller

The best programming model would be Interrupts
