# I/O Software Layer Scheme Layers for each Task

## i - controlling of a user's access permissions to a given block of information

The responsible layer is the Device-independent Software layer.

## ii - calculation of the track, sector and head of a magnetic disk that would correspond to the reading of a given block of information

The responsible layer is the Hardware Layer.

## iii - writing of commands to a device controller's registers

The responsible layer is the Device Drivers Layer.

## iv - maintaining a cache with the recently accessed blocks of information

The responsible layer is the Device-independent Software layer.

## v - converting binary integers to ASCII characters so that they can be printed

The responsible layer is User Processes layer.