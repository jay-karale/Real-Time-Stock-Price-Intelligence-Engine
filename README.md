📈 Real-Time Stock Price Intelligence Engine (Console Based)

- A console-based C++ project that simulates real-time stock price analysis using core Data Structures and Algorithms (DSA). The project processes a single price stream and derives multiple analytical insights similar to basic financial systems.

🚀 Project Objective

- Understand how streaming numerical data can be analyzed efficiently

- Apply DSA concepts like heap, vectors and sliding windows

- Build a placement-oriented, menu-driven C++ project

- Simulate basic stock market analytics at an educational level

🧠 Key Features (Implemented)

🔄 Price Stream Input

- User enters prices manually once

- All modules work on the same stored price stream

🌐 Real-Time Price Fetching (API Integration)

- Fetch real-time stock prices using an external financial API

- User can specify how many price values to fetch

- Prices are fetched sequentially with a small delay to simulate a live market feed

- Small controlled variation is applied to mimic real-time market tick movement

- Fetched prices automatically get added to the same price stream used by all analytics modules

📊 Max & Min Price Tracking

- Finds highest and lowest price from the stream

⚖️ Median Price Calculation

- Computes median of all entered prices

⏳ Sliding Window Median

- Calculates median for recent prices using a fixed window

📈 Moving Average

- Computes average price to understand overall trend

📉 Volatility Calculation

- Measures price variation using simple statistical logic

🚨 Anomaly Detection

- Detects sudden price changes beyond a threshold

🏦 Order Book Simulation (Basic)

- Console-based buy/sell order simulation

- Demonstrates how trades are conceptually executed

- No real trading or matching engine involved

🛠 Data Structures & Concepts Used

- vector for price storage

- priority_queue (Min/Max Heap)

- Sorting-based median logic

- Sliding window technique

- Basic statistics (mean & deviation)

- API data fetching using system calls

- Randomized variation to simulate market tick movement

- Modular design using .hpp and .cpp files

- Object-Oriented Programming (OOP)

🖥 Project Type

- Console-based application

- Menu-driven user interaction

- Real-time price fetching via API

- Focused on logic, DSA, and clean modular design

📌 Learning Outcomes

- How multiple analytics modules can work on a single data source

- Integrating external APIs with C++

- Applying DSA concepts to real-life inspired problems

- Writing modular, maintainable C++ code

- Building confidence for technical interviews

- Understanding how real-time financial data streams can be processed

▶️ How to Run

- Clone the repository

- Compile using a C++17 compatible compiler

- Run the executable

- Use the menu to either:

-> Add manual price streams

-> Fetch real-time prices from API

-> Run analytics on the collected data

⚠️ Disclaimer

- This project is an educational simulation only. It does not provide financial advice or real trading functionality.

⭐ Feedback and suggestions are welcome.
