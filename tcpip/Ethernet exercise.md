**Exercise 1: Ethernet Frame Parser**

**Objective**
Learn how to read and parse an Ethernet frame by working directly with its raw hexadecimal data.

**Background**

Ethernet frames contain crucial information such as source and destination MAC addresses and EtherType. Understanding how to extract and interpret these fields is fundamental to networking.

**Task**
You are given a raw Ethernet frame hex dump.

Write a C++ program that:

1. Extracts and prints the **Destination MAC address**

2. Extracts and prints the **Source MAC address**

3. Extracts and prints the **EtherType**

**Hex Dump**
The following hex dump is already provided in the starter C++ file:

```
ff ff ff ff ff ff 00 0c 29 3e 5b c4 08 00 45 00
00 3c 1c 46 40 00 40 06 b1 e6 c0 a8 00 68 c0 a8
00 01
```

**Expected Output Example**

```
Destination MAC: ff:ff:ff:ff:ff:ff
Source MAC: 00:0c:29:3e:5b:c4
EtherType: 0x0800
```

**Optional Challenge**
Print the **payload** of the Ethernet frame (everything after the EtherType) as hexadecimal values.

**Resources**
You can complete this exercise in:

• **Local environment** (Linux, Mac, Windows) using a compiler like g++

• **Online C++ environments**:

• [Replit](https://replit.com/)

• [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
