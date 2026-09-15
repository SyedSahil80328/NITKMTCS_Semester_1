### **Paper 1: Network Edge Security Monitoring System Based on Embedded System and Bi-LSTM**

#### **1. Core Problem & Objective**
* **The Problem:** Smart IoT devices generate massive amounts of network data. Traditional security systems rely on sending all data to a centralized cloud server for analysis. This causes severe network bottlenecks, high latency, and security vulnerabilities.
* **The Goal:** Detect cyber attacks and anomalous device behavior locally at the edge in real time, with high accuracy and low power consumption.

#### **2. Technical Solution**
* **Embedded Deployment:** The system runs a **Bidirectional Long Short-Term Memory (Bi-LSTM)** deep learning model directly on low-power embedded processors.
* **Temporal Pattern Analysis:** Bi-LSTM is specifically designed for sequential data; it analyzes traffic flows forward and backward in time to identify complex threat patterns that traditional rule-based filters miss.

#### **3. Key Findings & Performance Metrics**
* **Data Tested:** Evaluated on over **100 GB** of real-world network traffic from smart routers and IoT sensors.
* **Detection Accuracy:** Reached **96.8% accuracy**, outperforming traditional algorithms like Random Forest (**92.6%**) and Support Vector Machines (**91.3%**). Overall accuracy improved by **12%** compared to existing traditional systems, while reducing false alarms by **20%**.
* **Real-Time Speed:** Achieved an average response latency of **184 ms** (well within the **200 ms** real-time threshold) and processed roughly **5,000 records per second**.
* **Power Consumption:** Averaged **5.8 W**, making it suitable for continuously powered edge devices.

#### **4. Real-World Analogy**
* **Airport Security Checkpoint:** Imagine sending every traveler’s baggage to a police headquarters in another city to be scanned before letting them board a plane (centralized cloud security). It would create huge queues and delays. Paper 1 places an intelligent AI baggage scanner right at the local gate (embedded Bi-LSTM at the edge). It scans incoming travelers in sequence, detects illegal items in less than a second, and consumes very little electricity.

#### **5. Concrete Practical Example**
* A hacker attempts a distributed denial-of-service (DDoS) attack on a smart router by sending subtle, repeated packets. Instead of waiting for a remote cloud server to flag the attack seconds later, the local embedded processor analyzes the incoming traffic stream, flags the anomaly in **184 milliseconds**, and blocks the offending IP address locally.

---

### **Paper 2: Optimal Task Allocation and Coding Design for Secure Edge Computing**

#### **1. Core Problem & Objective**
* **The Problem:** Edge devices are **heterogeneous** (they have varying CPU, memory, and battery capabilities) and often **untrustworthy** (vulnerable to physical or digital tampering). 
* **The Goal:** Perform complex parallel computations across multiple edge devices efficiently without exposing sensitive data to untrusted nodes.

#### **2. Technical Solution**
* **Coded Distributed Computing:** Focuses on **matrix multiplication** (the fundamental building block of AI algorithms).
* **Joint Optimization Framework:** Solves two interconnected problems simultaneously:
  1. **Task Allocation:** Dynamically calculates how many computational blocks to assign to each device based on its specific hardware capacity.
  2. **Linear Code Design:** Encodes raw data with random secret vectors before sending it to devices.
* **Security & Flexibility:** Provides **information-theoretic security**, ensuring individual devices cannot reconstruct the underlying raw data even if compromised. Supports both redundant and non-redundant computational setups.

#### **3. Real-World Analogy**
* **Shredded Financial Records:** A manager needs to calculate company profits across a team of freelance accountants who cannot be fully trusted with confidential numbers. The manager cuts the financial ledgers into pieces, mixes the numbers with random mathematical noise (linear coding), and gives larger stacks to fast workers and smaller stacks to slower workers (task allocation). No individual accountant can read the true company figures from their piece alone, but when they send back their mathematical answers, the manager easily reconstructs the final profit total.

#### **4. Concrete Practical Example**
* A smart city grid needs to perform matrix operations across 10 devices (ranging from fast edge servers to slow streetlight sensors). The system assigns 80% of the mathematical workload to the fast server and 2% to each slow sensor. Because all data blocks are linearly encoded with random vectors, an attacker tapping into a sensor gets only random noise rather than private energy consumption data.

---

### **Paper 3: TMO – Time Domain Outsourcing Attribute-Based Encryption for Edge Data**

#### **1. Core Problem & Objective**
* **The Problem:** IoT environments collect sensitive user data, but resource-constrained edge devices struggle with heavy cryptographic encryption. Furthermore, permissions change rapidly based on time and user mobility.
* **The Goal:** Protect data privacy using flexible attribute-based access rules while offloading heavy cryptographic math to edge nodes without compromising security.

#### **2. Technical Solution**
* **Time-Domain Integration:** Embeds time parameters directly into the encryption algorithm so data access automatically expires after a designated time window.
* **Multi-Authority CP-ABE:** Uses **Ciphertext-Policy Attribute-Based Encryption** with multiple trust authorities to eliminate single points of failure.
* **Computation Outsourcing:** Delegating complex mathematical encryption and decryption tasks to nearby edge servers relieves low-power IoT sensors.
* **Dynamic Policy Updates:** Allows administrators to modify access permissions online without consuming excessive network bandwidth.

#### **3. Real-World Analogy**
* **Time-Gated Bank Vault with Receptionist:** Imagine a bank vault that only opens for officers with "Manager" badges, and only between 9:00 AM and 11:00 AM. Opening the heavy vault door takes enormous physical effort. Instead of forcing the manager to push the heavy door, a powerful mechanical receptionist at the front desk handles the physical push (outsourced computation to the edge). Once 11:01 AM arrives, the key code automatically stops working (time-domain security).

#### **4. Concrete Practical Example**
* A patient wears a heart-monitoring sensor that logs vital signs. The patient sets an access policy: *"Only accredited cardiologists can view my heart data during my hospital visit from 8:00 AM to 12:00 PM today."* The heavy mathematical encryption is executed by the hospital's edge gateway rather than the patient's small wearable battery, preserving device lifespan.

---

### **Paper 4: Blockchain for Secure Data Sharing in Vehicular Edge Networks (VECONs)**

#### **1. Core Problem & Objective**
* **The Problem:** Connected vehicles share real-time road and traffic data through Roadside Units (RSUs). However, RSUs and neighboring vehicles are not fully trustworthy—malicious actors can share false hazard warnings or re-share private data without authorization.
* **The Goal:** Ensure authentic, tamper-proof, and high-quality data sharing between vehicles while detecting and isolating malicious drivers.

#### **2. Technical Solution**
* **Consortium Blockchain & Smart Contracts:** Creates a decentralized digital ledger across trusted roadside nodes, preventing unauthorized second-hand data resale and tampering.
* **Three-Weight Subjective Logic (TWSL) Reputation Model:** Dynamically calculates a trust/reputation score for every vehicle by analyzing three metrics:
  1. **Interaction Frequency:** How often the vehicle communicates reliably.
  2. **Event Timeliness:** How fresh and relevant the reported data is.
  3. **Trajectory Similarity:** Whether the vehicle was physically located on the road segment it reported on.

#### **3. Key Findings & Performance Metrics**
* Numerical evaluations using real vehicular datasets proved that the **TWSL model significantly improves the detection rate of rogue/malicious vehicles** compared to conventional reputation models.

#### **4. Real-World Analogy**
* **Community Traffic Chatroom:** Imagine a highway drivers' group chat where people post warnings about traffic accidents. To stop fake warning posts, every post is logged on a shared, un-editable bulletin board (consortium blockchain). A smart system checks if the reporting driver was actually on that road segment at that exact time (trajectory & timeliness). Drivers who post verified warnings earn high reputation stars, while liar accounts are flagged and muted.

#### **5. Concrete Practical Example**
* Vehicle A broadcasts an alert about black ice on Highway 101. Before Vehicle B adjusts its automated brakes, the onboard edge node checks Vehicle A’s reputation score via smart contracts. The system confirms Vehicle A was driving on Highway 101 two minutes ago (trajectory similarity & timeliness) and accepts the warning.

---

### **Paper 5: P2P Knowledge Market for Edge-AI Enabled IoT**

#### **1. Core Problem & Objective**
* **The Problem:** Edge-AI devices collect local data and train machine learning models (creating "knowledge slices"). Devices belong to independent, selfish owners who have no incentive to share their trained models for free. Existing studies focus only on model generation, not monetization.
* **The Goal:** Create a secure, automated peer-to-peer (P2P) marketplace where Edge-AI devices can trade trained AI knowledge slices for money.

#### **2. Technical Solution**
* **Knowledge Consortium Blockchain:** Manages model transactions securely via smart contracts and a custom cryptocurrency named **Knowledge Coin (KC)**.
* **Proof of Trading (PoT):** Replaces energy-intensive mining with a lightweight, green consensus mechanism designed for resource-constrained edge hardware.
* **Game-Theoretic Pricing Strategy:** Uses a non-cooperative game theory model to set fair prices, guaranteeing that sellers earn higher profits when they train higher-quality AI models using larger datasets.

#### **3. Real-World Analogy**
* **Farmers' Market for Recipes:** Farmers independently invent secret recipes for organic pest control (trained AI models). Rather than keeping these recipes secret, a local farmers' market allows them to sell their recipes using specialized market tokens (Knowledge Coin). A digital registry (blockchain) logs ownership, and a smart pricing rule ensures that farmers who put more labor into testing their recipes can charge higher prices.

#### **4. Concrete Practical Example**
* An autonomous agricultural drone trains a machine learning model to recognize grape leaf disease. A neighboring farm's drone wants to identify the disease without spending weeks gathering training images. It buys the trained model slice directly from the first drone over the knowledge blockchain, paying 50 Knowledge Coins.

---

### **Paper 6: EdgeSec – Edge Layer Security Service to Enhance IoT Security**

#### **1. Core Problem & Objective**
* **The Problem:** The Internet of Things is vast, highly diverse (heterogeneous), and made of tiny, resource-constrained devices with weak built-in security.
* **The Goal:** Provide a comprehensive, centralized security protection layer located at the edge (between IoT devices and the internet).

#### **2. Technical Solution**
* **Modular Architecture:** EdgeSec consists of **seven major functional components** working together at the edge layer to monitor, authenticate, inspect, and protect IoT traffic.
* **Deployment Validation:** Tested in a **Smart Home** ecosystem to defend against common device exploits.
* **Future Extension Plans:** The authors plan to implement EdgeSec using **Software Defined Networking (SDN)** and **Virtualization**, introduce lightweight cryptographic algorithms, and organize edge nodes into secure collaborative layers.

#### **3. Real-World Analogy**
* **Gated Community Guardhouse:** Imagine a neighborhood where individual house front doors have flimsy locks (cheap IoT devices like smart lightbulbs or smart plugs). Instead of replacing every lock on every lightbulb, the neighborhood builds a gated entry guardhouse (EdgeSec) equipped with 7 specialized security officers (firewall, identity verification, packet scanner, etc.). Every person or delivery entering or leaving the neighborhood must pass through this main guardhouse.

#### **4. Concrete Practical Example**
* A homeowner installs cheap smart lightbulbs and IP cameras. An external hacker attempts to exploit a known vulnerability in the camera's firmware. The **EdgeSec** service running on the home's central edge router intercepts the malicious network packets via its inspection components, blocks the intrusion, and isolates the vulnerable camera before it can infect the rest of the home network.

---

### **Summary Comparison Table**

| Paper | Core Technology | Primary Focus | Key Advantage |
| :--- | :--- | :--- | :--- |
| **Paper 1** | Embedded Bi-LSTM Neural Network | Edge Intrusion Detection | **96.8% accuracy**, <200ms latency, 5.8W power |
| **Paper 2** | Coded Distributed Computing | Secure Task Allocation | Information-theoretic security across untrusted nodes |
| **Paper 3** | Time-Domain CP-ABE | Dynamic Data Access Control | Outsourced computation with time-expiring permissions |
| **Paper 4** | Consortium Blockchain & TWSL | Vehicular Data Sharing | Detects rogue vehicles using trajectory & timeliness metrics |
| **Paper 5** | Blockchain & Proof of Trading | P2P AI Knowledge Market | Monetizes AI models using Knowledge Coins & game theory |
| **Paper 6** | 7-Component EdgeSec Layer | IoT System Security | Comprehensive edge security framework for smart homes |