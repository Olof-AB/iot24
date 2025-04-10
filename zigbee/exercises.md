# Zigbee Stack

## **Exercise 1: Exploring the PHY Layer**

### Objective:

Understand the physical transmission aspects of Zigbee and how they affect IoT deployments.

### Tasks:

1. What modulation scheme does Zigbee use in the 2.4 GHz band? How does it compare to BLE and Wi-Fi?
2. List all 2.4 GHz channels used by Zigbee. What frequency corresponds to channel 15?
3. Research and explain how _RSSI_ and _LQI_ are measured in Zigbee radios. What role do they play in network performance?
4. Find at least one Zigbee-compatible hardware module (e.g., XBee, CC2530) and document its transmit power and receiver sensitivity.

## **Exercise 2: MAC Layer Behavior Analysis**

### Objective:

Investigate how Zigbee avoids collisions and manages reliable data transfer.

### Tasks:

1. Explain the CSMA-CA mechanism in Zigbee. What is a backoff exponent?
2. Describe the structure of a Zigbee MAC frame. What fields are included?
3. Compare the use of beacons in _beacon-enabled_ vs _non-beacon_ networks. In what use cases would each be preferred?
4. Research a Zigbee packet capture tool (e.g., TI Packet Sniffer, Wireshark with a CC2531) and describe how to capture MAC frames.

## **Exercise 3: Network Layer Routing and Addressing**

### Objective:

Learn how Zigbee devices form a network, assign addresses, and route messages.

### Tasks:

1. Describe the role of the Coordinator in network formation.
2. Explain the difference between a **16-bit network address** and a **64-bit IEEE address**.
3. What routing protocol is used in Zigbee? How does route discovery work?
4. Research the “depth” and “routing capacity” of a Zigbee network using a real-world mesh application (e.g., IKEA Tradfri or Philips Hue).

### Deliverable:

- Flowchart of Zigbee network joining and routing steps
- Addressing example: Show a hypothetical tree of devices with addresses assigned
- Explanation of how Zigbee handles a broken link in a mesh network

## **Exercise 4: Application Support and Binding (APS Layer)**

### Objective:

Understand how Zigbee applications discover, format, and exchange data.

### Tasks:

1. Define an **endpoint** and explain how it allows multiple logical devices on a single node.
2. What is a **cluster**? Find and describe the attributes and commands of the _On/Off_ cluster from the ZCL.
3. How does **binding** work between devices? Explain the unicast and group binding mechanisms.
4. Explore a binding scenario: Light switch and three bulbs. Explain how binding is configured and maintained.

### Deliverable:

- Diagram showing endpoints and clusters for a multi-function device (e.g., smart plug with power monitoring)
- Table of On/Off cluster attributes and commands
- Binding scenario map (with unicast/group options)

## **Exercise 5: Zigbee Device Object (ZDO) Services**

### Objective:

Investigate how Zigbee devices are discovered and managed.

### Tasks:

1. List the main services provided by ZDO (e.g., device discovery, binding, management).
2. What is the _Trust Center_ in Zigbee? How does it participate in secure joining?
3. What happens during the network joining process at the ZDO level? What messages are exchanged?
4. Find and analyze an example ZDO message format (e.g., Device_annce, Node_Desc_req).

### Deliverable:

- Table listing ZDO services and associated commands
- Diagram of network joining sequence from the ZDO perspective
- Discussion: What could go wrong during joining? Suggest mitigation strategies.

## **Exercise 6: Application Profiles and Interoperability**

### Objective:

Explore how Zigbee ensures standardized behavior between devices from different manufacturers.

### Tasks:

1. What is the Zigbee Cluster Library (ZCL)? What are functional clusters?
2. Choose one Zigbee Application Profile (e.g., Home Automation, Smart Energy). List:
   - Three device types
   - The clusters they support
   - What attributes/commands they implement
3. Describe how profiles ensure interoperability across different vendors (e.g., Philips Hue and IKEA).
4. What is Zigbee 3.0 and how does it unify previous profiles?

### Deliverable:

- Profile summary sheet
- Table mapping devices → endpoints → clusters
- Example use case: describe how two devices interact using clusters (e.g., Motion sensor → light bulb)

## Final Integration Challenge (Optional Bonus)

### Scenario:

Design a Zigbee network for a smart office with:

- 5 light bulbs
- 3 smart plugs
- 2 motion sensors
- 1 temperature sensor
- 1 coordinator

### Deliverable:

- Draw the topology (star/tree/mesh)
- Assign roles and addresses
- List clusters used and how devices are bound
- Identify at least one security concern and mitigation
