#include "whitenoisesystem.h"

#include <boost/random/normal_distribution.hpp>
#include <boost/random/lagged_fibonacci.hpp>

WhiteNoiseSystem::WhiteNoiseSystem(const double real_value, const double stddev)
  : m_mean(real_value),
    m_stddev(stddev)
{

}

double WhiteNoiseSystem::GetRandomNormal(const double mean, const double sigma)
{
  boost::normal_distribution<double> norm_dist(mean, sigma);
  static boost::lagged_fibonacci19937 engine;
  const double value = norm_dist.operator () <boost::lagged_fibonacci19937>((engine));
  return value;
}

double WhiteNoiseSystem::Measure() const
{
  return GetRandomNormal(m_mean,m_stddev);
}

