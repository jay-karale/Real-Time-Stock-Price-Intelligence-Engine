#ifndef ANOMALY_DETECTOR_HPP
#define ANOMALY_DETECTOR_HPP

#include <vector>

class AnomalyDetector {
public:
    void detect(const std::vector<double>& prices) const;
};

#endif
