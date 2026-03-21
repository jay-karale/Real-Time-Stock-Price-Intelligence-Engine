## API Integration

The system uses Alpha Vantage API to fetch stock prices.

Endpoint:
https://www.alphavantage.co/query

Function:
GLOBAL_QUOTE

Example Response:
{
  "05. price": "182.21"
}

Parsing Strategy:
- Extract price using string matching
- Convert to double