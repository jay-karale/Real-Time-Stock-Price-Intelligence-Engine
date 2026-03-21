## System Architecture Diagram

```
                    ┌────────────────────────────┐
                    │        User (CLI)          │
                    │  Menu-driven interaction   │
                    └────────────┬───────────────┘
                                 │
                                 ▼
                    ┌────────────────────────────┐
                    │         main.cpp           │
                    │  (Controller / Orchestrator)
                    └────────────┬───────────────┘
                                 │
         ┌───────────────────────┼────────────────────────┐
         │                       │                        │
         ▼                       ▼                        ▼

┌───────────────────┐   ┌───────────────────┐   ┌───────────────────┐
│    PriceStream    │   │     APIClient     │   │       Utils       │
│ (Central Storage) │   │ (Fetch live data) │   │ (UI formatting)   │
└─────────┬─────────┘   └─────────┬─────────┘   └───────────────────┘
          │                       │
          │                       ▼
          │             External Stock API
          │          (Alpha Vantage Server)
          │
          ▼
 ┌──────────────────────────────────────────────────────────────┐
 │                     Analytics Modules                        │
 └──────────────────────────────────────────────────────────────┘
          │
          ├───────────────► MaxMinTracker
          │
          ├───────────────► MedianTracker
          │
          ├───────────────► SlidingWindowMedian
          │
          ├───────────────► MovingAverage (Streaming)
          │
          ├───────────────► VolatilityTracker
          │
          ├───────────────► AnomalyDetector
          │
          └───────────────► OrderBook (Execution Simulation)

                                 │
                                 ▼
                    ┌────────────────────────────┐
                    │        Console Output      │
                    │   (Results displayed)     │
                    └────────────────────────────┘
```

---

## Key Design Concepts

### 1. Centralized Data Flow

* PriceStream acts as the **single source of truth**
* All modules consume the same data

### 2. Modular Architecture

* Each feature is implemented in a separate class
* Improves maintainability and scalability

### 3. Streaming Data Integration

* APIClient injects real-time data into the system
* Supports incremental updates

### 4. Separation of Concerns

* Input Handling → main.cpp
* Data Storage → PriceStream
* Processing → Analytics Modules
* Output → Console

### 5. Extensibility

* New modules can be added without modifying existing ones
