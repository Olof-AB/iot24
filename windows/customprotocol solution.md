# Solution: Custom Protocol over UDP (Windows Version)

## Server Code

```cpp
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

uint8_t compute_checksum(const uint8_t* data, size_t length) {
    uint8_t checksum = 0;
    for (size_t i = 0; i < length; ++i) {
        checksum ^= data[i];
    }
    return checksum;
}

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET sockfd;
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(client_addr);
    uint8_t buffer[1024];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Socket creation failed" << std::endl;
        WSACleanup();
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(5002);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed" << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    std::cout << "Server listening on port 5002..." << std::endl;

    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int n = recvfrom(sockfd, (char*)buffer, sizeof(buffer), 0,
                         (struct sockaddr*)&client_addr, &addr_len);

        if (n >= 2) {
            uint8_t sequence = buffer[0];
            uint8_t received_checksum = buffer[n - 1];
            uint8_t computed_checksum = compute_checksum(buffer + 1, n - 2);

            std::cout << "Received packet: Sequence = " << (int)sequence
                      << ", Payload = '" << std::string((char*)(buffer + 1), n - 2)
                      << "', Checksum valid: "
                      << (received_checksum == computed_checksum ? "YES" : "NO")
                      << std::endl;
        }
    }

    closesocket(sockfd);
    WSACleanup();
    return 0;
}
```

## Client Code

```cpp
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
#include <chrono>

#pragma comment(lib, "ws2_32.lib")

uint8_t compute_checksum(const uint8_t* data, size_t length) {
    uint8_t checksum = 0;
    for (size_t i = 0; i < length; ++i) {
        checksum ^= data[i];
    }
    return checksum;
}

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Socket creation failed" << std::endl;
        WSACleanup();
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5002);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    uint8_t sequence = 0;

    while (true) {
        const char* payload = "Temperature: 23C";
        size_t payload_length = strlen(payload);

        uint8_t message[1024];
        message[0] = sequence;
        memcpy(message + 1, payload, payload_length);
        message[1 + payload_length] = compute_checksum((uint8_t*)payload, payload_length);

        sendto(sockfd, (char*)message, 1 + payload_length + 1, 0,
               (struct sockaddr*)&server_addr, sizeof(server_addr));

        std::cout << "Sent packet: Sequence = " << (int)sequence << std::endl;

        sequence++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    closesocket(sockfd);
    WSACleanup();
    return 0;
}
```

## Explanation

### Server

- Initializes Winsock.
- Creates a UDP socket and binds to port `5002`.
- Receives packets using `recvfrom()`.
- Extracts sequence number, payload, checksum.
- Verifies checksum using XOR calculation.
- Prints packet details and checksum validity.

### Client

- Initializes Winsock.
- Creates a UDP socket.
- Sends a packet every second:
  - Adds sequence number.
  - Includes payload.
  - Computes checksum.
- Uses `sendto()` to transmit the packet.

## Summary

This solution demonstrates how to design and implement a simple application-level protocol over UDP on Windows, including checksum verification.
