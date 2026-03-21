## Design Decisions

1. Used vector for storing prices
   - Simple and cache efficient

2. Used streaming moving average
   - Avoid recomputation

3. Used modular .hpp/.cpp structure
   - Improves maintainability

4. Used system() for API call
   - Quick integration (can be improved with libcurl)