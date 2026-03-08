@echo off
cd src
echo Compiling...
g++ -o main main.cpp PriceStream.cpp MaxMinTracker.cpp MedianTracker.cpp SlidingWindowMedian.cpp MovingAverage.cpp VolatilityTracker.cpp AnomalyDetector.cpp OrderBook.cpp Utlis.cpp
if errorlevel 1 (
    echo Compilation failed!
    pause
    exit /b 1
)
echo Compilation successful! Running...
echo.
.\main.exe
pause
