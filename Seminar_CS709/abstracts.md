# Design and Research of Network Edge Device Security Monitoring System Based on Embedded System and Bi-LSTM
## Abstract
With the popularization of smart devices and networked devices, edge device
security issues have become increasingly prominent. Traditional security
monitoring systems often rely on centralized data processing mode, which
is difficult to meet the current real-time analysis requirements of massive
data. In order to solve this problem, this paper designs a network edge device
security monitoring system based on the fusion of embedded system and
bidirectional long-short-term memory network. By deploying the Bi-LSTM
model through the embedded processor, the system can detect the abnor-
mal behavior of edge devices in real time, thereby improving the response
speed and accuracy of security monitoring. This paper conducts experimental
analysis on the actual network traffic data set, collects security data from
different types of edge devices, covering device types including smart routers,
IoT sensors, etc., and processes more than 100GB of network traffic data
in total. The experimental results show that the detection accuracy of the
Bi-LSTM model in network attack behavior reaches 96.8%, which is about 4.2% and 5.5% higher than the traditional random forest and support vector
machine models respectively. In addition, the real-time analysis of the system
shows that the average processing latency of the embedded system is less
than 200 ms, which meets the low latency requirement in edge computing
environment.

**Keywords:** Edge computing, network security monitoring, embedded sys-
tems, bidirectional long-short-term memory network

## Conclusion
An edge device security monitoring system integrating embedded systems
and Bi-LSTM is designed to significantly improve security and cope with the
bottlenecks faced by traditional centralized architectures in large-scale real-
time data processing. This system cleverly combines embedded systems’ low
energy consumption characteristics and the advantages of distributed com-
puting. It uses the robust performance of the Bi-LSTM network in processing
sequence data, aiming to achieve efficient and accurate network intrusion
identification. This innovative integration not only enhances the system’s
response speed and energy efficiency ratio but also effectively reduces the
dependence on the central server, thereby building a more flexible, reliable
and secure edge computing environment.

A comparative analysis was conducted between the designed system and
the existing edge device security monitoring system. The existing systems
mainly rely on rule-based detection methods or traditional machine learning
algorithms, which are susceptible to complex attacks and unknown threats,
and have low accuracy and real-time performance. In contrast, the monitoring
system based on Bi-LSTM proposed in this article effectively captures the
complex behavior patterns of IoT devices through deep learning models,
accurately identifies various security threats, and ensures real-time perfor-
mance and energy efficiency through hardware optimization and low-power
design of embedded systems. The experimental results show that the designed
system has improved accuracy by about 12% compared to traditional systems,
reaching 94%, and reduced false alarm rate by 20%. The conclusion is that
the design combining Bi-LSTM model with embedded systems significantly
improves the security of edge devices and provides a feasible solution for
intelligent security monitoring in IoT environments.

The experiment uses over 100GB of actual data sets from edge devices
such as intelligent routers and IoT sensors, focusing on diverse cyber-attacks.
In order to meet this data processing requirement, this paper mainly con-
structs a Bi-LSTM model, which aims to deeply analyze the sequence
characteristics of network traffic and accurately identify abnormal behaviors. The experimental results show that the detection accuracy of the system based
on Bi-LSTM reaches 96.8%, far exceeding the performance of traditional
methods such as random forest (92.6%) and support vector machine (SVM)
(91.3%). This evidence clearly shows that the Bi-LSTM network can effec-
tively capture and deal with complex dependencies when solving security
problems involving time series, thus showing its significant advantages in
accuracy.

In addition to analyzing the detection accuracy, this paper also considers
the system’s real-time performance. Given the low-latency operation of edge
devices, embedded system performance is critical. Experiments show that
the average response time of the embedded Bi-LSTM system is 184 ms,
which meets the real-time processing requirement of 200 ms and reflects
the time-sensitive characteristics of edge computing. The system processes
about 5,000 network traffic records per second with high data volume,
demonstrating efficient processing capabilities.

The design focuses on improving energy efficiency. The test results
show that the average power consumption is 5.8 W, suitable for long-term
low-power environment operation. Compared with traditional server-side
monitoring systems, the embedded design significantly reduces total energy
consumption and data transmission latency and cost.

The designed embedded system integrates a Bi-LSTM network for edge
device security monitoring, significantly improving detection accuracy, real-
time performance and energy efficiency and introducing innovative strategies
for edge computing network security protection. This system aims to enhance
the security of IoT devices and promote future edge security monitoring
technology development.

# Optimal Task Allocation and Coding Design for Secure Edge Computing With Heterogeneous Edge Devices
## Abstract
In recent years, edge computing has attracted significant attention because it can effectively support many delay-sensitive
applications. Despite such a salient feature, edge computing also faces many challenges, especially for efficiency and security,
because edge devices are usually heterogeneous and may be untrustworthy. To address these challenges, we propose a unified
framework to provide efficiency and confidentiality by coded distributed computing. Within the proposed framework, we use matrix
multiplication, a fundamental building block of many distributed machine learning algorithms, as the representative computation task.
To minimize resource consumption while achieving information-theoretic security, we investigate two highly-coupled problems, (1) task
allocation that assigns data blocks in a computing task to edge devices and (2) linear code design that generates data blocks by
encoding the original data with random information. Specifically, we first theoretically analyze the necessary conditions for the optimal
solution. Based on the theoretical analysis, we develop an efficient task allocation algorithm to obtain a set of selected edge devices
and the number of coded vectors allocated to them. Using the task allocation results, we then design secure coded computing
schemes, for two cases, (1) with redundant computation and (2) without redundant computation, all of which satisfy the availability and
security conditions. Moreover, we also theoretically analyze the optimization of the proposed scheme. Finally, we conduct extensive
simulation experiments to demonstrate the effectiveness of the proposed schemes.

**Index Terms** — Edge computing, efficiency, confidentiality, coded computing, task allocation, linear coding, optimization

## Conclusion
In this paper, we have investigated a secure coded comput-
ing problem in heterogeneous edge computing, with the
objective to minimize the total resource usage, by jointly study-
ing the task allocation that assigns data blocks in a computing
task to edge devices, and the linear code design that generates
data blocks by encoding the original data with random infor-
mation. Specifically, we first theoretically analyzed the nec-
essary conditions for the optimal solution. Based on the
theoretical analysis, we developed an efficient task allocation
algorithm to obtain a set of selected edge devices and the
number of coded vectors allocated to them. Using the task
allocation results, we designed two secure coded computing
schemes for both the case with redundant computation and
the case without redundant computation, and we further proved the feasibility and the optimality of these schemes.
Finally, we conducted extensive simulation experiments that
demonstrate the effectiveness of the proposed schemes. In
the future, we will implement the proposed MCSCEC
scheme in real edge computing systems and study a more
general case that edge devices can attack cooperatively.

# TMO: Time Domain Outsourcing Attribute-Based Encryption Scheme for Data Acquisition in Edge Computing
## Abstract
With the rapid development of the Internet of Things and the ever-increasing demands
of advanced services and applications, edge computing is proposed to move the computing and storage
resources near the data source, which improves the response time and saves the bandwidth. However, due
to the limited available resources and massive privacy-sensitive user data in edge nodes, there are huge
challenges in data security and privacy protection in the edge computing environment. Hence, we propose
an efficient time-domain multi-authority outsourcing attribute-based encryption (ABE) scheme (TMO)
with a dynamic policy updating method for secure data acquisition and sharing in the edge computing.
Specifically, considering that the time is a crucial factor in many real-world application scenarios, we add
time-domain information in the encryption algorithm. Besides, to take full advantage of edge computing,
TMO extends the multi-authority ABE approach by outsourcing the computation to edge nodes to enhance
security and performance. Moreover, to tackle the mobility and frequently changing edge environment, TMO
also provides an efficient online policy updating method to manage attribute information and to access policy
with low overhead. The security analysis and the experimental results show that TMO can indeed efficiently
enhance data security with low overhead in the edge computing environment.

**INDEX TERMS** - Multi-authority, CP-ABE, time-based, security, edge computing.

## Conclusion
With the blooming of IoT and ever-increasing demands of
users, edge computing is proposed to leverage the computing
and storage resources on the edge to process the massive
data. With the benefit of reducing response time and saving
bandwidth, edge computing also encounters huge challenges
in security and privacy. Hence, in this paper, we proposed
TMO, a time domain multi-authority outsourcing attribute-
based encryption scheme, to enhance data security in the
edge computing environment. The proposed TMO takes time
as a key encryption factor to provide a flexible data acqui-
sition mechanism. Besides, edge nodes are used to support
multi-authority and outsourcing features, which can greatly
improve the security and reduce the costs. Moreover, an effi-
cient dynamic policy updating method is also developed,
which updates the access policy online without wasting the
network bandwidth. The security analysis and the compre-
hensive performance experimental results show that TMO
can indeed improve the data security with less overhead in
edge computing environment. In the future, we will explore
the usage of historical data accessible time range, it is helpful
to profile data users and predict data open possibilities. More-
over, we will improve TMO to support a large number of users and devices with more features in the edge environment.

# Blockchain for Secure and Efficient Data Sharing in Vehicular Edge Computing and Networks
### Abstract
The drastically increasing volume and the growing
trend on the types of data have brought in the possibility of real-
izing advanced applications such as enhanced driving safety, and
have enriched existing vehicular services through data sharing
among vehicles and data analysis. Due to limited resources with
vehicles, vehicular edge computing and networks (VECONs) i.e.,
the integration of mobile edge computing and vehicular networks,
can provide powerful computing and massive storage resources.
However, road side units that primarily presume the role of vehic-
ular edge computing servers cannot be fully trusted, which may
lead to serious security and privacy challenges for such inte-
grated platforms despite their promising potential and benefits.
We exploit consortium blockchain and smart contract technolo-
gies to achieve secure data storage and sharing in vehicular
edge networks. These technologies efficiently prevent data sharing
without authorization. In addition, we propose a reputation-based
data sharing scheme to ensure high-quality data sharing among
vehicles. A three-weight subjective logic model is utilized for
precisely managing reputation of the vehicles. Numerical results
based on a real dataset show that our schemes achieve reasonable
efficiency and high-level of security for data sharing in VECONs.

**Index Terms** — Blockchain, reputation management, security
and privacy, smart contracts, vehicular edge computing.

## Conclusion
In this paper, we have presented a secure P2P data shar-
ing system in vehicular computing and networks. We utilized consortium blockchain and smart contract technologies to
achieve secure and efficient data storage and data sharing.
These technologies efficiently prevent second-hand data shar-
ing without authorization. In addition, we have proposed a
reputation-based data sharing scheme with the TWSL model
considering interaction frequency, event timeliness, and tra-
jectory similarity. This scheme can achieve accurate reputation
management for high-quality data sharing among vehicles. The
vehicles can choose the optimal data providers with high-
quality data during sharing in VECONs. Security analysis
shows that our system ensures security of data storage and data
sharing. Numerical results indicate that the proposed TWSL
scheme has great advantages over the traditional reputation
schemes in improving detection rate of abnormal vehicles to
ensure security during data sharing.

# Making Knowledge Tradable in Edge-AI Enabled IoT: A Consortium Blockchain-Based Efficient and Incentive Approach
## Abstract
Nowadays, benefit from more powerful edge
computing devices and edge artificial intelligence (edge-
AI) could be introduced into Internet of Things (IoT) to find
the knowledge derived from massive sensory data, such
as cyber results or models of classification, and detection
and prediction from physical environments. Heterogeneous
edge-AI devices in IoT will generate isolated and distributed
knowledge slices, thus knowledge collaboration and ex-
change are required to complete complex tasks in IoT intel-
ligent applications with numerous selfish nodes. Therefore,
knowledge trading is needed for paid sharing in edge-AI
enabled IoT. Most existing works only focus on knowledge
generation rather than trading in IoT. To address this is-
sue, in this paper, we propose a peer-to-peer (P2P) knowl-
edge market to make knowledge tradable in edge-AI enabled
IoT. We first propose an implementation architecture of the
knowledge market. Moreover, we develop a knowledge con-
sortium blockchain for secure and efficient knowledge man-
agement and trading for the market, which includes a new
cryptographic currency knowledge coin, smart contracts,
and a new consensus mechanism proof of trading. Besides,
a noncooperative game based knowledge pricing strategy
with incentives for the market is also proposed. The security
analysis and performance simulation show the security and
efficiency of our knowledge market and incentive effects of
knowledge pricing strategy. To the best of our knowledge,
it is the first time to propose an efficient and incentive P2P
knowledge market in edge-AI enabled IoT.

**Index Terms** — Consortium blockchain, edge artificial in-
telligence (edge-AI), Internet of Things (IoT), knowledge
market, knowledge pricing, smart contract.

### Conclusion
In this paper, to break islands of knowledge and make knowl-
edge tradable in edge-AI enabled IoT, we proposed a P2P knowl-
edge market for knowledge paid sharing. We utilized blockchain
technologies (consortium blockchain/smart contract) to build a
knowledge blockchain to ensure security and efficiency of the
market. In addition, a green consensus mechanism PoT was pro-
posed for the knowledge blockchain, which is more applicable
at the edge of networks due to less resource consumption. More-
over, we proposed a noncooperative game based optimal knowl-
edge pricing strategy as incentives for the knowledge market.
We showed that the optimal pricing strategy could encourage
knowledge sellers to learn more data and provide higher qual-
ity knowledge for buyers in the market. Based on the proposed
knowledge market, some future works could be pursued. Knowl-
edge extracted by machine learning could be reproduced with almost no costs. Some buyers could buy KCs from sellers, dupli-
cate and resell knowledge to others. Thus, hierarchical market
models could be introduced, e.g., Stackelberg games. Besides,
the knowledge market is established upon the data/information
market, so a comprehensive market and more economic mod-
els should be discussed, which take both data/information and
knowledge trading into account.

# EdgeSec: Design of an Edge Layer Security Service to Enhance IoT Security
## Abstract 
With the widespread availability of connected smart
devices, Internet of Things (IoT) is becoming the world’s
largest computing platform. These large-scale, heterogeneous
and resource-constrained devices bring many significant new
challenges to the design of efficient and reliable IoT systems.
Security is one of the most crucial ones that need to be effectively
addressed for the wide adoption of IoT systems. In this paper, we
first present an in-depth analysis of security challenges in IoT.
Then, we propose EdgeSec, the design of a novel security service
which is deployed at the Edge layer to enhance the security of IoT
systems. EdgeSec consists of seven major components that work
together to systematically handle specific security challenges in
IoT systems. Finally, the effectiveness of EdgeSec is demonstrated
in the context of a typical IoT application, Smart Home.

**Index Terms** — Internet of Things, IoT, Security, Edge Comput-
ing, Smart Homes

## Conclusion and Future Work
Security is the biggest concern for IoT systems. It is very
difficult to address the security challenges of IoT systems
because of its new characteristics. In this paper, we first
analyze various challenges that make it difficult to secure IoT
systems. Then we design EdgeSec, an Edge layer security
service, which enhances IoT systems security. The seven major
components of EdgeSec are discussed in detail. Furthermore,
EdgeSec is applied in Smart Home application in the context
of several use cases.

We plan to extend our work in three perspectives. First, the
prototype of EdgeSec will be implemented by exploiting Soft-
ware Defined Network (SDN) and Virtualization technologies.
Second, a Smart Home application will be built to test and
evaluate the efficiency and effectiveness of the implemented
prototype system. Third, we will investigate next-generation
light-weight security algorithms and protocols that can be used
in our prototype to enhance the IoT security. Finally, how to
organize edge devices into a secure and efficient edge layer
will be explored.