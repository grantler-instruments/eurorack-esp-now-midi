# eurorack-esp-now-midi

A eurorack module that receives MIDI messages via ESP-NOW.

This module works with the ESP-NOW MIDI library. It functions solely as a receiver, but the exciting part is that you can create your own senders—they just need to utilize the ESP-NOW MIDI library.

check out the sender example here: https://github.com/thomasgeissl/esp-now-midi.
## usage
* upload firmware: `pio run -t upload`