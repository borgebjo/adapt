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

} // namespace math
} // namespace adapt
