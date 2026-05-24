# Computer Networks — Complete Notes

---

# UNIT 1 — Computer Networks and the Internet

---

## 1.1 Introduction to Computer Networks

A **computer network** is two or more devices connected together so they can communicate, share data, or share resources.

The **Internet** is a massive, global network of networks — it interconnects billions of computing devices worldwide. These include:
- Traditional devices: PCs, workstations, servers
- Modern "things": laptops, phones, TVs, gaming consoles, home appliances, cars, watches, traffic systems — collectively called **IoT (Internet of Things)**

Every device connected to the Internet is called a **host** or **end system**. End systems run application programs at the Internet's "edge."

---

## 1.2 Internet: A Nuts-and-Bolts Description

The Internet has three main physical components:

### Hosts / End Systems
- Billions of connected computing devices
- Run network applications at the Internet's edge

### Packet Switches
- Forward packets (chunks of data) from one link to another
- Two main types: **routers** (network core) and **link-layer switches** (access networks)

### Communication Links
- Made of fiber, copper, radio, or satellite
- Each link has a **transmission rate**, measured in bits per second (bps), called **bandwidth**

### Networks
- A collection of devices, routers, and links managed by a single organization (e.g., a company's internal network, a university network)

### Internet Standards
- **RFC (Request for Comments)**: documents that define Internet standards
- **IETF (Internet Engineering Task Force)**: the organization that produces RFCs

**Protocols are everywhere** — they control all sending and receiving of messages. Examples: HTTP, TCP, IP, WiFi, 4G/5G, Ethernet.

---

## 1.3 Internet: A Services Description

From a services viewpoint, the Internet is an **infrastructure that provides services to applications**:
- Web browsing, streaming video, email, games, e-commerce, social media, VoIP

The Internet provides two types of service to applications:
1. **Reliable data delivery** (TCP) — guaranteed, in-order
2. **Best-effort delivery** (UDP) — no guarantee

Applications access these services through a **programming interface (socket API)** — a set of hooks that allow apps to "connect" to the Internet transport service, similar to how you'd use a postal service.

---

## 1.4 What is a Protocol?

A **protocol** defines:
- The **format** of messages exchanged
- The **order** of messages sent and received
- The **actions** taken on message transmission and receipt

**Human analogy**: When you ask "what time is it?" and someone replies "2:00" — that's a protocol. Both parties know the format (question → answer) and the action (answer the question).

**Network protocol**: Computers exchange messages in a predefined format and take predefined actions. For example:
- Client sends TCP connection request → Server responds with TCP connection response → Client sends HTTP GET → Server replies with file

All activity on the Internet is governed by protocols.

---

## 1.5 The Network Edge: Access Networks

The **network edge** refers to end systems (hosts) and the access networks connecting them to the Internet's first router (called the **edge router**).

### Types of Access Networks

#### Digital Subscriber Line (DSL)
- Uses the **existing telephone line** to the central office
- A **DSLAM** (DSL Access Multiplexer) at the central office separates voice and data
- Asymmetric: downstream is faster than upstream
- Downstream: 24–52 Mbps; Upstream: 3.5–16 Mbps
- Voice, data, and control are on **different frequency bands** simultaneously

#### Cable-Based Access
- Uses **existing cable TV infrastructure** (coaxial cable + fiber — called **HFC: Hybrid Fiber Coax**)
- **FDM (Frequency Division Multiplexing)**: different channels on different frequency bands simultaneously
- A **CMTS** (Cable Modem Termination System) is at the cable headend
- **Shared** access — all homes in a neighborhood share the downstream channel
- Asymmetric: downstream up to 1.2 Gbps; upstream 30–100 Mbps

#### Home Network
- A cable or DSL modem connects to a home **router/NAT/firewall box**
- From the router: wired Ethernet (1 Gbps) and WiFi wireless (54–450+ Mbps) to devices

#### Enterprise Networks
- Used in companies and universities
- Mix of **wired Ethernet** (100 Mbps, 1 Gbps, 10 Gbps) and **WiFi** (802.11 b/g/n/ac)
- Connects via institutional router to the ISP (Internet)

#### Wireless Access Networks
- **WLAN (Wireless Local Area Network)**: typically within a building (~30 m)
  - 802.11 b/g/n (WiFi): 11 Mbps → 54 Mbps → 450+ Mbps
- **Wide-area cellular**: provided by mobile operators (km-scale coverage)
  - 4G/5G: tens of Mbps

---

## 1.6 Physical Media

Physical media is what lies between a transmitter and receiver.

**Bit**: propagates between transmitter/receiver pairs

Two categories:
- **Guided media**: signals travel along a solid medium (copper wire, fiber optic, coax)
- **Unguided media**: signals propagate freely (radio waves)

### Twisted Pair (TP)
- Two insulated copper wires twisted together
- **STP** (Shielded) and **UTP** (Unshielded)
- **Category 5**: 100 Mbps or 1 Gbps Ethernet
- **Category 6**: 10 Gbps Ethernet
- Most common — used in office buildings and homes

### Coaxial Cable
- Two **concentric** copper conductors (not parallel)
- Bidirectional, broadband
- Multiple frequency channels, each carrying 100s of Mbps
- Used in cable TV systems

### Fiber Optic Cable
- Carries light pulses, each pulse = 1 bit
- **High speed**: 10s–100s of Gbps point-to-point
- **Low error rate**: immune to electromagnetic interference
- Repeaters spaced far apart
- Used in long-distance and high-capacity links (ISP backbone, transocean links)

### Wireless Radio
- Signals travel through the **electromagnetic spectrum** — no physical wire
- Broadcast medium; "half-duplex" by default (one direction at a time)
- Environmental effects: reflection, obstruction, interference

Types:
- **Terrestrial microwave**: up to 45 Mbps
- **Wireless LAN (WiFi)**: up to 100s of Mbps
- **Wide-area cellular (4G)**: ~tens of Mbps
- **Satellite**: up to 45 Mbps per channel, but ~280 ms end-to-end delay (geostationary); low-earth-orbit satellites (LEO) have much lower delay

### Half-duplex vs. Full-duplex
- **Half-duplex**: data can only go one direction at a time (takes turns on a single channel)
- **Full-duplex**: data can go both directions simultaneously (two separate channels)

---

## 1.7 Introduction to Physical Layer Devices

These are network hardware devices — each operates at a specific OSI layer.

### Repeater (Physical Layer)
- **Problem it solves**: signals weaken over distance (attenuation)
- Receives an incoming signal, **regenerates** and **amplifies** it, then retransmits it
- Does NOT interpret the data — just regenerates the signal
- Extends the range of a network segment

### Hub (Physical Layer)
- Connects multiple devices on a LAN
- **Broadcasts** incoming data to ALL connected ports — no intelligence
- **Single collision domain**: only one device can talk at a time (half-duplex)
- Cannot store MAC addresses, no filtering
- Suitable for small networks; largely replaced by switches

### Modem (Physical Layer)
- **Modulator-Demodulator**: converts digital signals to analog (for transmission over phone lines) and back
- Sending side: **modulation** (digital → analog)
- Receiving side: **demodulation** (analog → digital)

### Bridge (Data Link Layer)
- Connects two or more network segments
- Reads **MAC addresses** to decide which segment to forward traffic to
- Functions: segmentation (divides network), filtering (reduces congestion), learning (tracks MAC-to-port mappings), forwarding

### Switch (Data Link Layer)
- An **intelligent multiport bridge**
- Reads MAC addresses and forwards frames only to the correct destination port
- **Multiple collision domains** (one per port) — devices don't compete
- **Full-duplex** capable
- Stores MAC address table; filters traffic; reduces collisions
- Suitable for larger, complex networks

**Hub vs Switch comparison**:
| Feature | Hub | Switch |
|---|---|---|
| Layer | Physical | Data Link |
| Data handling | Broadcasts to all | Forwards to specific port |
| Collision domain | One shared | One per port |
| Intelligence | None | Stores MAC table |
| Performance | Lower (collisions) | Higher |

### NIC — Network Interface Card (Data Link Layer)
- Physical card or chip in every device
- Contains a **unique 48-bit MAC address** (burned in ROM)
- Handles data transmission and reception, data conversion, error detection
- Connects device to network (wired or wireless)

### Router (Network Layer)
- Forwards data packets based on **IP addresses**
- Maintains a **routing table** — updated dynamically by routing algorithms
- Functions: Forwarding (move packet to output port), Routing (determine best path), NAT

### Gateway (Any Layer)
- Connects two **different-type** networks (different protocols, configurations)
- Acts as a **protocol converter**
- Types: Unidirectional (one-way replication), Bidirectional (synchronization)

### Firewall (Transport / Application Layer)
- Monitors incoming and outgoing traffic
- Allows or blocks traffic based on predefined **security rules**
- Protects the network from unauthorized access

---

## 1.8 The Network Core

The **network core** is the mesh of interconnected packet switches (routers and switches) that form the Internet's backbone.

Core function: move data from source to destination.

Two fundamental functions in every router:
- **Forwarding** (data plane): local action — move arriving packet from input link to the correct output link using a forwarding table
- **Routing** (control plane): global action — determine the end-to-end path; routing algorithms compute the forwarding tables

---

## 1.9 Packet Switching

In packet switching, hosts break messages into **packets** and send them independently through the network.

### Store-and-Forward Transmission
- A router must **receive the entire packet** before it can begin transmitting it to the next link
- This is called "store-and-forward"
- Transmission delay for one hop = L/R (L = packet length in bits, R = link rate in bps)

### Queuing Delay and Packet Loss
- Each router has an **output buffer (queue)**
- If packets arrive faster than the link can transmit them, they wait in the queue → **queuing delay**
- If the buffer is full and a new packet arrives → the packet is **dropped (lost)**
- Lost packets may be retransmitted by the source, or not at all

### Forwarding Table
- Each router has a forwarding table: maps destination IP address (or prefix) → output link
- Routers use this table to decide where to send each packet

### Packet Switching vs. Circuit Switching
| Feature | Packet Switching | Circuit Switching |
|---|---|---|
| Connection | Connectionless | Connection-oriented |
| Resources | Shared (on-demand) | Dedicated (reserved) |
| Designed for | Data (bursty) | Voice (continuous) |
| Flexibility | Flexible | Inflexible |
| Order | Out-of-order possible | In-order |
| Multiplexing | Statistical (packet-by-packet) | FDM or TDM |
| Layer | Network layer | Physical layer |
| Bandwidth | Dynamic (no waste when idle) | Fixed (wasted when idle) |
| Delay type | Transmission delay | Call setup delay |

**Why packet switching wins for data**: Most data traffic is **bursty** — devices are not continuously sending. Packet switching lets many users share the link when others are idle. This is called **statistical multiplexing**.

---

## 1.10 Circuit Switching

In circuit switching, a **dedicated end-to-end path** is established before communication begins (like a traditional phone call).

- Resources (bandwidth) are **reserved** for the entire duration of the call
- The reserved capacity sits idle if no data is being sent — **wasteful**
- Guarantees a constant rate — good for voice/real-time applications

### Multiplexing in Circuit-Switched Networks

**FDM (Frequency Division Multiplexing)**:
- The entire link bandwidth is divided into **frequency bands**
- Each call is allocated one band and can use it the whole time
- Simultaneous transmission, but each user gets a narrow band

**TDM (Time Division Multiplexing)**:
- Time is divided into **frames**, and each frame is divided into **slots**
- Each call is allocated a periodic time slot
- Users take turns, but can use the full bandwidth during their slot
- Like a rotating "turn" system

---

## 1.11 A Network of Networks

End systems connect to the Internet through **access ISPs** (Internet Service Providers) — residential, company, or university ISPs.

These ISPs must be interconnected so any two hosts can communicate. This evolved over time:

- **Structure 1**: All access ISPs connect to a single global ISP
- **Structure 2**: Multiple competing global ISPs → need peering links
- **Structure 3**: IXPs (Internet Exchange Points) allow ISPs to directly interconnect — more efficient and cheaper
- **Structure 4**: Regional ISPs connect access ISPs to global ISPs
- **Structure 5**: Content provider networks (Google, Facebook) run their own private networks to bring content close to end users, often bypassing tier-1 ISPs

### Final Internet Structure
- **Tier-1 ISPs** (e.g., AT&T, Sprint, NTT): national/international coverage, connect to each other directly
- **Regional ISPs**: connect to one or more Tier-1 ISPs
- **Access ISPs**: connect end users to the Internet
- **IXPs**: neutral facilities where ISPs exchange traffic
- **Content provider networks**: Google, Facebook, etc. operate their own global backbones

---

## 1.12 Delay, Loss, and Throughput in Packet-Switched Networks

### Four Types of Delay at Each Router

Total **nodal delay** = dproc + dqueue + dtrans + dprop

#### 1. Processing Delay (dproc)
- Time for router to examine the packet header, check for bit errors, and determine which output link to use
- Typically **microseconds or less**

#### 2. Queuing Delay (dqueue)
- Time the packet waits in the output buffer before being transmitted
- Depends on **congestion** at the router — varies from zero to milliseconds
- If traffic intensity **La/R ≈ 0**: tiny delay; if **La/R → 1**: delay grows large; if **La/R > 1**: infinite average delay (more arrives than can leave)
- **La/R** is called **traffic intensity** (L = packet length, a = average arrival rate, R = link rate)

#### 3. Transmission Delay (dtrans)
- Time to push all bits of the packet onto the link
- **dtrans = L / R** (L = packet length in bits, R = link transmission rate in bps)
- Nothing to do with distance
- Example: 1000-bit packet on a 1 Mbps link → 1 ms

#### 4. Propagation Delay (dprop)
- Time for a bit to travel from one router to the next
- **dprop = d / s** (d = distance of the link, s = propagation speed ≈ 2×10⁸ m/s in copper, nearly 3×10⁸ in fiber/air)
- Depends only on **distance**, not packet size or link speed

### Transmission Delay vs. Propagation Delay — Key Distinction
| | Transmission Delay | Propagation Delay |
|---|---|---|
| What it is | Time to push bits onto the link | Time for bit to travel across the link |
| Depends on | Packet length (L) and link rate (R) | Distance (d) and medium speed (s) |
| Formula | L/R | d/s |
| Independent of | Distance | Packet length, link rate |

### Queuing Delay Revisited
- Queuing delay is the most **interesting and variable** of the four
- Can vary packet-to-packet
- Governed by traffic intensity La/R
- Design principle: keep La/R ≤ 1 (and preferably much less)

### Traceroute
- A diagnostic tool that measures delay from source to each router along the path
- Sends 3 probes to each hop; each probe gets a response from that router
- Shows RTT to each hop, revealing where delays are high
- Some routers don't respond → shown as `* * *`

### Packet Loss
- Each router has a **finite buffer**
- When buffer is full, arriving packets are **dropped**
- Lost packets may be retransmitted by the previous node, source, or not at all
- Loss probability increases with traffic intensity

---

## 1.13 End-to-End Delay

The **end-to-end delay** is the total time from source sending the first bit to the destination receiving the last bit of a packet.

For N links (N−1 routers between source and destination):
- End-to-end delay = sum of all individual link delays (transmission + propagation at each hop)
- Ignoring queuing and processing: N × (dtrans + dprop) if all links are identical

In practice, each link has different rate and length, so you compute each hop's delay separately and sum them.

---

## 1.14 Throughput in Computer Networks

**Throughput**: the rate (bits per unit time) at which bits are transferred from sender to receiver.

- **Instantaneous throughput**: rate at a given instant
- **Average throughput**: rate over a longer period (F bits / T seconds)

### Bottleneck Link
- The link on the end-to-end path that **limits** the throughput
- Throughput = **min(Rs, Rc)** where Rs = server link rate, Rc = client link rate
- If Rs < Rc: server is the bottleneck
- If Rc < Rs: client is the bottleneck
- In a network with shared backbone: throughput may also be constrained by shared link capacity / number of flows using it

---

## 1.15 The OSI Model and the TCP/IP Protocol Suite

### Why Layering?
- Networks are complex systems with many components
- Layering provides **modularity**: each layer has a well-defined role, implemented independently
- Changes in one layer don't affect others
- Easier to maintain, update, and debug

### Internet Protocol Stack (TCP/IP — 5 Layers)

| Layer | Name | Function | Unit | Protocols |
|---|---|---|---|---|
| 5 | Application | Network application support | Message | HTTP, SMTP, DNS, FTP |
| 4 | Transport | Process-to-process delivery | Segment | TCP, UDP |
| 3 | Network | Host-to-host routing | Datagram | IP, routing protocols |
| 2 | Link | Node-to-node frame delivery | Frame | Ethernet, WiFi (802.11) |
| 1 | Physical | Bits on the wire | Bit | Cables, radio |

Each layer uses the services of the layer below and provides services to the layer above.

### The OSI Model (7 Layers)

The OSI (Open Systems Interconnection) model adds two layers between Application and Transport:

| Layer | Name | Function |
|---|---|---|
| 7 | Application | Network applications |
| 6 | Presentation | Data format translation, encryption, compression |
| 5 | Session | Session setup, synchronization, checkpointing |
| 4 | Transport | End-to-end delivery |
| 3 | Network | Routing |
| 2 | Data Link | Frame delivery |
| 1 | Physical | Bits on medium |

**Presentation layer**: handles data format issues like encryption, compression, and machine-specific encoding differences.

**Session layer**: manages synchronization, checkpointing, and recovery of data exchange.

**Why TCP/IP doesn't have these layers**: If needed, these services are implemented inside the application itself.

### OSI layer groupings:
- **Network support layers**: Physical, Data Link, Network (move data from A to B)
- **Heart**: Transport (end-to-end delivery between processes)
- **User support layers**: Session, Presentation, Application (support the application)

### Encapsulation and Decapsulation

At each layer on the **sender** side, a **header** (and sometimes a trailer) is added to the data:
- Application creates a **message (M)**
- Transport adds header → **segment (Ht | M)**
- Network adds header → **datagram (Hn | Ht | M)**
- Link adds header → **frame (Hl | Hn | Ht | M)**
- Physical transmits as **bits**

At the **receiver**, each layer strips its header and passes the rest up.

**Routers** only process up to the Network layer (they read IP headers).
**Link-layer switches** only process up to the Link layer (they read MAC headers).

---

---

# UNIT 1 (Part 2) + UNIT 2 (Part 1) — Application Layer

---

## 2.1 Principles of Network Applications

### Network Application Architectures

#### Client-Server Architecture
- **Server**: always-on host with a permanent IP address, often in data centers
- **Client**: contacts and communicates with the server, may be intermittently connected, may have a dynamic IP, clients do NOT directly communicate with each other
- Examples: HTTP (web), IMAP (email), FTP (file transfer)

#### Peer-to-Peer (P2P) Architecture
- **No always-on server**
- Arbitrary end systems (peers) communicate directly with each other
- Peers request service from other peers AND provide service in return
- **Self-scalability**: new peers bring new service capacity as well as new demand
- Peers are intermittently connected and change IP addresses → complex management
- Example: BitTorrent

### Processes Communicating

A **process** is a program running within a host.

- Within the same host: two processes communicate via **inter-process communication** (defined by the OS)
- Across different hosts: processes communicate by exchanging **messages** over the network

**Client process**: the process that initiates communication
**Server process**: the process that waits to be contacted

Note: In P2P applications, both client and server processes exist on the same peer.

### Sockets

A **socket** is the interface between a process and the network — it's the "door" through which a process sends and receives messages.

- The application developer controls the application-layer side of the socket
- The OS controls the transport-layer side
- Two sockets are involved in communication: one on each side

### Addressing Processes

To receive messages, a process must have an **identifier** consisting of:
1. **IP address** (32-bit): identifies the host
2. **Port number**: identifies the specific process on that host (since many processes may run on the same host)

Common port numbers:
- HTTP server: **80**
- HTTPS: **443**
- Mail server (SMTP): **25**
- DNS: **53**

### What an Application-Layer Protocol Defines
- **Types of messages** exchanged (request, response)
- **Message syntax**: what fields exist and how they are delimited
- **Message semantics**: the meaning of the fields
- **Rules**: when and how to send and respond to messages

**Open protocols**: defined in RFCs, publicly accessible → interoperability (e.g., HTTP, SMTP)
**Proprietary protocols**: privately controlled (e.g., Skype)

---

## 2.2 Transport Services Available to Applications

Applications need the transport layer to provide certain services. Four dimensions:

### 1. Data Integrity
- Some apps (file transfer, web) require **100% reliable** delivery — no data loss
- Others (audio streaming) can tolerate some loss

### 2. Timing
- Some apps (Internet telephony, games) require **low delay** to be effective
- Others are delay-tolerant

### 3. Throughput
- Some apps (multimedia) require a **minimum throughput** to function ("bandwidth-sensitive apps")
- Others ("elastic apps") use whatever throughput is available

### 4. Security
- Encryption, data integrity, authentication

### Transport Service Requirements for Common Apps (Table)

| Application | Data Loss | Throughput | Time Sensitive |
|---|---|---|---|
| File transfer | No loss | Elastic | No |
| Email | No loss | Elastic | No |
| Web documents | No loss | Elastic | No |
| Real-time audio/video | Loss-tolerant | 5 Kbps – 5 Mbps | Yes (10s msec) |
| Streaming audio/video | Loss-tolerant | Same as above | Yes (few secs) |
| Interactive games | Loss-tolerant | Kbps+ | Yes (10s msec) |
| Text messaging | No loss | Elastic | Yes and no |

---

## 2.3 Transport Services Provided by the Internet

### TCP (Transmission Control Protocol)
- **Reliable transport**: guarantees all data arrives correctly and in order
- **Flow control**: sender won't overwhelm receiver's buffer
- **Congestion control**: throttles sender when the network is congested
- **Connection-oriented**: requires a handshake (setup) before data transfer
- Does NOT provide: timing guarantees, minimum throughput guarantees, security (by default)

### UDP (User Datagram Protocol)
- **Unreliable data transfer**: no guarantee of delivery or ordering
- **Connectionless**: no setup
- Does NOT provide: reliability, flow control, congestion control, timing, throughput, security
- Lightweight — useful when speed matters more than reliability (DNS, streaming, gaming)

### Which Protocol Does Each App Use?

| Application | Protocol | Transport |
|---|---|---|
| File transfer | FTP | TCP |
| Email | SMTP | TCP |
| Web | HTTP | TCP |
| Internet telephony | SIP, RTP | TCP or UDP |
| Streaming video | DASH | TCP |
| Interactive games | WoW, FPS | UDP or TCP |

---

## 2.4 The Web: HTTP and HTTPS

### Web Basics
- A **web page** consists of **objects** — HTML files, JPEG images, applets, audio files, etc.
- A web page has a **base HTML file** that references other objects by URL
- **URL format**: `host name / path name` (e.g., `www.example.com/dept/pic.gif`)
- If a web page has 1 HTML file + 5 JPEG images → it has **6 objects**

### HTTP Overview
- **HTTP (HyperText Transfer Protocol)**: the Web's application-layer protocol
- Uses **client/server** model:
  - Client (browser): sends requests, receives and displays objects
  - Server: sends objects in response to requests
- HTTP uses **TCP** (client connects to server on port **80**)
- HTTP is **stateless**: the server maintains no information about past client requests

### Non-Persistent HTTP
- TCP connection is opened, **at most one object** is sent, then the connection is closed
- Downloading a web page with 10 images requires **11 TCP connections** (1 for HTML + 10 for images)
- Response time per object: **2 RTT + file transmission time**
  - 1 RTT to initiate TCP connection
  - 1 RTT for HTTP request and response
  - + file transmission time
- **RTT (Round-Trip Time)**: time for a small packet to travel from client to server and back

**Drawbacks**: requires 2 RTTs per object, OS overhead for each TCP connection

### Persistent HTTP (HTTP/1.1)
- Server **leaves the connection open** after sending a response
- Multiple objects sent over the **same TCP connection**
- Client sends requests as soon as it encounters a referenced object
- As little as **1 additional RTT** for all referenced objects (after the first connection is set up)

### HTTP Request Message
- Human-readable ASCII text
- Structure:
  - **Request line**: method + URL + HTTP version (e.g., `GET /index.html HTTP/1.1`)
  - **Header lines**: one per line, each `field-name: value`
  - **Blank line** (carriage return + line feed): marks end of headers
  - **Body** (for POST requests): the data being sent

**HTTP Methods**:
- **GET**: retrieve an object; can send data in URL after `?`
- **POST**: submit form data; user data is in the request body
- **HEAD**: like GET but server only returns headers, not the object (used for checking metadata)
- **PUT**: upload a new file to the server; replaces existing content at the URL

### HTTP Response Message
- Structure:
  - **Status line**: HTTP version + status code + phrase
  - **Header lines**: metadata about the response
  - **Blank line**
  - **Body**: the requested object

**HTTP Status Codes**:
- **200 OK**: success, object follows
- **301 Moved Permanently**: object has a new URL (given in Location header)
- **400 Bad Request**: server couldn't understand the request
- **404 Not Found**: object not found on server
- **505 HTTP Version Not Supported**

### HTTP/2
- Goal: **decrease delay** in multi-object requests
- HTTP/1.1 had **HOL (Head-of-Line) blocking**: small objects wait behind large ones (FCFS order)
- HTTP/2 improvements:
  - Client can **prioritize** objects; server delivers in priority order (not FCFS)
  - Server can **push** unrequested objects to client
  - **Frame-based**: objects divided into frames; frames interleaved → mitigates HOL blocking

### HTTP/3
- HTTP/2 over one TCP connection still suffers when packets are lost (all objects stall)
- HTTP/3: runs over **UDP** (using QUIC protocol)
- Adds: security, per-object error control, per-object congestion control
- More pipelining, less head-of-line blocking

---

## 2.5 HTTPS — HTTP over TLS/SSL

- **HTTPS** = HTTP + **TLS (Transport Layer Security)** (formerly called SSL)
- All communication between browser and server is **encrypted bidirectionally**
- Uses port **443** instead of 80
- The 'S' stands for **Secure**

### How It Works (Public/Private Key Cryptography)
- Server has a **public key** and a **private key**
- Anything encrypted with the public key can **only** be decrypted with the private key
- Server's public key is distributed via an **SSL Certificate**, digitally signed by a trusted **CA (Certificate Authority)**

### SSL Handshake (5 Steps)
1. Browser requests a secure page (HTTPS) from server
2. Server sends its **SSL certificate** containing its **public key** (signed by a CA)
3. Browser verifies the CA's signature on the certificate (green padlock)
4. Browser creates a **symmetric session key**, encrypts it with the server's public key, and sends it
5. Server decrypts it with its private key → both now have the same symmetric key

After this:
- **Asymmetric encryption** was used to establish trust and exchange the key
- **Symmetric encryption** is used for all subsequent data (faster)

### Benefits of HTTPS
- Better Google ranking
- Improved security (prevents eavesdropping, tampering)
- Customer trust
- Required for any site handling sensitive data

---

## 2.6 User-Server Interaction: Cookies

HTTP is stateless — but websites need to track users. **Cookies** solve this.

### What Cookies Are
- Small pieces of data stored on the user's computer by the browser
- Allow websites to track users across requests and visits

### Four Components of the Cookie System
1. **Cookie header line** in the HTTP response message (server sets a cookie)
2. **Cookie header line** in the next HTTP request message (browser sends cookie back)
3. **Cookie file** kept on the user's host, managed by the browser
4. **Back-end database** at the website that stores user state

### How It Works
1. User visits a site for the first time → server creates a **unique ID** and stores user info in its database
2. Server sends `Set-cookie: 1678` in the response header
3. Browser stores this cookie
4. On all future visits, browser sends `Cookie: 1678` in requests → server recognizes the user

### What Cookies Are Used For
- Track browsing history
- Remember login details (authorization)
- Shopping carts
- Personalized recommendations
- Counting visitors

### Privacy and Cookies
- **First-party cookies**: set by the website you chose to visit
- **Third-party (tracking) cookies**: set by a third party (e.g., ad network AdX.com) embedded in the page — these track you **across multiple websites**
- Third-party cookies enable behavioral profiling and targeted advertising

---

## 2.7 Web Caching (Proxy Servers)

A **Web cache** (also called a **proxy server**) is a network entity that satisfies HTTP requests on behalf of an origin server.

### How Web Caching Works
1. User configures browser to send all HTTP requests to the cache
2. Browser sends request to cache
3. **Cache hit**: if the object is in the cache → cache returns it immediately
4. **Cache miss**: cache requests the object from the origin server, stores a copy, then returns it to the client

### Web Cache Acts as Both
- **Server** to the requesting client
- **Client** to the origin server

Typically installed by ISPs (university, company, residential).

### Why Web Caching?
- **Reduces response time**: cache is physically closer to client
- **Reduces traffic** on the institution's access link → cheaper, less congestion
- **Privacy**: anonymous browsing
- **Enables smaller content providers** to deliver content effectively without a massive CDN

### Conditional GET
- Problem: cached object may be stale (out of date)
- Solution: cache uses **If-Modified-Since: \<date\>** header in its request to origin server
- If the object hasn't changed: server replies **304 Not Modified** (no body sent) → cache serves its copy
- If it has changed: server replies **200 OK** with the new object

---

## 2.8 DNS — The Internet's Directory Service

### The Problem
- Humans prefer to use **names** (e.g., google.com)
- Routers and computers work with **IP addresses** (e.g., 142.250.190.14)
- **DNS maps names to IP addresses**

### DNS Services
- **Hostname-to-IP address translation** (primary function)
- **Host aliasing**: a host can have one canonical name and multiple alias names (e.g., www.ibm.com is really servereast.backup2.ibm.com)
- **Mail server aliasing**: MX records map domain names to mail server hostnames
- **Load distribution**: one name maps to multiple IP addresses (replicated servers); DNS rotates which IP is returned

### Why Not Centralize DNS?
- **Single point of failure**: one crash kills all DNS
- **Traffic volume**: millions of queries per second
- **Distant database**: slow for users far from the server
- **Maintenance**: impossible to keep one database current globally

### DNS: A Distributed Hierarchical Database

Three levels of hierarchy:

#### Root DNS Servers
- 13 **logical** root name servers (each replicated ~200 times globally)
- Official contact of last resort when no other server can resolve a name
- Incredibly important: the Internet cannot function without them
- Managed by **ICANN** (Internet Corporation for Assigned Names and Numbers)
- **DNSSEC** provides security (authentication and integrity)

#### TLD (Top-Level Domain) Servers
- Responsible for .com, .org, .net, .edu, .aero, .jobs, and country domains (.cn, .uk, .fr, .in, etc.)
- Network Solutions manages .com and .net
- Educause manages .edu

#### Authoritative DNS Servers
- An organization's own DNS server(s)
- Provides definitive hostname-to-IP mappings for that organization's hosts
- Can be maintained by the organization or a service provider

### Local DNS Server (Default Name Server)
- Not strictly part of the hierarchy
- Every ISP (residential, university, company) has one
- When a host makes a DNS query, it goes to its local DNS server first
- The local server returns the answer if it has it cached, or acts as a proxy forwarding to the hierarchy

### DNS Name Resolution

#### Iterated Query
1. Client asks local DNS server
2. Local server asks root → root says "ask the .com TLD server"
3. Local server asks .com TLD → TLD says "ask amazon.com's authoritative server"
4. Local server asks authoritative server → gets the IP
5. Local server returns IP to client
- The **local server does all the work**; each server just tells it who to ask next

#### Recursive Query
- Client asks local server → local server asks root → root asks TLD → TLD asks authoritative server → answer bubbles back up
- **Heavy load on upper hierarchy** — less common at the top levels

### DNS Caching and TTL
- Once a name server learns a mapping, it **caches** it
- Cached responses are returned immediately for subsequent queries → faster
- Cache entries have a **TTL (Time to Live)**: they expire after a set time (e.g., seconds to hours)
- TLD servers are often cached at local servers → root servers are rarely queried
- Cached entries can be **stale** (if a host changes its IP before TTL expires)
- Update mechanism: **RFC 2136**

### DNS Zone vs Domain
- A **domain** is a subtree of the DNS namespace (e.g., example.com)
- A **zone** is an administrative unit — a portion of the namespace managed by a particular authority
- A zone can encompass multiple subdomains

### DNS Resource Records (RRs)

Format: **(name, value, type, TTL)**

| Type | Name | Value |
|---|---|---|
| **A** | Hostname | IPv4 address |
| **NS** | Domain name | Hostname of authoritative name server for this domain |
| **CNAME** | Alias hostname | Canonical (real) hostname |
| **MX** | Domain name | Hostname of mail server for this domain |

Examples:
- `(relay1.bar.foo.com, 145.37.93.126, A)` — A record for hostname
- `(foo.com, dns.foo.com, NS)` — NS record pointing to authoritative server
- `(ibm.com, servereast.backup2.ibm.com, CNAME)` — alias mapping
- `(example.com, mail.example.com, MX)` — mail server

### DNS Protocol Messages
- **Both queries and replies use the same message format**
- 12-byte header containing:
  - **Identification** (16-bit): matches replies to queries
  - **Flags**: query or reply, recursion desired, recursion available, authoritative answer
- Variable sections: Questions, Answers (RRs), Authority (RRs), Additional info

### Inserting Records into DNS
1. Register with a **DNS registrar** (e.g., GoDaddy, Network Solutions)
2. Provide the registrar with names and IPs of your authoritative name servers
3. Registrar inserts **NS** and **A** records into the .com TLD server
4. You create records on your own authoritative server (A records for www, MX records for mail)

---

## 2.9 Peer-to-Peer Applications

### P2P Architecture Recap
- No always-on server; peers communicate directly
- Self-scalable: each new peer adds both demand and capacity

### File Distribution: Client-Server vs. P2P

**Client-Server Time**: The server must upload N copies of the file one by one. Distribution time grows **linearly with N** (bottleneck = server upload rate or slowest client download rate).

**P2P Time**: Server uploads only **one** copy initially. Then peers help distribute — each peer that receives a chunk can share it. Total upload capacity = server + sum of all peer upload rates. Distribution time grows **much more slowly** as N increases because more peers = more upload capacity.

### BitTorrent
The most popular P2P file-sharing protocol.

**Key concepts**:
- **Torrent**: a group of peers exchanging chunks of a file
- **Tracker**: a server that tracks which peers are in the torrent
- **Chunks**: file is divided into 256 KB pieces
- When a peer joins, it registers with the tracker and gets a list of peers

**Requesting chunks — "Rarest First"**:
- Each peer tracks which chunks its neighbors have
- It requests the **rarest** chunk first — the one fewest neighbors have
- This helps equalize chunk distribution across the swarm

**Sending chunks — "Tit-for-Tat"**:
- Each peer sends chunks to the **4 peers** currently sending it chunks at the highest rate (the "unchoked" peers)
- Every 30 seconds, a peer **optimistically unchokes** a random new peer → gives newcomers a chance to join
- This incentivizes peers to upload: if you don't upload, you won't get good download rates

---

## 2.10 Socket Programming with TCP and UDP

### What is Socket Programming?
- An API for building network applications
- A socket is a software interface between an application and the transport layer
- Two types of sockets:
  - **SOCK_DGRAM**: UDP socket (connectionless)
  - **SOCK_STREAM**: TCP socket (connection-oriented)

### Socket Programming with UDP

**Client**:
1. Create a UDP socket
2. Get input from user
3. Send the message to server (specifying server IP and port)
4. Receive reply from server
5. Display reply, close socket

**Server**:
1. Create a UDP socket, bind it to a port
2. Wait (loop forever)
3. Read incoming message and client address from socket
4. Process message (e.g., uppercase it)
5. Send reply back to client's address

**Note**: No connection setup in UDP. The client and server can send to any address at any time.

### Socket Programming with TCP

**Key difference from UDP**: TCP requires a **connection to be established** before data is sent.

**Server setup**:
- Creates a **welcoming socket** (on a well-known port) that listens for connections
- When a client connects, the server's TCP creates a **new connection socket** specific to that client
- Server can then communicate with that client on the new socket while the welcoming socket continues accepting new clients

**Client**:
1. Create TCP socket specifying server IP and port
2. TCP automatically establishes connection with server (3-way handshake)
3. Send data through socket
4. Receive reply
5. Close socket

**Server**:
1. Create welcoming socket, bind to port, listen
2. Accept a client connection → creates a new connection socket
3. Read from connection socket
4. Process and write response
5. Close connection socket

---

## 2.11 Other Application Layer Protocols

### FTP — File Transfer Protocol
- Used to **transfer files** between hosts over the Internet
- Uses **TCP** for reliable delivery
- Uses **two separate TCP connections**:
  - **Control connection** (port 21): sends commands and replies (e.g., login, file names, put/get)
  - **Data connection** (port 20): transfers the actual file data
- This separation is called **"out-of-band"** control
- FTP is **stateful**: the server keeps track of the user's current directory, login state

### SMTP — Simple Mail Transfer Protocol
- Used for **sending email** between mail servers and from clients to servers
- Uses **TCP port 25**
- A **push protocol**: the sender actively pushes mail to the receiver's mail server
- Email retrieval uses separate protocols: **IMAP** (Internet Mail Access Protocol) or **POP3**
- SMTP uses ASCII text commands (HELO, MAIL FROM, RCPT TO, DATA, QUIT)

### DHCP (overview — detailed in Unit 4)
- Automatically assigns IP addresses to hosts when they join a network
- "Plug-and-play" protocol

### SNMP — Simple Network Management Protocol
- Used to **monitor and manage network devices** (routers, switches, servers)
- Architecture:
  - **SNMP Manager**: runs on network admin's machine, sends queries and receives responses
  - **SNMP Agents**: run on managed devices, collect and report data
- Agents report device status, performance, and error information to the manager

### Telnet
- Provides **remote login** to another host over a network
- Uses **TCP port 23**
- All data (including passwords) transmitted in **plaintext** — highly insecure
- Largely replaced by SSH

### SSH — Secure Shell
- **Encrypted** remote login protocol — replaces Telnet
- Uses **TCP port 22**
- Uses **public-key encryption** for authentication and encrypts all data
- Provides: remote login, remote command execution, secure file transfer (SCP, SFTP)

---

---

# UNIT 2 (Part 2) + UNIT 3 (Part 1) — Transport Layer

---

## 3.1 Introduction to Transport Layer Services

### Relationship Between Transport and Network Layer

- **Network layer**: logical communication between **hosts** (end systems) — provides host-to-host delivery
- **Transport layer**: logical communication between **processes** running on those hosts — provides process-to-process delivery

The transport layer **relies on** the network layer and **extends** it:
- Network layer delivers packets to the correct host
- Transport layer then gets the data to the correct **process** on that host

**Analogy**: 
- Hosts = houses
- Processes = kids in the house
- Network layer = postal service delivering to the house
- Transport layer = the person inside the house who hands the letter to the right kid

### Overview of Transport Layer in the Internet

Two protocols:

**TCP (Transmission Control Protocol)**:
- Reliable, in-order delivery
- Connection-oriented
- Congestion control
- Flow control

**UDP (User Datagram Protocol)**:
- Unreliable, unordered delivery
- Connectionless
- No congestion or flow control
- "Best-effort" — no frills extension of IP

Neither provides: **timing guarantees** or **bandwidth guarantees**.

### Transport Layer Actions

**Sender side**:
1. Receives an application-layer message
2. Determines segment header field values
3. Creates a segment (message + header)
4. Passes segment to the network layer (IP)

**Receiver side**:
1. Receives segment from IP
2. Checks header values
3. Extracts the application-layer message
4. Demultiplexes message up to the correct application via socket

---

## 3.2 Multiplexing and Demultiplexing

### Multiplexing (at sender)
- **Gathering** data from multiple sockets, wrapping each with transport header → creating segments
- The transport layer handles data from multiple application sockets simultaneously

### Demultiplexing (at receiver)
- **Delivering** the data in a received segment to the correct socket
- Done using port numbers in the segment header

### Connectionless Demultiplexing (UDP)
- A UDP socket is identified by **(destination IP address, destination port number)**
- Two UDP segments with the same dest IP and dest port will go to the **same socket**, regardless of source IP/port

### Connection-Oriented Demultiplexing (TCP)
- A TCP socket is identified by a **4-tuple**: (source IP, source port, destination IP, destination port)
- Two TCP segments with different source IPs or source ports will be directed to **different sockets**
- This allows a server to distinguish multiple simultaneous clients

---

## 3.3 Connectionless Transport: UDP

### UDP Segment Structure
Fields in the UDP header (8 bytes total):
- **Source port** (16 bits): port of the sending process
- **Destination port** (16 bits): port of the receiving process
- **Length** (16 bits): total length of UDP segment (header + data) in bytes
- **Checksum** (16 bits): error detection
- **Data**: the application message

### UDP Checksum
- Provides **error detection** (not correction)
- Sender: treats all 16-bit words in segment + pseudo-header as integers, sums them in **1's complement** arithmetic → stores result in checksum field
- Receiver: computes the same sum over received segment; if result is all 1s → no error detected; if any 0 → error
- Note: error detection does **not** mean the error is fixed — the segment may simply be discarded

### Why Use UDP?
- **No connection setup**: no handshake, no delay
- **No connection state**: server can support many more clients
- **Small header overhead**: 8 bytes vs. 20 bytes for TCP
- **No congestion control**: UDP can blast away at any rate — useful for real-time apps (DNS, streaming, gaming, VoIP)
- The application can add its own error control if needed

---

## 3.4 Principles of Reliable Data Transfer (RDT)

The network layer (IP) is **unreliable** — packets can be lost, corrupted, or reordered. The transport layer must build reliability on top of this.

### Building a Reliable Data Transfer Protocol — rdt Evolution

#### rdt 1.0 — Perfectly Reliable Channel
- Assumption: underlying channel is perfect — no errors, no loss
- Sender: send data; Receiver: receive data
- Nothing special needed — trivial

#### rdt 2.0 — Channel with Bit Errors
- Assumption: bits may be flipped, but no packet loss
- New mechanisms:
  - **Error detection**: checksum
  - **Receiver feedback**: **ACK** (acknowledged — OK) and **NAK** (not acknowledged — error)
  - **Retransmission**: sender retransmits if it receives a NAK
- Problem: what if the ACK/NAK itself is corrupted?

#### rdt 2.1 — Corrupted ACK/NAK Handling
- Sender adds a **sequence number** (0 or 1) to each packet
- If ACK/NAK is corrupted, sender **retransmits**
- Receiver uses sequence number to detect **duplicates** (and discards them)

#### rdt 2.2 — NAK-Free
- Same as rdt 2.1 but eliminates NAK
- Instead of NAK, receiver sends ACK for the **last correctly received packet**
- A duplicate ACK tells sender the same thing as a NAK

#### rdt 3.0 — Channel with Errors AND Loss
- Assumption: bits may be corrupted AND packets may be lost entirely
- New mechanism: **Timer** at the sender
- Sender starts a timer after sending a packet
- If no ACK received before timer expires → **retransmit**
- Must handle: premature timeout (ACK arrives just after retransmit) → handled by sequence numbers

### Pipelined Reliable Data Transfer
- **Stop-and-wait** (rdt 3.0) is very slow: sender sends one packet, waits for ACK, then sends next
- **Link utilization** is tiny: sender is idle most of the time while waiting
- **Pipelining**: sender can have multiple "in-flight" unacknowledged packets simultaneously
- Requires larger sequence number space and buffers at sender and/or receiver
- Two pipelining protocols: **Go-Back-N** and **Selective Repeat**

---

## 3.5 Go-Back-N (GBN)

### Concept
- Sender can have up to **N** unacknowledged ("in-flight") packets at a time — this is the **window size**
- **k-bit sequence numbers** are used (e.g., 3-bit = sequence numbers 0–7)

### GBN Sender
- Maintains a **window** of up to N consecutive sent-but-unACKed packets
- **Cumulative ACK**: ACK(n) means all packets up to and including sequence number n have been received correctly
- On receiving ACK(n): **slide the window forward** to start at n+1
- **Single timer** for the oldest unACKed packet
- On **timeout(n)**: retransmit packet n AND all higher-numbered packets in the window (all in-flight packets are retransmitted)

### GBN Receiver
- **ACK-only**: always sends ACK for the highest in-order packet received so far
- Maintains only **rcv_base** (next expected sequence number)
- **Out-of-order packets**: can discard or buffer (implementation choice), but always re-ACKs the last in-order packet
- Only one sequence number to track

### Key Characteristics
- Simple receiver (no buffer needed)
- Inefficient when window is large and errors are frequent — many packets unnecessarily retransmitted
- Good when error rate is low

---

## 3.6 Selective Repeat (SR)

### Concept
- Receiver individually ACKs each correctly received packet
- Sender only retransmits packets that were **not** acknowledged (individually)
- Both sender and receiver maintain **windows** of size N

### SR Sender
- Maintains a window of N consecutive sequence numbers
- Sends packets up to the window limit
- **Individual timer** per unACKed packet
- On timeout(n): retransmit only packet n, restart its timer
- On ACK(n): mark n as received; if n = sendbase (oldest unACKed), advance window to next unACKed

### SR Receiver
- **Individually ACKs** each correctly received packet (whether in-order or not)
- **Buffers** out-of-order packets (waiting for the missing ones to fill gaps)
- On receiving packet n in [rcvbase, rcvbase+N-1]: send ACK(n); if out-of-order, buffer it; if in-order, deliver it and all buffered in-order packets, advance window
- On receiving packet n in [rcvbase-N, rcvbase-1]: ACK it again (sender may not have received the original ACK)

### SR Dilemma
- Window size must be **≤ half the sequence number space**
- Otherwise, the receiver cannot distinguish between a new packet and a retransmission after wraparound

### GBN vs. Selective Repeat

| Feature | Go-Back-N | Selective Repeat |
|---|---|---|
| On timeout | Retransmit all in window | Retransmit only the lost packet |
| Receiver buffer | None needed | Buffers out-of-order packets |
| ACK type | Cumulative | Individual |
| Efficiency under loss | Lower (many retransmissions) | Higher (only retransmit what's lost) |
| Receiver complexity | Simple | More complex |

---

## 3.7 Connection-Oriented Transport: TCP

### The TCP Connection
- **Point-to-point**: exactly one sender, one receiver
- **Full-duplex**: data flows in both directions simultaneously on the same connection
- **Connection-oriented**: handshake required before data exchange
- **MSS (Maximum Segment Size)**: maximum amount of data in a TCP segment (typically 1460 bytes for Ethernet)
- **Byte-stream service**: TCP sees data as a stream of bytes, not individual messages

### TCP Segment Structure

Key fields:
- **Source port** (16 bits) and **Destination port** (16 bits)
- **Sequence number** (32 bits): byte number of the first byte of data in this segment (in the overall byte stream)
- **Acknowledgment number** (32 bits): the byte number of the **next** byte the receiver expects (cumulative ACK)
- **Header length**: length of TCP header in 32-bit words
- **Flags** (6 bits):
  - **URG**: urgent data (rarely used)
  - **ACK**: acknowledgment field is valid
  - **PSH**: push data to application immediately
  - **RST**: reset the connection
  - **SYN**: synchronize sequence numbers (used in connection setup)
  - **FIN**: sender is finished sending (used in connection teardown)
  - **C, E**: congestion notification (ECN)
- **Receive window** (16 bits): number of bytes the receiver is willing to accept (used for flow control)
- **Checksum** (16 bits): error detection
- **Urgent data pointer**: used with URG flag (rarely)
- **Options**: variable length, e.g., MSS negotiation

### TCP Sequence and Acknowledgment Numbers
- **Sequence numbers** are byte offsets in the data stream, not packet numbers
- If data is "Hello World" (10 bytes) and first byte is #100, then seq# = 100
- **ACK number**: "I have received up to byte X, send me byte X+1"
- TCP uses **cumulative acknowledgments**: ACK covers all bytes up to and including that number

### TCP RTT Estimation and Timeout
TCP must set a **timeout** for retransmission — too short = unnecessary retransmissions; too long = slow response to loss.

- **SampleRTT**: measured RTT for a segment (from send to ACK)
- **EstimatedRTT**: weighted average (EWMA) of past SampleRTTs
  - EstimatedRTT = (1-α) × EstimatedRTT + α × SampleRTT (α typically 0.125)
  - Past samples decay exponentially — recent samples count more
- **DevRTT**: deviation (variability) of RTT, also an EWMA
- **TimeoutInterval** = EstimatedRTT + 4 × DevRTT
  - Safety margin of 4 × DevRTT handles variability

### TCP Reliable Data Transfer
- TCP creates a reliable service on top of unreliable IP
- Uses: sequence numbers, cumulative ACKs, and timers

**Retransmission Scenarios**:
1. **Timeout**: if timer expires before ACK received → retransmit the segment and restart timer
2. **Fast Retransmit**: if sender receives **3 duplicate ACKs** for the same sequence number → packet lost → retransmit immediately (before timeout)
   - 3 duplicate ACKs means 3 ACKs with the same ACK number → the next expected packet hasn't arrived but later ones have → the missing packet is probably lost

### TCP Flow Control
- **Problem**: the receiver has a finite receive buffer; if the sender sends too fast, it overflows the buffer
- **Solution**: receiver controls the sender by advertising available buffer space

**Mechanism**:
- Receiver includes **rwnd (receive window)** field in TCP header = free buffer space available
- Sender limits the amount of unACKed data to **min(cwnd, rwnd)** where cwnd is the congestion window
- This ensures the sender never sends more than the receiver can absorb

### TCP Connection Management

#### 3-Way Handshake (Connection Setup)
Purpose: agree to establish connection, synchronize sequence numbers

1. **SYN**: Client sends TCP segment with SYN flag=1, a random initial sequence number (client_isn)
2. **SYNACK**: Server allocates buffers and variables, sends segment with SYN=1, ACK=1, server_isn, ACK# = client_isn+1
3. **ACK**: Client allocates buffers/variables, sends ACK segment (SYN=0), ACK# = server_isn+1, can carry data

After this: connection is **ESTABLISHED** on both sides.

#### Closing a Connection (4-Step)
1. Client sends segment with **FIN=1** → "I'm done sending"
2. Server sends **ACK**
3. Server sends its own **FIN=1** → "I'm done sending"
4. Client sends **ACK** → connection fully closed

Each side closes independently, allowing **half-close** (one side done but other still sending).

---

## 3.8 TCP Congestion Control

### Why Congestion Control?
- **Congestion**: too many sources sending too much data too fast for the network to handle
- Effects: long queuing delays, packet loss
- Unlike flow control (which protects the receiver), congestion control protects **the network**

### Causes and Costs of Congestion

**Scenario 1** (2 senders, 1 router with infinite buffer):
- As load increases, average delay increases
- Maximum throughput per connection = R/2

**Scenario 2** (finite buffers, packet loss):
- Router drops packets when buffer fills
- Retransmissions add overhead — some bandwidth wasted on retransmitting packets that were actually received (due to premature timeout)

**Scenario 3** (multiple hops):
- When a packet is dropped after traversing several links, all the upstream bandwidth used for that packet was wasted
- This is why congestion is so costly — wasted capacity at multiple routers

### Approaches to Congestion Control

**End-to-end congestion control** (TCP's approach):
- Network provides **no explicit feedback**
- Senders infer congestion from observed events (loss, delay)

**Network-assisted congestion control** (ATM, ECN):
- Routers explicitly inform senders about congestion
- **ECN (Explicit Congestion Notification)**: routers set bits in packet headers; receivers echo back to sender
- TCP also supports ECN (flags C and E in header)

### TCP Congestion Control: AIMD

TCP uses **AIMD (Additive Increase Multiplicative Decrease)**:

- **Additive Increase**: increase cwnd by 1 MSS per RTT (probe for available bandwidth linearly)
- **Multiplicative Decrease**: cut cwnd significantly on detected loss

This produces the classic **sawtooth pattern** in TCP's sending rate.

**Why AIMD?** It's been mathematically shown that AIMD converges to fair bandwidth sharing and is stable.

### TCP Congestion Window (cwnd)

- **cwnd** (congestion window): limits how much data the sender can have in flight
- **Effective send rate** ≈ cwnd / RTT (bytes per second)
- Sender sends at rate: LastByteSent − LastByteAcked ≤ min(cwnd, rwnd)

### TCP Congestion Control: Three Phases

#### 1. Slow Start
- Initial cwnd = **1 MSS**
- For every ACK received, cwnd increases by 1 MSS
- This means cwnd **doubles every RTT** — exponential growth
- Despite the name, slow start grows fast — starts slow, grows exponentially
- Continues until cwnd reaches **ssthresh** (slow start threshold)

#### 2. Congestion Avoidance
- Once cwnd ≥ ssthresh: switch to **linear** increase
- cwnd increases by MSS × (MSS/cwnd) per ACK received = 1 MSS per RTT
- Probing carefully for more bandwidth

#### 3. Fast Recovery (TCP Reno only)
- After 3 duplicate ACKs: retransmit the missing segment
- cwnd = ssthresh + 3 (temporarily inflate by 3 because 3 packets left the network)
- For each additional duplicate ACK: cwnd += 1 MSS
- When the retransmitted segment is ACKed: cwnd = ssthresh, exit fast recovery, enter congestion avoidance

### TCP Tahoe vs. TCP Reno

#### TCP Tahoe (older)
- On **ANY loss** (timeout OR 3 duplicate ACKs):
  - ssthresh = cwnd/2
  - cwnd = 1 MSS
  - Restart slow start
- Simple but harsh — always drops to 1 MSS

#### TCP Reno (current standard)
- On **3 duplicate ACKs** (mild loss signal):
  - ssthresh = cwnd/2
  - cwnd = ssthresh + 3 (fast recovery)
  - Retransmit missing segment
  - Stays in fast recovery until new ACK arrives
- On **timeout** (severe loss signal):
  - ssthresh = cwnd/2
  - cwnd = 1 MSS
  - Restart slow start

**Key difference**: Reno distinguishes between mild loss (3 dup ACKs) and severe loss (timeout), responding more gently to mild loss. Tahoe treats all loss the same.

### ssthresh — Slow Start Threshold
- Determines when to switch from slow start to congestion avoidance
- Initially set to a large value (64 KB)
- Updated on loss: **ssthresh = cwnd/2** at the moment of loss

### Full TCP Congestion Control State Machine Summary
- Start: cwnd=1, ssthresh=64KB
- Slow start: cwnd doubles per RTT until ssthresh or loss
- Congestion avoidance: cwnd += 1 MSS per RTT until loss
- On 3 dup ACKs (Reno): ssthresh=cwnd/2, cwnd=ssthresh+3, fast recovery
- On timeout: ssthresh=cwnd/2, cwnd=1, back to slow start

---

---

# UNIT 3 (Part 2) — Network Layer and Internet Protocol

---

## 4.1 Overview of Network Layer

### Network Layer Function
- Transports segments from the **sending host** to the **receiving host**
- Sender: encapsulates transport segments into **datagrams**, passes to link layer
- Receiver: delivers segments to the transport layer protocol
- **Every Internet device** (hosts, routers) runs network layer protocols

### Two Key Network Layer Functions

#### Forwarding (Data Plane)
- **Local, per-router** function
- When a datagram arrives at a router's input port, the router moves it to the appropriate output port
- Done using the **forwarding table** (also called flow table in SDN)
- Analogy: taking a single interchange on a highway trip

#### Routing (Control Plane)
- **Network-wide** function
- Determines the end-to-end path for datagrams — which routers to traverse
- Done by **routing algorithms** that populate forwarding tables
- Analogy: planning the entire route of a trip

### Data Plane vs. Control Plane

| | Data Plane | Control Plane |
|---|---|---|
| Scope | Local to each router | Network-wide |
| Function | Forwarding | Routing |
| Speed | Nanoseconds (hardware) | Milliseconds–seconds (software) |
| Implementation | In router hardware (ASIC) | Routing algorithms or SDN controller |

### Two Control Plane Approaches

1. **Traditional routing algorithms**: each router runs routing protocol, routers exchange info, each computes its own forwarding table
2. **Software-Defined Networking (SDN)**: a remote (logically centralized) controller computes forwarding tables and pushes them to routers

---

## 4.2 What's Inside a Router?

### Router Architecture Overview

Four main components:

#### 1. Input Ports
- **Line termination**: physical layer — receive bits
- **Link layer protocol**: data link layer processing
- **Decentralized switching**:
  - Lookup destination IP address in forwarding table
  - Determine output port
  - Forward to switch fabric
- **Input port queuing**: if datagrams arrive faster than they can be forwarded to switch fabric, they queue here

#### 2. Switch Fabric
- Connects input ports to output ports
- Three switching methods:
  - **Via memory**: packet copied to CPU memory, then to output port (early routers; memory bandwidth limited — 2 bus crossings per datagram)
  - **Via bus**: packet crosses shared bus from input to output memory (limited by bus bandwidth)
  - **Via interconnection network (crossbar)**: multiple packets can be forwarded simultaneously; highly parallel; used in modern high-speed routers

#### 3. Output Ports
- Buffers datagrams received from switch fabric
- Performs link-layer and physical-layer functions to transmit datagrams
- **Buffering** required when datagrams arrive faster than the link's transmission rate
- **Scheduling**: which datagram to transmit next (FIFO, priority, round-robin, etc.)
- **Drop policy**: which datagrams to drop when buffer is full (tail drop, RED, etc.)

#### 4. Routing Processor
- Executes routing protocols
- Maintains routing tables and link state info
- Computes forwarding table (in traditional routers) or communicates with SDN controller

### Forwarding Table Lookup — Destination-Based
- Router looks at destination IP address in arriving packet header
- Finds the matching entry in forwarding table using **longest prefix matching**
- **Longest prefix matching**: if multiple entries match the destination, use the one with the longest (most specific) prefix

### Generalized Forwarding
- Modern routers (especially SDN-based) can forward based on **any header field**, not just destination IP
- Match on fields like source/dest IP, port numbers, protocol → take action (forward, drop, modify)

### Head-of-Line (HOL) Blocking
- A queued datagram at the **front** of an input queue blocks other datagrams behind it from moving forward, even if their output ports are free
- Occurs when using input port queuing
- Limits throughput; solved by using virtual queues or output port queuing

---

## 4.3 Introduction to SDN (Software-Defined Networking)

### Traditional Routing Problem
- In traditional networks, each router runs routing algorithms independently and maintains its own forwarding table
- Routers are "smart" — complex to manage and program
- Hard to implement new forwarding behaviors

### SDN Concept
- **Decouple** the control plane (routing decisions) from the data plane (forwarding)
- Move the control plane to a **remote, logically centralized SDN controller**
- Routers become simple "dumb" forwarding devices — they just follow the controller's instructions

### SDN Architecture Components
- **SDN Controller**: centralized software system that computes forwarding tables
- **Control Agents (CA)**: software on each router that communicates with the controller
- **OpenFlow API**: standard interface between controller and routers for installing flow table entries
- **Southbound interface**: between controller and routers (OpenFlow)
- **Northbound interface**: between controller and network applications

### How It Works
1. SDN controller has a global view of the network topology
2. Controller runs routing algorithms, computes optimal paths
3. Controller pushes forwarding table entries to each router via OpenFlow
4. Routers simply match packets against their flow table and forward

### Benefits of SDN
- **Programmability**: network behavior can be changed by updating the controller software
- **Centralized management**: easier to implement complex policies
- **Vendor independence**: standard APIs reduce lock-in
- **Innovation**: new forwarding behaviors without changing router hardware

### SDN Analogy
Traditional networking = mainframe era (monolithic, everything in one box)
SDN = PC era (separated concerns, open APIs, specialized software on commodity hardware)

### OpenFlow
- **"Match plus action"** forwarding model
- Match on: source/dest IP, source/dest port, protocol, MAC address, VLAN tag, etc.
- Actions: forward to port(s), drop, modify header field, send to controller

---

## 4.4 The Internet Protocol (IPv4)

### IPv4 Datagram Format

A datagram has a **20-byte base header** (plus optional fields):

| Field | Size | Description |
|---|---|---|
| Version | 4 bits | IP version (4 for IPv4) |
| Header length | 4 bits | Length of header in 32-bit words (usually 5 = 20 bytes) |
| Type of service (TOS) | 8 bits | Quality of service (e.g., ECN bits) |
| Total length | 16 bits | Total datagram length (header + data) in bytes |
| Identifier | 16 bits | Used for fragmentation — all fragments of a datagram share same ID |
| Flags | 3 bits | Fragmentation flags (don't fragment, more fragments) |
| Fragmentation offset | 13 bits | Position of this fragment in the original datagram |
| TTL (Time to Live) | 8 bits | Decremented by 1 at each router; dropped when 0 (prevents infinite loops) |
| Upper-layer protocol | 8 bits | Which transport protocol (6=TCP, 17=UDP, 1=ICMP) |
| Header checksum | 16 bits | Error detection for header only |
| Source IP address | 32 bits | |
| Destination IP address | 32 bits | |
| Options | Variable | Rarely used |
| Data (payload) | Variable | The transport-layer segment |

### IP Fragmentation and Reassembly

**Why fragmentation?** Different links have different **MTU (Maximum Transmission Unit)** — the largest datagram a link can carry (e.g., Ethernet MTU = 1500 bytes).

**How fragmentation works**:
- If a datagram is larger than the outgoing link's MTU, the router **fragments** it into smaller pieces
- Each fragment becomes an independent datagram with its own IP header
- Fragments carry the **same Identifier** as the original (so receiver can group them)
- **Fragmentation offset**: byte position of this fragment's data in the original, divided by 8
- **More fragments flag**: set to 1 for all fragments except the last
- Fragments are **reassembled at the destination** only (not at intermediate routers)

**Problem with fragmentation**: if one fragment is lost, the entire original datagram must be retransmitted. IPv6 eliminates router-based fragmentation.

### IPv4 Addressing

#### What is an IP Address?
- A **32-bit** identifier for a network interface (not just a host — a host with multiple interfaces has multiple IPs)
- Written in **dotted-decimal notation**: four decimal numbers separated by dots (e.g., 192.168.1.1)

#### Subnets
- A **subnet** is a portion of the network where all devices share the same high-order bits (subnet part)
- Devices within the same subnet can communicate without a router
- **Subnet mask**: indicates how many bits are the subnet part (e.g., /24 means first 24 bits = subnet)
- **Recipe for finding subnets**: detach each interface from its host/router — each isolated "island" is a subnet

#### CIDR — Classless InterDomain Routing
- Pronounced "cider"
- Subnet portion of address can be **arbitrary length** (not fixed to 8/16/24 bits)
- Address format: **a.b.c.d/x** where x is the number of subnet bits
- Example: 200.23.16.0/23 means first 23 bits are the network part
- Replaced classful addressing (Class A /8, Class B /16, Class C /24) because classful was inflexible

#### Classful Addressing (Historical)
- **Class A** (/8): first 8 bits = network; supports ~16.7 million hosts
- **Class B** (/16): first 16 bits = network; supports ~65,534 hosts
- **Class C** (/24): first 24 bits = network; supports 254 hosts
- Problem: inflexible — a company needing 300 addresses had to use a Class B (65K addresses wasted)

#### How Does a Host Get an IP Address?
- **Manual (static)**: sysadmin hardcodes IP in config file
- **DHCP (Dynamic Host Configuration Protocol)**: automatically assigned when host joins network — "plug-and-play"

#### How Does a Network Get Its IP Block?
- Apply to ISP or regional registry (ICANN)
- ISP gets a block from IANA (Internet Assigned Numbers Authority) and subdivides it

### NAT — Network Address Translation

**Problem**: IPv4 address space is exhausted (~4.3 billion addresses, not enough for all devices).

**NAT solution**: A single **public IP address** represents an entire private network to the outside world.

**How NAT works**:
- All devices in the private network use **private IP addresses** (e.g., 10.x.x.x, 192.168.x.x)
- The NAT router has one public IP address
- When a private device sends a packet:
  1. NAT router replaces source private IP with its public IP
  2. NAT router assigns a new source port number (unique per private connection)
  3. NAT router records the mapping: (private IP, private port) ↔ (public IP, new port) in the **NAT translation table**
- When a reply comes back:
  1. NAT router looks up the destination port in the translation table
  2. Translates back to private IP and port
  3. Delivers to the correct internal device

**Key point**: All packets leaving the private network have the **same source IP** (the public IP) but different source port numbers.

**NAT controversy**:
- Violates end-to-end argument (routers shouldn't modify addresses)
- Port numbers used for addressing, not just multiplexing
- Hard to run servers inside NAT (incoming connections need port forwarding)
- **NAT traversal**: techniques for P2P connections through NAT (e.g., STUN, TURN)

---

---

# UNIT 4 (Part 1) — Network Layer (Continued)

---

## 4.5 DHCP — Dynamic Host Configuration Protocol

### Goal
Automatically assign IP addresses and network configuration to hosts when they join a network — **plug-and-play**.

### What DHCP Returns
- The host's **IP address**
- **Subnet mask** (network vs. host portion)
- Address of the **first-hop router** (default gateway)
- Address and name of **DNS server**

### DHCP Process (4 Steps — "DORA")

**1. DHCP Discover** (client → broadcast)
- New host broadcasts to 255.255.255.255 (port 67)
- "Is there a DHCP server out there?"
- Source IP = 0.0.0.0 (doesn't have one yet)

**2. DHCP Offer** (server → broadcast)
- DHCP server replies with an offered IP address, subnet mask, lease time
- Still broadcast (client doesn't have an IP yet)
- "Here's an IP address you can use"

**3. DHCP Request** (client → broadcast)
- Client broadcasts "I'd like to use that IP address" (may receive offers from multiple servers)
- Transaction ID identifies which offer is accepted

**4. DHCP ACK** (server → broadcast)
- Server confirms the assignment: "You've got that IP address!"
- Client is now configured

**Note**: Steps 1 and 2 can be skipped if the client remembers a previously allocated address and wants to reuse it.

### Where DHCP Server Lives
- Typically **co-located in the router** (first-hop router), serving all subnets attached to that router

### DHCP Encapsulation Example
- DHCP request is encapsulated: DHCP → UDP → IP → Ethernet
- Ethernet frame is **broadcast** (dest = FF:FF:FF:FF:FF:FF) on the LAN
- Router running DHCP server receives it, processes it, sends DHCP ACK back

---

## 4.6 ICMP — Internet Control Message Protocol

### What ICMP Is
- Used by **hosts and routers** to communicate **network-layer information**
- Primarily for **error reporting** and **diagnostics**
- Architecturally lives just **above IP** — ICMP messages are carried as IP payloads
- Every ICMP message has a **type** and a **code** field

### Key ICMP Message Types

| Type | Code | Description |
|---|---|---|
| 0 | 0 | Echo reply (ping response) |
| 3 | 0 | Destination network unreachable |
| 3 | 1 | Destination host unreachable |
| 3 | 2 | Destination protocol unreachable |
| 3 | 3 | Destination port unreachable |
| 3 | 6 | Destination network unknown |
| 3 | 7 | Destination host unknown |
| 8 | 0 | Echo request (ping) |
| 9 | 0 | Router advertisement |
| 10 | 0 | Router discovery |
| 11 | 0 | TTL expired |
| 12 | 0 | Bad IP header |

### Ping
- Uses ICMP Echo Request (type 8) and Echo Reply (type 0)
- Sender sends echo request to target
- Target replies with echo reply
- Used to test connectivity and measure RTT

### Traceroute and TTL Expired
- Traceroute exploits the **TTL expired** ICMP message (type 11)
- Sends UDP segments with TTL=1, TTL=2, TTL=3, …
- Each router that decrements TTL to 0 sends back an ICMP TTL expired message
- Source records the RTT to each hop
- When UDP reaches destination (unreachable port), destination sends ICMP port unreachable (type 3, code 3) — that's when traceroute stops

---

## 4.7 IPv6 Protocol

### Why IPv6?
- IPv4 address space (**32-bit = ~4.3 billion**) is **exhausted** — allocated completely
- IPv6 uses **128-bit addresses** — 2^128 ≈ 3.4 × 10^38 addresses (astronomically large)
- IPv6 address space is **2^96 times** larger than IPv4
- Also: streamlined header, no fragmentation at routers, no checksum (simplifies router processing)

### IPv6 Address Notation
- Written in **colon-hex notation**: 8 groups of 4 hex digits separated by colons
- Example: `2001:0db8:0000:0000:0000:ff00:0042:8329`

**Compression Rules**:
1. **Leading zeros** in each group can be omitted: `0042` → `42`
2. **One run** of consecutive all-zero groups can be replaced with `::` (double colon)
   - `::` can only appear **once** in an address (ambiguous otherwise)
   - Example: `2001:db8::ff00:42:8329`

### IPv6 Address Types
- **Unicast**: identifies a single interface
- **Multicast**: identifies a group; packet delivered to all members
- **Anycast**: identifies a group; packet delivered to the nearest member

### IPv6 Datagram Format

Fixed **40-byte header** (simpler than IPv4):

| Field | Size | Description |
|---|---|---|
| Version | 4 bits | 6 for IPv6 |
| Traffic class | 8 bits | Like IPv4 TOS — priority |
| Flow label | 20 bits | Identify a "flow" for special handling |
| Payload length | 16 bits | Length of data following header |
| Next header | 8 bits | Identifies the type of next header (TCP=6, UDP=17, ICMPv6=58) |
| Hop limit | 8 bits | Like TTL — decremented at each router |
| Source address | 128 bits | |
| Destination address | 128 bits | |
| Data | Variable | Transport segment or extension headers |

**What IPv6 removes compared to IPv4**:
- **No fragmentation/reassembly** by intermediate routers (if packet too big, router sends ICMPv6 "Packet Too Big" back to source)
- **No header checksum** (transport layer handles this)
- **No options** (replaced by extension headers linked via Next Header field)

### Transition from IPv4 to IPv6

The Internet can't switch all at once — IPv4 and IPv6 coexist.

**Tunneling** — the primary transition mechanism:
- IPv6 datagrams are carried **as payload inside IPv4 datagrams** between IPv4-only routers ("packet within a packet")
- A tunnel exists between two IPv6-capable routers (or hosts) separated by an IPv4-only network
- At the tunnel entrance: IPv4 router wraps the IPv6 datagram in an IPv4 header (protocol = 41)
- At the tunnel exit: IPv4 header is stripped; original IPv6 datagram is delivered

**Dual-stack approach**: Some routers/hosts support both IPv4 and IPv6 and can communicate with either.

---

## 4.8 Introduction to Routing Algorithms

### What Routing Algorithms Do
- Determine the **best path** from source to destination
- Populate the **forwarding tables** in routers
- "Best" typically = lowest cost path; cost can represent: hop count, bandwidth, delay, congestion, monetary cost

### Classification

**By information scope**:
- **Link State (LS)**: each router has complete knowledge of the entire network topology and all link costs → centralized computation
- **Distance Vector (DV)**: each router knows only its directly connected neighbors and their costs → distributed, iterative computation

**By dynamics**:
- **Static**: routes change slowly (manually configured)
- **Dynamic**: routes change automatically in response to topology changes

---

### Link State Algorithm: Dijkstra's Algorithm

#### Key Properties
- Requires each router to **broadcast** its link state (which links it has and their costs) to all other routers in the network ("link state broadcast")
- After broadcast, every router has a complete **graph of the network**
- Then each router **independently** runs Dijkstra's algorithm to compute shortest paths to all destinations

#### Algorithm Steps
1. Start with the source node
2. Maintain set **N'** of nodes whose least-cost path from source is known
3. Initialize: D(v) = cost of direct link to v if neighbor, else infinity; D(source) = 0
4. Repeat until all nodes are in N':
   a. Find node w not in N' with minimum D(w)
   b. Add w to N'
   c. Update D(v) for all neighbors v of w: D(v) = min(D(v), D(w) + c(w,v))
5. After algorithm: D(v) = least-cost path from source to every node v

#### Properties
- **Complexity**: O(n²) with basic implementation; O(n log n) with priority queue
- Produces a forwarding table for the source router

---

### Distance Vector Algorithm: Bellman-Ford

#### Key Properties
- **Distributed**: each node only communicates with its **directly connected neighbors**
- **Iterative**: process repeats until no more updates (self-stopping)
- **Asynchronous**: nodes don't need to be in sync

#### Bellman-Ford Equation
The key equation: **dx(y) = min over all neighbors v { c(x,v) + dv(y) }**

Where:
- dx(y) = cost of least-cost path from x to y
- c(x,v) = cost of link from x to neighbor v
- dv(y) = neighbor v's estimate of cost to y

Each node x:
1. Maintains its own **distance vector** Dx = [Dx(y) for all destinations y]
2. Knows cost to each neighbor: c(x,v)
3. Receives distance vectors from all neighbors: Dv = [Dv(y)] for each neighbor v

#### Algorithm Operation
- Initialization: Dx(x) = 0; Dx(y) = ∞ for all y ≠ x (unless y is a direct neighbor)
- Each node **sends its distance vector** to all neighbors periodically or when it changes
- On receiving a new DV from neighbor v, node x updates: Dx(y) = min{c(x,v) + Dv(y)}
- If Dx changes, x notifies its neighbors → they update → propagates through network
- Converges when no more updates occur

#### Count-to-Infinity Problem
- When a link cost **increases** dramatically (or a link fails), bad news travels slowly
- Nodes may keep updating each other with stale (too-optimistic) routes
- Distance estimates "count up to infinity" before converging
- Solution: **Poisoned reverse** — if x routes to y via z, x tells z that its distance to y is infinity (so z won't try to route through x → y)

#### LS vs. DV Comparison

| | Link State (Dijkstra) | Distance Vector (Bellman-Ford) |
|---|---|---|
| Info scope | Global (full topology) | Local (neighbors only) |
| Computation | Centralized (each node runs full algorithm) | Distributed (uses neighbor estimates) |
| Convergence speed | Fast | Slower (iterative) |
| Robustness | More robust (bad info doesn't propagate) | Count-to-infinity possible |
| Message complexity | O(n × E) broadcasts | Only with neighbors |
| Implementations | OSPF, IS-IS | RIP, BGP (conceptually) |

---

---

# UNIT 4 (Part 2) — Link Layer and LAN

---

## 5.1 Introduction to Link Layer

### Responsibility
The link layer is responsible for transferring a datagram from **one node to a physically adjacent node** over a single link.

### Terminology
- **Nodes**: all devices that run link-layer protocols — hosts, routers, switches, WiFi access points
- **Links**: the communication channels connecting adjacent nodes (wired or wireless)
- **Frame**: the link-layer packet that **encapsulates** the network-layer datagram

### Context
- Different links use different link-layer protocols (e.g., Ethernet on one hop, WiFi on another)
- Each link protocol may provide different services
- The **transport analogy**: a trip from New York to Paris — limo (Ethernet) to JFK, plane (fiber backbone) to CDG, train (DSL) to hotel. Each leg uses a different transport mode.

### Where Link Layer is Implemented
- In the **NIC (Network Interface Card)** — a hardware chip or card in every device
- The NIC implements **both** the link layer and the physical layer
- NIC attaches to host via the host bus (e.g., PCIe)
- Combination of hardware (fast operations), software (higher-level control), and firmware

### Link Layer Services

**Framing and Link Access**:
- Encapsulate datagram into a frame, adding header and trailer
- On shared medium: control channel access ("MAC" protocol)
- **MAC (Media Access Control) addresses** in frame headers identify source and destination (different from IP!)

**Reliable Delivery**:
- Guarantee error-free delivery on the link
- Seldom used on low-error links (fiber, copper Ethernet) — overhead not worth it
- Used on **wireless links** which have high error rates

**Flow Control**:
- Pacing between adjacent sender and receiver — don't overwhelm the receiver's buffer

**Error Detection**:
- Errors caused by signal attenuation and noise
- Receiver detects errors and signals retransmission or drops the frame

**Error Correction**:
- Receiver **identifies and corrects** bit errors without retransmission (using redundant bits)

**Half-duplex and Full-duplex**:
- **Half-duplex**: both ends can transmit, but not simultaneously (one at a time)
- **Full-duplex**: simultaneous bidirectional transmission

---

## 5.2 Error Detection and Correction Techniques

### Why Error Detection?
- Physical media introduces **bit errors** (a 0 becomes 1 or vice versa) due to signal attenuation, electromagnetic noise, etc.
- Error detection adds **redundancy** (extra bits) so the receiver can detect (and possibly correct) errors
- Error detection is **not 100% reliable** — some undetected errors possible (but rare)

### Three Main Techniques

---

#### 1. Parity Checks

**Single-Bit Parity**:
- Add **one parity bit** to the data
- **Even parity**: set parity bit so the total number of 1s (data + parity) is even
- **Odd parity**: total number of 1s is odd
- Receiver counts 1s; if parity doesn't match → error detected
- **Detects only 1-bit errors** — misses 2-bit errors (or any even number of errors)

**Two-Dimensional Bit Parity**:
- Arrange data bits in a **2D matrix** (rows and columns)
- Compute parity bit for each **row** AND each **column**
- Transmit data + all parity bits
- Receiver recomputes row and column parities and checks
- **Can detect AND correct** single-bit errors (intersection of bad row and bad column identifies the flipped bit)
- Can detect (but not correct) most multi-bit errors

---

#### 2. Internet Checksum

Used in the **transport and network layers** (TCP, UDP, IP headers).

**How it works**:
- Treat the segment as a sequence of **16-bit integers**
- Sum all integers using **1's complement arithmetic**
  - Add normally; any carry out of the top bit is wrapped around and added to the result
- Take the 1's complement of the sum → this is the checksum
- Receiver: sum all 16-bit words (including checksum); if result = all 1s → no error; if any 0 → error

**Why used at transport layer too?** Link-layer error detection only covers one link — the Internet checksum catches errors that may occur in router memory between links.

---

#### 3. Cyclic Redundancy Check (CRC)

The most powerful and widely used error detection method (used in Ethernet, 802.11 WiFi, USB).

**Concept**:
- Treat data D as a binary number
- Sender and receiver agree on a **generator polynomial G** (a binary number of r+1 bits)
- Sender computes r **CRC bits (R)** and appends them to D → transmits \<D, R\>
- The key property: \<D, R\> is exactly divisible by G (mod 2 arithmetic)
- Receiver divides the received bits by G; if **remainder = 0** → no error; if remainder ≠ 0 → error

**How sender computes CRC bits R**:
1. Take data D, append r zeros → call it D × 2^r
2. Divide D × 2^r by G using **mod-2 arithmetic** (XOR, no carries/borrows)
3. The **remainder** of this division = R (the CRC bits)
4. Transmit \<D, R\>

**Mod-2 arithmetic**: addition and subtraction are both just **XOR** (no carrying)

**Generator polynomial notation**:
- G = x^4 + x + 1 means the binary number 10011 (4+1 = 5 bits for 4-bit CRC)
- x^k represents a 1 in bit position k

**What CRC can detect**:
- All single-bit errors
- All double-bit errors
- All odd numbers of errors
- All burst errors of length ≤ r bits

---

## 5.3 Multiple Access Protocols

### The Problem
In a **broadcast channel** (shared medium), multiple nodes transmit simultaneously → their signals **collide** → garbled, unreadable data.

**Multiple access protocol**: a distributed algorithm that determines how nodes share the channel (who transmits when).

### Ideal Multiple Access Protocol
For a channel of rate R bps:
- When one node wants to transmit: it gets rate R
- When M nodes want to transmit: each gets average rate R/M
- Fully decentralized (no special master node)
- Simple to implement

### MAC Protocols Taxonomy

Three broad classes:

#### Channel Partitioning Protocols
Divide the channel into pieces — each node gets a dedicated piece.

**TDMA (Time Division Multiple Access)**:
- Time divided into frames → each frame divided into slots
- Each node gets one slot per frame
- If a node has nothing to send, its slot goes idle (wasted)

**FDMA (Frequency Division Multiple Access)**:
- Channel divided into frequency bands
- Each node assigned a fixed frequency band
- Idle bands wasted

**Advantage**: no collisions, guaranteed rate
**Disadvantage**: bandwidth wasted when nodes are idle

#### Random Access Protocols
No coordination — nodes transmit whenever they want. Collisions happen; they are dealt with.

Key protocols (in order of sophistication):

**Pure ALOHA** (earliest):
- Transmit immediately when frame arrives
- Collision → wait random time → retransmit
- Low efficiency (~18%)

**Slotted ALOHA**:
- Time divided into slots of one frame
- Nodes transmit only at start of a slot
- Collision → each node retransmits in a future slot with probability p
- Max efficiency ~37%

**CSMA (Carrier Sense Multiple Access)**:
- **Listen before you transmit**: if channel is idle → transmit; if busy → wait
- Reduces collisions but doesn't eliminate them (propagation delay means two nodes may both sense idle and transmit simultaneously)

**CSMA/CD (Collision Detection)** — used in Ethernet:
- CSMA + **detect collision while transmitting**
- If collision detected: abort transmission immediately (jam signal), wait a **random backoff time**, retry
- **Binary exponential backoff**: after nth collision, choose random wait time from {0, 1, ..., 2^n − 1} × slot time
  - More collisions = longer wait (backs off more)
- Collision detection is **easy on wired** (compare transmitted and received signal), **hard on wireless** (can't hear while transmitting due to signal strength differences)

**CSMA/CA (Collision Avoidance)** — used in 802.11 WiFi:
- Can't detect collisions (wireless), so try to **avoid** them
- If channel idle for DIFS time → transmit
- If channel busy → wait until idle, then start random backoff timer (countdown while idle)
- When timer reaches 0 → transmit
- ACK required to confirm delivery (unlike wired Ethernet)
- Backoff timer pauses when channel is busy, resumes when idle

#### Taking Turns Protocols
Combine benefits of partitioning (no waste at high load) and random access (efficient at low load).

**Polling**: master node "polls" each node in turn — "do you have data?" Overhead + master failure = single point of failure.

**Token passing**: a token circulates; a node can transmit only when it holds the token. Token overhead + token loss = problem.

---

## 5.4 Switched LAN

### Link-Layer Addressing and ARP

#### MAC Addresses
- Also called **LAN address**, **physical address**, or **Ethernet address**
- **48 bits** long (6 bytes), expressed in hex: e.g., `1A-23-F9-CD-06-9B`
- Burned into the **NIC ROM** by the manufacturer (also sometimes software-settable)
- **Flat structure**: no hierarchy (unlike IP addresses which have network + host parts)
- **Portable**: a device's MAC address doesn't change when it moves to a different network (unlike IP)

**MAC address allocation**: administered by IEEE; manufacturers buy a block of addresses (first 3 bytes = OUI — manufacturer identifier)

**MAC vs IP address analogy**:
- MAC = like your Social Security Number (permanent, attached to you)
- IP = like your postal address (changes when you move)

#### ARP — Address Resolution Protocol

**Problem**: within a subnet, when host A wants to send a frame to host B, it knows B's IP address (from DNS) but needs B's **MAC address** to construct the link-layer frame.

**ARP Solution**:
- Each node maintains an **ARP table**: maps IP addresses to MAC addresses, with TTL
- ARP table format: `< IP address ; MAC address ; TTL >`

**ARP Process**:
1. A wants to send to B but doesn't have B's MAC in its ARP table
2. A broadcasts an **ARP query** frame to all nodes on the LAN (dest MAC = FF:FF:FF:FF:FF:FF)
   - "Who has IP address X.X.X.X?"
3. All nodes receive the query; **only B** (with IP X.X.X.X) sends an **ARP reply** (unicast to A)
   - "My MAC address is YY:YY:YY:YY:YY:YY"
4. A stores B's MAC in its ARP table (with TTL)
5. A constructs the frame with B's MAC and sends it

**ARP across subnets** (routing):
- When sending to a different subnet, A sends to the **router's MAC** (not the destination's MAC)
- The router then looks up the destination in its routing table and forwards to the next hop

---

### Ethernet

Ethernet has dominated wired LAN technology for 40+ years, defeating competitors like Token Ring, FDDI, and ATM.

#### Physical Topology
- **Old (bus)**: all nodes share a single coaxial cable — one collision domain
- **Modern (star)**: nodes connect via separate cables to a **central switch** — no collisions between different nodes

#### Ethernet Frame Structure

| Field | Size | Description |
|---|---|---|
| Preamble | 7 bytes | 10101010... — synchronizes clocks |
| Start Frame Delimiter | 1 byte | 10101011 — marks start of frame |
| Destination MAC | 6 bytes | MAC address of destination |
| Source MAC | 6 bytes | MAC address of sender |
| Type | 2 bytes | Identifies upper-layer protocol (0x0800=IPv4, 0x86DD=IPv6, 0x0806=ARP) |
| Data (payload) | 46–1500 bytes | The IP datagram; padded to minimum 46 bytes |
| CRC | 4 bytes | Error detection |

#### Ethernet: Unreliable, Connectionless
- **Connectionless**: no handshaking between sender and receiver NICs
- **Unreliable**: receiving NIC doesn't send ACKs or NAKs
  - If CRC fails → frame dropped silently
  - Higher layers (TCP) handle recovery
- **MAC protocol**: unslotted CSMA/CD with **binary exponential backoff**

#### Ethernet CSMA/CD Algorithm
1. NIC receives datagram from network layer
2. If channel idle: start transmitting; if busy: wait until idle then transmit
3. While transmitting: monitor for collision
4. If collision detected: abort transmission, send **jam signal** (48 bits) to notify all nodes
5. Enter **binary exponential backoff**:
   - After m-th collision: choose K randomly from {0, 1, ..., 2^m − 1}
   - Wait K × 512 bit times, then return to step 2
6. If transmitted successfully: done

#### Ethernet Standards
- 802.3 covers many physical-layer variants: 10BASE-T, 100BASE-TX, 1000BASE-T (Gigabit), 10GBASE-T
- Different physical media: twisted pair (copper), fiber optic
- All use the same frame format, MAC protocol

---

### Link-Layer Switches

#### What Switches Do
- Receive incoming frames and **forward** them to the correct output port
- **Transparent**: hosts don't know switches exist (plug-and-play)
- **Full-duplex**: each node has a dedicated connection — no collisions
- Connect multiple LAN segments

#### Switch Table (MAC Table)
Each switch maintains a table mapping **MAC addresses → port number** (with TTL).

**Self-Learning**:
- When a frame arrives on port X from source MAC address A:
  - Switch **records**: MAC A is reachable via port X (adds to switch table)
- Switch table entries expire after TTL

**Forwarding and Filtering**:
- Frame arrives with destination MAC D:
  - If D is in switch table → forward only to the recorded port (not all ports)
  - If D is **not** in switch table → **flood** (forward to all ports except the incoming port)
  - If D's port = incoming port → **drop** (filter — no need to forward)
- This is called **selective forwarding** — reduces unnecessary traffic

**Multi-switch self-learning**: works exactly the same — switches learn MAC addresses of devices in other parts of the network through normal traffic

#### Switches vs. Routers

| | Switch | Router |
|---|---|---|
| Layer | Data Link (Layer 2) | Network (Layer 3) |
| Address type | MAC address | IP address |
| Broadcast domain | One per switch | Breaks up broadcast domains |
| Topology | Spanning tree (loop prevention) | Any topology with routing protocols |
| Plug-and-play | Yes | Configuration needed |
| Typical use | Within a LAN | Between networks |

---

## 5.5 Retrospective: A Day in the Life of a Web Page Request

This ties together all layers — follow a web page request from start to finish.

**Scenario**: Student connects laptop to campus network and requests www.google.com.

### Step 1: DHCP — Getting Connected
- Laptop broadcasts **DHCP Discover** → encapsulated in UDP → IP → Ethernet (broadcast frame)
- Campus router (with DHCP server) receives it → sends **DHCP Offer** with IP address, subnet mask, gateway IP, DNS server IP
- Laptop sends **DHCP Request** → router sends **DHCP ACK**
- Laptop now has: its IP, subnet mask, router (gateway) IP, DNS server IP

### Step 2: ARP — Getting the Router's MAC Address
- Laptop wants to send to DNS server (outside subnet) → must go through the gateway router
- Laptop doesn't know router's MAC → sends **ARP query** (broadcast)
- Router replies with its MAC address
- Laptop stores router's MAC in ARP table

### Step 3: DNS — Resolving google.com
- Laptop creates DNS query for www.google.com
- Sends UDP packet → to DNS server (its IP from DHCP)
- DNS query frame: dest MAC = router MAC (it's outside the subnet)
- Packet routed through campus network → Comcast → DNS server
- DNS server replies with IP address of www.google.com
- DNS response returns all the way back to laptop

### Step 4: TCP Connection — 3-Way Handshake
- Laptop sends **SYN** segment to www.google.com (now known IP)
- Packet routed across the Internet to Google's servers
- Google replies with **SYNACK**
- Laptop replies with **ACK** → TCP connection established

### Step 5: HTTP Request and Reply
- Laptop sends **HTTP GET** request through TCP socket
- Packet routed to Google's web server
- Google server returns **HTTP 200 OK** with HTML content
- Laptop browser renders the page

**This walkthrough shows every layer working together**:
- DHCP (application layer) → assigned IP
- ARP (link layer) → found MAC addresses
- DNS (application layer) → resolved hostname
- TCP (transport layer) → reliable connection
- HTTP (application layer) → web content
- IP (network layer) → routing across networks
- Ethernet/WiFi (link layer) → local forwarding
- Physical layer → bits on the wire

---

## 5.6 Physical Layer

### Purpose
The physical layer is responsible for:
1. **Encoding** binary digits (from the link layer frame) into **signals**
2. **Transmitting** those signals over the physical medium
3. **Receiving** and decoding incoming signals back into bits

### Physical Medium
The physical medium carries signals in the form of:
- **Voltage** (copper wire)
- **Light** (fiber optic)
- **Radio waves** (wireless)

### Signal Types
- **Analog signal**: continuous-valued (varying amplitude, frequency) — used in older telephone systems
- **Digital signal**: discrete-valued (0s and 1s) — used in modern digital communications

### Physical Layer Services (What it provides)
1. **Physical components**: connectors, cables, NICs, transceivers
2. **Encoding**: how 0s and 1s are represented as signal values
3. **Signaling**: how the signal is transmitted over the medium

### Physical Layer Devices
- **Hub**: broadcasts signal to all ports (Layer 1)
- **Repeater**: regenerates/amplifies signal (Layer 1)
- **Modem**: modulates/demodulates (Layer 1)
- **Cables**: physical medium
- **Network Adapters (NICs)**: interface between device and medium

### Signaling Methods

**NRZ (Non Return to Zero)**:
- Low voltage = **0**; High voltage = **1**
- Simple, but has problems with long runs of the same bit (clock synchronization issues)

**Manchester Encoding**:
- A transition from **low to high** within a bit period = **1**
- A transition from **high to low** within a bit period = **0**
- Every bit has a transition → self-clocking (receiver can synchronize)
- Used in early Ethernet (10BASE-T)

### Physical Layer Standards Bodies
- **ISO**: International Organization for Standardization
- **IEEE**: Institute of Electrical and Electronics Engineers (defines 802.x standards)
- **ANSI**: American National Standards Institute
- **ITU**: International Telecommunication Union
- **EIA/TIA**: Electronics Industry Alliance / Telecommunications Industry Association
- **FCC**: Federal Communications Commission (US, regulates radio spectrum)

---

## 5.7 Wireless LANs: IEEE 802.11 (WiFi)

### Wireless Network Characteristics
- Wireless hosts communicate via **radio waves** — no physical cable
- **Wireless ≠ mobility**: a desktop computer with WiFi is wireless but not mobile
- **Higher error rates** than wired (interference, multipath propagation, attenuation)
- **Half-duplex** by default (can't transmit and detect collisions simultaneously)

### Types of Wireless Networks

**Infrastructure mode** (most common):
- Hosts connect to a **Base Station (Access Point — AP)**
- AP connects to the wired network (or Internet)
- Hosts relay all traffic through the AP

**Ad-hoc mode**:
- No AP; hosts communicate directly peer-to-peer
- Self-organizing network

### 802.11 Standards Family

| Standard | Common Name | Max Rate | Frequency |
|---|---|---|---|
| 802.11b | WiFi 1 | 11 Mbps | 2.4 GHz |
| 802.11g | WiFi 3 | 54 Mbps | 2.4 GHz |
| 802.11n | WiFi 4 | 450+ Mbps | 2.4/5 GHz |
| 802.11ac | WiFi 5 | ~1 Gbps+ | 5 GHz |
| 802.11ax | WiFi 6 | ~10 Gbps+ | 2.4/5/6 GHz |
| 802.11af | White-Fi | Varies | TV white spaces |
| 802.11ah | — | Low power | Sub-1 GHz |

**All 802.11 variants use CSMA/CA** for multiple access.

### 802.11 LAN Architecture

**BSS (Basic Service Set)**: the fundamental building block
- One **Access Point (AP)** + associated wireless hosts
- Each BSS has an **SSID** (Service Set Identifier — the network name you see when scanning for WiFi)

**AP functions**:
- Relay frames between wireless hosts and the wired network
- Manage association with hosts

### Association Process

Before a host can communicate, it must **associate** with an AP:

1. **Passive scanning**: AP periodically broadcasts **beacon frames** containing SSID and MAC address; host listens and selects an AP
2. **Active scanning**: host broadcasts a **Probe Request** on all channels; APs reply with Probe Response; host selects and associates

**Association steps**:
1. Host sends **Association Request** to chosen AP
2. AP replies with **Association Response**
3. If security is required: authentication exchange (WPA2, WPA3)
4. After association: host is "connected" — frames go through this AP

### 802.11 CSMA/CA — Avoiding Collisions

**Why collision avoidance instead of detection?**
- A sender cannot detect a collision while transmitting on wireless (the transmitted signal is much stronger than any received signal, drowning out collisions)
- Hidden terminal problem: node A and node C can't hear each other but both can hear B — A and C may transmit simultaneously to B, causing a collision at B that neither A nor C detects

**CSMA/CA operation**:
1. If channel idle for **DIFS** (Distributed Inter-Frame Space) time → transmit
2. If channel busy → wait until idle, then start a **random backoff timer**
3. Count down the timer only while the channel is idle; pause when busy
4. When timer hits 0 → transmit
5. If no ACK received → assume collision → double backoff interval → retry

**ACK required**: unlike wired Ethernet, 802.11 requires the receiver to send an **ACK** after successfully receiving each frame. If no ACK is received within a timeout → retransmit.

**Why ACK?** High wireless error rates mean the sender needs confirmation; link-layer reliability is provided directly.

### 802.11 Frame Structure

Main fields:
- **Frame control**: type (management/control/data), subtype, flags
- **Duration**: how long the channel will be busy (used by other nodes to set their NAV — network allocation vector)
- **Address 1**: MAC of receiver (AP or host)
- **Address 2**: MAC of transmitter
- **Address 3**: MAC of router (destination in wired network) — 802.11 uses 3 MAC addresses!
- **Sequence control**: for fragmentation and duplicate detection
- **Address 4**: used in ad-hoc mode
- **Payload**: IP datagram
- **CRC**: error detection

---

*End of Complete Notes*