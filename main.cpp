///Kalman filter example
///Adapted from merge from www.adrianboeing.com and http://greg.czerniak.info/guides/kalman1

#include <iostream>
#include <boost/shared_ptr.hpp>

#include "kalmanfilter.h"
#include "whitenoisesystem.h"

///Context:
///A constant DC voltage measured with a noisy multimeter
int main()
{
  const double x_real = 1.25; //Volts
  const double x_real_noise = 0.25; //Real measurement noise

  const double x_first_guess = 10.0; //Volts
  const double p_first_guess =  1.0; //Just a guess for the covariance
  const double measurement_noise = 0.1; //Estimated measurement noise
  const double process_noise = 0.0001; //Estimated process noise

  const WhiteNoiseSystem s(x_real,x_real_noise);

  KalmanFilter k(x_first_guess,p_first_guess,measurement_noise,process_noise);

  std::cout << "Real,measured,Kalman\n";
  for (int i=0;i!=100;++i)
  {
    //Perform a noisy measurement
    const double z_measured = s.Measure();
    //Pass this measurement to the filter
    k.SupplyMeasurement(z_measured);
    //Display what the filter predicts
    const double x_est_last = k.Predict();
    std::cout << x_real << "," << z_measured << "," << x_est_last << '\n';
  }
}
