# Solution: Ethernet Frame Parser

## Overview
This solution demonstrates how to parse an Ethernet frame and extract key fields like Destination MAC, Source MAC, and EtherType using C++.

---

## Solution Code
```cpp
#include <iostream>
#include <iomanip>
#include <cstdint>

void print_mac(const uint8_t* mac) {
    for (int i = 0; i < 6; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)mac[i];
        if (i != 5) std::cout << ":";
    }
    std::cout << std::dec << std::endl;
}

uint16_t parse_ethertype(const uint8_t* frame) {
    return (frame[12] << 8) | frame[13];
}

int main() {
    uint8_t frame[] = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x0c, 0x29, 0x3e, 0x5b, 0xc4,
        0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x1c, 0x46, 0x40, 0x00, 0x40, 0x06,
        0xb1, 0xe6, 0xc0, 0xa8, 0x00, 0x68, 0xc0, 0xa8, 0x00, 0x01
    };

    std::cout << "Destination MAC: ";
    print_mac(frame);

    std::cout << "Source MAC: ";
    print_mac(frame + 6);

    uint16_t ethertype = parse_ethertype(frame);
    std::cout << "Ethertype: 0x" << std::hex << ethertype << std::dec << std::endl;

    std::cout << "Payload: ";
    for (size_t i = 14; i < sizeof(frame); ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)frame[i] << " ";
    }
    std::cout << std::dec << std::endl;

    return 0;
}
```

---

## Explanation

### Includes
- `#include <iostream>`: Allows printing
- `#include <iomanip>`: Provides formatting functions.
- `#include <cstdint>`: Fixed-size integer types (`uint8_t`, `uint16_t`).

### `print_mac()` Function
Prints a MAC address in standard format:
- Loops over 6 bytes
- Prints them in hex with leading zeroes and colons in between

### `parse_ethertype()` Function
Combines two bytes into a 16-bit integer:
```cpp
(frame[12] << 8) | frame[13]
```

**Why?**
EtherType is stored in **Big Endian (Network Byte Order)**:
| Byte | Value |
|:----:|:-----:|
| 12   | 0x08  |
| 13   | 0x00  |

You need to shift the first byte left 8 bits and OR with the second byte.

### `main()` Function
- Defines an array `frame[]` with raw Ethernet frame data.
- Prints Destination and Source MAC addresses.
- Parses and prints EtherType.
- Loops over payload and prints in hex.

---

## About Endianness
**Endianness** defines byte order in multi-byte numbers:

| Type         | Description                             |
|-------------|-----------------------------------------|
| Big Endian | Most Significant Byte first (Network)   |
| Little Endian | Least Significant Byte first          |

**Ethernet frames always use Big Endian (Network Byte Order)**.

That’s why you need:
```cpp
(frame[12] << 8) | frame[13]
```

To reconstruct the 16-bit EtherType field correctly.

If your CPU is Little Endian (like Intel), this step is necessary to avoid getting the wrong value.
