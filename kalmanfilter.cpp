#include "kalmanfilter.h"


KalmanFilter::KalmanFilter(
  const double first_x,
  const double first_p,
  const double measurement_noise,
  const double process_noise)
  : m_measurement_noise(measurement_noise),
    m_p(first_p),
    m_process_noise(process_noise),
    m_x(first_x)
{

}

void KalmanFilter::SupplyMeasurement(const double x)
{
  /// 1/7) State prediction
  const double x_current = m_x;
  /// 2/7) Covariance prediction
  const double p_current = m_p + m_process_noise;
  /// 3/7) Innovation (y with a squiggle above it)
  const double z_measured = x; //x has noise in it
  const double innovation = z_measured - x_current;
  /// 4/7) Innovation covariance (S)
  const double innovation_covariance = p_current + m_measurement_noise;
  /// 5/7) Kalman gain (K)
  const double kalman_gain = p_current / innovation_covariance;
  /// 6/7) Update state prediction
  m_x = x_current + (kalman_gain * innovation);
  /// 7/7) Update covariance prediction
  m_p = (1.0 - kalman_gain) * p_current;

}

