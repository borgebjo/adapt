#include <numeric>
#include <stdexcept>

namespace adapt {
namespace math {

template <typename T>
double Mean(const T& container)
{
   if (container.empty())
       throw std::invalid_argument("Empty container passed to Mean.");
   auto sum = std::accumulate(begin(container), end(container),
			      typename T::value_type());
   return sum/static_cast<double>(container.size());
}

template <typename T>
double Variance(const T& container)
{
   if (container.size() < 2)
      throw std::invalid_argument("Container with size less than 2 passed "
				  "to Variance.");
   const auto mean = Mean(container);
   auto squared_sum = double(0.0);
   for (auto value: container)
   {
      squared_sum += (value-mean)*(value-mean);
   }
   return squared_sum/(static_cast<double>(container.size()) - 1);
}


/// Computes the sample covariance between the stocastic x variables
/// and the stocastic y variables given in the \c x_values and \c
/// y_values containter respectively.
template <typename T, typename U>
double Covariance(const T& x_values, const U& y_values)
{
   if (x_values.size() != y_values.size())
      throw std::invalid_argument("x_values and y_values passed to Covariance has different sizes.");
   if (x_values.size() < 2)
      throw std::invalid_argument("Arguments with size less than 2 passed to Covariance.");

   auto x_mean = Mean(x_values);
   auto y_mean = Mean(y_values);
   auto inner_product = double(0.0);
   for (unsigned int i = 0; i < x_values.size(); ++i)
   {
      inner_product += (x_values[i]-x_mean)*(y_values[i]-y_mean);
   }
   return inner_product/(static_cast<double>(x_values.size())-1);
}

} // namespace math
} // namespace adapt
