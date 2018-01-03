#ifndef KALMANFILTER_H
#define KALMANFILTER_H

struct KalmanFilter
{
  ///Initialize the filter with a first measurent
  KalmanFilter(
    const double first_x,
    const double first_p,
    const double measurement_noise,
    const double process_noise
    );

  ///Give the filter a real measurement, so it will update itself
  void SupplyMeasurement(const double x);

  ///Let the filter predict
  double Predict() const { return m_x; }

  ///Let the filter predict
  double PredictCovariance() const { return m_p; }

  private:

  //R: Estimated measurement noise: How to estimate this?
  const double m_measurement_noise;

  ///The (current prediction of the) covariance
  double m_p;

  //Q: Process noise: How to estimate this?
  const double m_process_noise;

  ///The (current prediction of the) measurement
  double m_x;

};

#endif // KALMANFILTER_H
