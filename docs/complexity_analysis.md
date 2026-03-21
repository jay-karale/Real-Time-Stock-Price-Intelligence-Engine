## Time Complexity Analysis

### Price Stream

* Add Price: **O(1)**
* Get Prices: **O(n)** (copying vector)


### Max & Min Tracker

* Time Complexity: **O(n)**
* Reason: Traverse entire price list once


### Median Tracker

* Time Complexity: **O(n log n)**
* Reason: Sorting required before finding median


### Sliding Window Median

* Time Complexity: **O(n log k)**

* Where k = window size

* Reason:

  * Each window requires insertion/removal in sorted structure



### Moving Average (Streaming)

* Time Complexity: **O(1) per update**
* Reason:

  * Uses incremental update (add new, remove old)



### Volatility Tracker

* Time Complexity: **O(n)**
* Reason:

  * Single pass to compute mean and variance


### Anomaly Detector

* Time Complexity: **O(n)**

* Reason:

  * Traverses price list once
  * Compares consecutive or threshold-based differences

* Example Logic:

  * |current_price - previous_price| > threshold


### Order Book Simulation

* Time Complexity: **O(n)**

* Reason:

  * Iterates through price stream to simulate execution
  * Finds suitable price(s) for buy/sell

* Note:

  * Current implementation is simplified
  * No priority queues or matching engine used


## Space Complexity

* Price Storage: **O(n)**
* Additional Structures:

  * Moving Average Window: **O(k)**
  * Sliding Window Median: **O(k)**


## Overall System Efficiency

* Optimized for streaming operations
* Most operations run in linear time or better
* Moving Average is optimized to constant time updates
