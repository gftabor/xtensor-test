#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

int main(int argc, char* argv[])
{


    xt::xarray<double> array = xt::eval(xt::zeros<double>({2,2}));


    auto res_incorrect = xt::eval(xt::cos(array));

    std::cout << res_incorrect << std::endl;


    xt::xarray<double> small_array = xt::eval(xt::zeros<double>({2}));


    auto res_correct = xt::eval(xt::cos(small_array));

    std::cout << res_correct << std::endl;

    return 0;
}