# eurorack-esp-now-midi

A eurorack module that receives MIDI messages via ESP-NOW.

This module works with the ESP-NOW MIDI library. It functions solely as a receiver, but the exciting part is that you can create your own senders—they just need to utilize the ESP-NOW MIDI library.
Check out the sender example here: https://github.com/thomasgeissl/esp-now-midi.

The module comes with 16 outputs, which e.g. can be used as 8 gate/cv pairs.
It can be configured to use different modes, based on the modes it sends voltages to different output channels.

## usage
* upload firmware: `pio run -t upload`