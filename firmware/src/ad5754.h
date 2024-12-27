#ifndef AD5754_H
#define AD5754_H

#include <Arduino.h>
#include <SPI.h>

class AD5754 {
public:
    // Constructor: specify the SPI CS pin
    AD5754(uint8_t csPin) : csPin(csPin) {}

    // Initialize the SPI and DAC
    void begin() {
        pinMode(csPin, OUTPUT);
        digitalWrite(csPin, HIGH); // Ensure CS is high

        SPI.begin();
        SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE2)); // Configure SPI settings

        // Initialize the DAC (reset or any startup configuration can go here)
        sendCommand(0x28, 0x0000); // Example: Power Control Register (Enable all channels)
    }

    // Set a specific channel to a voltage
    // channel: 0-3 (corresponding to DAC A, B, C, D)
    // voltage: Desired voltage in volts (e.g., 0.0 to 10.0)
    void setVoltage(uint8_t channel, float voltage) {
        if (channel > 3 || voltage < 0.0 || voltage > 10.0) {
            return; // Invalid channel or voltage range
        }

        // Calculate the 12-bit value based on the voltage
        uint16_t dacValue = (uint16_t)((voltage / 10.0) * 4095);

        // Construct the 24-bit command
        uint8_t command = 0x30 | (channel & 0x03); // 0x30 is the "Write to DAC" command base
        uint16_t data = (dacValue & 0xFFF);       // 12-bit data value

        sendCommand(command, data);
    }

void setGate(uint8_t channel, bool state) {
    setVoltage(channel, state ? 5.0 : 0.0);
}

private:
    uint8_t csPin;

    // Send a 24-bit command to the DAC
    void sendCommand(uint8_t command, uint16_t data) {
        digitalWrite(csPin, LOW);

        // Send the command and data
        SPI.transfer(command);
        SPI.transfer((data >> 8) & 0xFF); // Upper 8 bits
        SPI.transfer(data & 0xFF);        // Lower 8 bits

        digitalWrite(csPin, HIGH);
    }
};

#endif
