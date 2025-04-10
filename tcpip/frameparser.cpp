// Ethernet Frame Parser Exercise (Stub)
#include <iostream>
#include <iomanip>
#include <cstdint>

// TODO: Implement this function to print a MAC address
void print_mac(const uint8_t* mac) {
    // Example output: ff:ff:ff:ff:ff:ff
}

// TODO: Implement this function to parse EtherType
uint16_t parse_ethertype(const uint8_t* frame) {
    return 0;
}

int main() {
    // Ethernet frame hex dump
    uint8_t frame[] = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x0c, 0x29, 0x3e, 0x5b, 0xc4,
        0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x1c, 0x46, 0x40, 0x00, 0x40, 0x06,
        0xb1, 0xe6, 0xc0, 0xa8, 0x00, 0x68, 0xc0, 0xa8, 0x00, 0x01
    };

    // TODO: Print Destination MAC address

    // TODO: Print Source MAC address

    // TODO: Parse and print EtherType

    // TODO (Optional): Print Payload

    return 0;
}