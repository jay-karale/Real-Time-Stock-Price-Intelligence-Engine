📈 Real-Time Stock Price Intelligence Engine (Console Based)

A console-based C++ project that simulates real-time stock price analysis using core Data Structures and Algorithms (DSA). The system now integrates live API-based price fetching, streaming analytics, and a basic order execution simulation inspired by real-world trading systems.

🚀 Project Objective

- Understand how streaming numerical data can be    analyzed efficiently

- Apply DSA concepts like heaps, vectors, sliding windows, and streaming updates

- Build a placement-oriented, modular C++ project

- Simulate basic stock market analytics at an educational level

🧠 Key Features (Updated)

🔄 Price Stream Input

- User can manually enter prices or fetch them from API

- All modules work on a shared real-time price stream

🌐 Live API Price Fetching

- Fetches stock prices using Alpha Vantage API

- Simulates real-time streaming with delay control

- Automatically appends fetched data to the system

📊 Max & Min Price Tracking

- Finds highest and lowest price from the stream

⚖️ Median Price Calculation

- Computes median of all entered prices

⏳ Sliding Window Median

- Calculates median for recent prices using a fixed window

📈 Moving Average (Dynamic)

- Uses streaming updates instead of recomputation

- Supports custom window size

- Efficient implementation using incremental updates

📉 Volatility Calculation

- Measures price variation using statistical logic

🚨 Anomaly Detection

- Detects sudden price spikes or drops beyond threshold

🏦 Order Book Simulation (Enhanced)

- Supports Buy/Sell order input

- Simulates trade execution using available price stream

- Returns execution result (success/failure, price, quantity)

- Demonstrates basic trade flow (not a real matching engine)

🛠 Data Structures & Concepts Used

- vector for price storage

- priority_queue (Min/Max Heap)

- Sliding window technique

- Streaming algorithms (incremental updates)

- Basic statistics (mean & deviation)

- Object-Oriented Programming (OOP)

- Modular design using .hpp and .cpp files

🖥 Project Type

- Console-based application

- Menu-driven interaction

- Integrated API-based simulation

- Focused on logic, DSA, and clean architecture

📌 Learning Outcomes

- Working with real-time-like data streams

- Designing multiple analytics modules on shared data

- Understanding system design at a basic fintech level

- Building modular and scalable C++ applications

- Handling API integration in C++

▶️ How to Run

Option 1: Run from Source

1. Clone the repository
   git clone <your-repo-link>

2. Navigate to project
   cd MarketPulse

3. Compile (example)
   g++ src/*.cpp -o MarketPulse

4. Run
   ./MarketPulse

Option 2: Run Prebuilt Executable

1. Go to Releases section on GitHub

2. Download:

* MarketPulse.exe
* libcurl-x64.dll

3. Run MarketPulse.exe

4. Follow menu instructions

📷 Sample Flow

* Fetch prices using API
* Store in stream
* Analyze using median / volatility / moving average
* Execute simulated buy/sell orders

🧪 Testing

Tested manually with:

* Manual input streams
* API-based real-time simulation
* Edge cases (empty input, small datasets, invalid entries)

## 📄 License
This project is licensed under a simplified MIT License.

⚠️ Disclaimer

This project is an educational simulation only. It does not provide financial advice or real trading functionality.

⭐ Feedback and suggestions are welcome

